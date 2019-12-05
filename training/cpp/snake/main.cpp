/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test.cpp                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/02 14:30:38 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/05 17:51:00 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "Window.hpp"
#include "Snake.hpp"
#include <algorithm>

void	manage_key(vector<Snake> &snakes, vector<int> &tab_key)
{
	for (int i(0); i < Snake::nb_player; ++i)
		tab_key[i] = getch();
	for (size_t k(0); k < tab_key.size(); ++k)
		for (int j(0); j < Snake::nb_player; ++j)
		{
			if (tab_key[k] != ERR)
			{
				if (tab_key[k] == snakes[j].get_u())
					snakes[j].set_key(tab_key[k]);
				else if (tab_key[k] == snakes[j].get_d())
					snakes[j].set_key(tab_key[k]);
				else if (tab_key[k] == snakes[j].get_l())
					snakes[j].set_key(tab_key[k]);
				else if (tab_key[k] == snakes[j].get_r())
					snakes[j].set_key(tab_key[k]);
			}
		}
}

void	init_game(Window &win, vector<Snake> &snakes)
{
	int	nb_p;

	cout << "How many players are you ? ";
	cin >> nb_p;
	cout << nb_p;
	win.set_screen();
	if (nb_p >= 1)
		snakes.push_back({win, "Player 1", KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT, 1});
	if (nb_p >= 2)
		snakes.push_back({win, "Player 2", 119, 115, 97, 100, 2});
	if (nb_p >= 3)
		snakes.push_back({win, "Player 3", 105, 107, 106, 108, 3});
	if (nb_p == 4)
		snakes.push_back({win, "Player 4", 53, 50, 49, 51, 4});
}

void	init_colors(void)
{
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_CYAN, COLOR_BLACK);
	init_pair(5, COLOR_WHITE, COLOR_BLACK);
}

int		main(void)
{
	Window	win;
	vector<int>	tab_key(2, ERR);
	vector<Snake>	snakes;

	srand(time(0));
	init_game(win, snakes);
	init_colors();
	generate_goal(Snake::goal, win);
	while (42)
	{
		manage_key(snakes, tab_key);
		destroy_opponent(snakes);
		for (int i(0); i < Snake::nb_player; ++i)
			snakes[i].process();
		wrefresh(win.get_win());
	}
	endwin();
	return (0);
}
