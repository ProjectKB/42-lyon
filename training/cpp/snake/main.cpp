/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.cpp                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/30 17:57:08 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/01 22:41:01 by loiberti    ###    #+. /#+    ###.fr     */
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
	WINDOW	*win;
	int		key;

	int		h_max;
	int		w_max;
	int		pieces;
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
		getmaxyx(stdscr, h_max, w_max);
		win = newwin(h_max, w_max, 0, 0);
		pieces = 3;
		pos.push_back({h_max / 2, w_max / 2});
		pos.push_back({h_max / 2 - 1, w_max / 2});
		pos.push_back({h_max / 2 - 2, w_max / 2});
	}
};

bool prohibit_turning_back(int &o_key, int &n_key)
{
	if (o_key == KEY_UP && n_key == KEY_DOWN)
		return (0);
	else if (n_key == KEY_UP && o_key == KEY_DOWN)
		return (0);
	else if (n_key == KEY_LEFT && o_key == KEY_RIGHT)
		return (0);
	else if (o_key == KEY_LEFT && n_key == KEY_RIGHT)
		return (0);
	else if (n_key != KEY_UP && n_key != KEY_DOWN && n_key != KEY_LEFT && n_key != KEY_RIGHT)
		return (0);
	return (1);
}

void	manage_direction(var &v)
{
	int	tmp_key;

	if ((tmp_key = getch()) != ERR && prohibit_turning_back(v.key, tmp_key))
		v.key = tmp_key;
	v.pos.push_front(v.pos[0]);
	switch (v.key)
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
	if (v.pos[0][1] == v.w_max - 1)
		v.pos[0][1] = 2;
	else if (v.pos[0][1] == 1)
		v.pos[0][1] = v.w_max - 2;
	else if (v.pos[0][0] == 1)
		v.pos[0][0] = v.h_max - 2;
	else if (v.pos[0][0] == v.h_max - 1)
		v.pos[0][0] = 2;
}

void	add_piece(var &v)
{
	switch (v.key)
	{
		case KEY_UP:
			v.pos.push_back({v.pos[v.pieces - 1][0] - 1, v.pos[v.pieces - 1][1]});
			break;
		case KEY_DOWN:
			v.pos.push_back({v.pos[v.pieces - 1][0] + 1, v.pos[v.pieces - 1][1]});
			break;
		case KEY_LEFT:
			v.pos.push_back({v.pos[v.pieces - 1][0], v.pos[v.pieces - 1][1] - 1});
			break;
		case KEY_RIGHT:
			v.pos.push_back({v.pos[v.pieces - 1][0], v.pos[v.pieces - 1][1] + 1});
			break;
	}
	++v.pieces;
}

void	display_pieces_data(var &v)
{
	for (int i(0); i < v.pieces; i++)
		cout << "h: " << v.pos[i][0] << " | w: " << v.pos[i][1] << "\n";
}

void	display_pieces(var &v)
{
	for (int i(0); i < v.pieces - 1; ++i)
		mvwaddch(v.win, v.pos[i][0], v.pos[i][1], ACS_CKBOARD);
}

void	erase_piece(var &v)
{
	mvwaddch(v.win, v.pos[v.pieces - 1][0], v.pos[v.pieces - 1][1], ' ');
}

bool	check_goal_pos(vector<int> &goal, var &v)
{
	for (int i(0); i < v.pieces; ++i)
		if (goal[0] == v.pos[i][0] || goal[1] == v.pos[i][1])
			return (0);
	return (1);
}

void	generate_goal(vector<int> &goal, var &v)
{
	while (42)
	{
		goal[0] = rand() % (v.h_max - 10) + 5;
		goal[1] = rand() % (v.w_max - 10) + 5;
		if (check_goal_pos(goal, v))
			break;
	}
}

void	new_goal(vector<int> &goal, var &v)
{
	if (v.pos[0][0] == goal[0] && v.pos[0][1] == goal[1])
	{
		generate_goal(goal, v);
		add_piece(v);
		mvwaddch(v.win, goal[0], goal[1], 'o');
	}
	else
		mvwaddch(v.win, goal[0], goal[1], 'o');
}

int main()
{
	var	v;
	vector<int>	goal{-1, -1};

	v.init_screen();
	v.init_var();
	srand(time(0));
	generate_goal(goal, v);
	while (1)
	{
		erase_piece(v);
		new_goal(goal, v);
		manage_direction(v);
		manage_border(v);
		display_pieces(v);
		(v.key == KEY_UP || v.key == KEY_DOWN) ? usleep(80000) : usleep(40000);
		wrefresh(v.win);
	}
	endwin();
	return (0);
}
