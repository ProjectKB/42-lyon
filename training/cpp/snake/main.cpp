/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.cpp                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/30 17:57:08 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/30 22:39:18 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <iostream>
#include <curses.h>
#include <unistd.h>

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
		wt = w / 2;
	}
};

void	manage_direction(var &v)
{
	if ((v.ch = getch()) != ERR)
		v.tmp = v.ch;
	switch (v.tmp)
	{
		case KEY_UP:
			--v.ht;
			break;
		case KEY_DOWN:
			++v.ht;
			break;
		case KEY_LEFT:
			--v.wt;
			break;
		case KEY_RIGHT:
			++v.wt;
			break;
	}
}

void	manage_border(var &v)
{
	if (v.wt == v.w && v.tmp == KEY_RIGHT)
		v.wt = 0;
	else if (!v.wt && v.tmp == KEY_LEFT)
		v.wt = v.w;
	else if (!v.ht && v.tmp == KEY_UP)
		v.ht = v.h;
	else if (v.ht == v.h && v.tmp == KEY_DOWN)
		v.ht = 0;
}

int main()
{
	var	v;

	v.init_screen();
	v.init_var();
	while (1)
	{
		mvwaddch(v.win, v.ht, v.wt, ' ');
		manage_direction(v);
		manage_border(v);
		mvwaddch(v.win, v.ht, v.wt, ACS_CKBOARD);
		(v.tmp == KEY_UP || v.tmp == KEY_DOWN) ? usleep(80000) : usleep(40000);
		wrefresh(v.win);
	}
	endwin();
	return (0);
}
