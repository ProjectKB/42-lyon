/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.cpp                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/30 17:57:08 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/01 21:14:03 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <iostream>
#include <curses.h>
#include <unistd.h>
#include <vector>
#include <deque>

using namespace std;
typedef string str;

struct var
{
	WINDOW *win;
	int		ch;

	int		h;
	int		w;
	int		ht;
	int		wt;
	int		tmp;
	int		piece;
	deque<vector<int>>	pos;

	void	init_screen()
	{
		initscr();
		keypad(stdscr, TRUE);
		cbreak();
		noecho();
		nodelay(stdscr, TRUE);
		curs_set(0);
		nodelay(stdscr, TRUE);
	}

	void	init_var()
	{
		getmaxyx(stdscr, h, w);
		win = newwin(h, w, 0, 0);
		ht = h / 2;
		piece = 1;
		wt = w / 2;
		pos.push_back({h / 2, w / 2});
	}
};

void	manage_direction(var &v)
{
	int	l_key;

	l_key = v.tmp;
	if ((v.ch = getch()) != ERR)
		v.tmp = v.ch;
	v.pos.push_front(v.pos[0]);
	switch (v.tmp)
	{
		case KEY_UP:
			--v.pos[0][0];
			break;
		case KEY_DOWN:
			++v.pos[0][0];
			break;
		case KEY_LEFT:
			--v.pos[0][1];
			break;
		case KEY_RIGHT:
			++v.pos[0][1];
			break;
	}
	v.pos.pop_back();
}



void	manage_border(var &v)
{
	if (v.pos[0][1] == v.w - 1)
		v.pos[0][1] = 2;
	else if (v.pos[0][1] == 1)
		v.pos[0][1] = v.w - 2;
	else if (v.pos[0][0] == 1)
		v.pos[0][0] = v.h - 2;
	else if (v.pos[0][0] == v.h - 1)
		v.pos[0][0] = 2;
}

void	add_piece(var &v)
{
	switch (v.tmp)
	{
		case KEY_UP:
			v.pos.push_back({v.pos[v.piece - 1][0] - 1, v.pos[v.piece - 1][1]});
			break;
		case KEY_DOWN:
			v.pos.push_back({v.pos[v.piece - 1][0] + 1, v.pos[v.piece - 1][1]});
			break;
		case KEY_LEFT:
			v.pos.push_back({v.pos[v.piece - 1][0], v.pos[v.piece - 1][1] - 1});
			break;
		case KEY_RIGHT:
			++v.pos[0][1];
			v.pos.push_back({v.pos[v.piece - 1][0], v.pos[v.piece - 1][1] + 1});
			break;
	}
	v.piece++;
}

void	display_pieces(var &v)
{
	for (int i(0); i < v.piece; i++)
		cout << "h: " << v.pos[i][0] << " | w: " << v.pos[i][1] << "\n";
}

void	erase_piece(var &v)
{
		mvwaddch(v.win, v.pos[v.piece - 1][0], v.pos[v.piece - 1][1], ' ');
}

int main()
{
	var	v;

	v.init_screen();
	v.init_var();
	v.tmp = KEY_UP;
	add_piece(v);
	add_piece(v);
	//display_pieces(v);
	while (1)
	{
		erase_piece(v);
		manage_direction(v);
		manage_border(v);
		mvwaddch(v.win, v.pos[0][0], v.pos[0][1], ACS_CKBOARD);
		mvwaddch(v.win, v.pos[1][0], v.pos[1][1], ACS_CKBOARD);
		mvwaddch(v.win, v.pos[2][0], v.pos[2][1], ACS_CKBOARD);
		(v.tmp == KEY_UP || v.tmp == KEY_DOWN) ? usleep(80000) : usleep(40000);
		wrefresh(v.win);
	}
	endwin();
	return (0);
}
