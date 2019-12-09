/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test.cpp                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/02 14:30:38 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/09 17:48:37 by loiberti    ###    #+. /#+    ###.fr     */
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

void	init_game(Window &win, vector<Snake> &snakes)
{
	int	nb_p;

	cout << "How many players are you ? ";
	cin >> nb_p;
	win.set_screen();
	if (nb_p >= 1)
		snakes.push_back({win, {U1, D1, L1, R1, 1}});
	if (nb_p >= 2)
		snakes.push_back({win, {U2, D2, L2, R2, 2}});
	if (nb_p >= 3)
		snakes.push_back({win, {U3, D3, L3, R3, 3}});
	if (nb_p == 4)
		snakes.push_back({win, {U4, D4, L4, R4, 4}});
}

void	process_game(vector<Snake> &snakes, vector<int> &tab_key)
{
	manage_key(snakes, tab_key);
	destroy_opponent(snakes);
	for (int i(0); i < Snake::nb_player; ++i)
		snakes[i].process();
}

int	main(void)
{
	Window	win;
	vector<int>	tab_key(2, ERR);
	vector<Snake>	snakes;

	srand(time(0));
	init_game(win, snakes);
	generate_goal(Snake::goal, win);
	while (42)
	{
		process_game(snakes, tab_key);
		wrefresh(win.get_win());
	}
	endwin();
	return (0);
}
