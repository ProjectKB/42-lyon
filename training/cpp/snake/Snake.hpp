/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   players.hpp                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/02 12:48:49 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/02 22:23:27 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef PLAYERS_HPP

# define PLAYERS_HPP

# include <iostream>
# include <curses.h>
# include <unistd.h>
# include <vector>
# include <deque>
# include "Window.hpp"

# define KUP 119

using namespace std;
typedef string str;

class Snake
{
	public:
		Snake(Window &win, str name);
		Snake(Snake const &to_copy);
		~Snake(void);

		bool	prohibit_turning_back(int &o_key, int &n_key) const;
		void	manage_direction(void);
		void	manage_border(void);
		void	manage_speed(void) const;
		void	add_piece(void);
		void	display_pieces(void) const;
		void	erase_last_piece(void) const;
		void	process(void);

		bool	check_goal_pos(void);
		void	manage_goal(void);

		static vector<int>	goal;
		static int			nb_player;

	private:
		Window				*m_win;
		int					m_piece;
		int					m_key;
		int					m_time;
		str					m_name;
		deque<vector<int>>	m_pos;
		int					m_up;

		void	init_var();
};

void	generate_goal(vector<int> &goal, Window &win);

#endif
