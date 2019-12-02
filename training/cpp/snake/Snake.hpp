/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   players.hpp                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/02 12:48:49 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/02 14:37:14 by loiberti    ###    #+. /#+    ###.fr     */
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

using namespace std;
typedef string str;

class Snake
{
	public:
		Snake(Window &win, str name = "Unknow");
		Snake(Snake const &to_copy);
		~Snake(void);

		bool	prohibit_turning_back(int &o_key, int &n_key) const;
		void	manage_direction();
		void	manage_border();
		void	add_piece();
		void	display_pieces() const;
		void	erase_last_piece() const;

		static bool	check_goal_pos();
		static void	generate_goal();
		static void	manage_goal();

	private:
		Window				*m_win;
		int					m_piece;
		int					m_key;
		str					m_name;
		deque<vector<int>>	m_pos;

		static vector<int>	goal;

		void	init_var();
};

#endif
