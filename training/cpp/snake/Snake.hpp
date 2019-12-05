/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   players.hpp                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/02 12:48:49 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/04 06:31:48 by loiberti    ###    #+. /#+    ###.fr     */
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

struct Dir
{
	int	up;
	int	down;
	int	left;
	int	right;
};

class Snake
{
	public:
		Snake(Window &win, str name, int u, int d, int l, int r, int c);
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
		void	destroy_pieces(vector<int> to_destroy);

		bool	check_goal_pos(void);
		void	manage_goal(void);
		bool	check_pos(Snake &target) const;
		void	set_key(int tmp_key);
		int		get_u(void) const;
		int		get_d(void) const;
		int		get_l(void) const;
		int		get_r(void) const;
		int		get_piece(void) const;
		int		get_nb(void) const;
		deque<vector<int>>	get_pos(void) const;
		vector<int>	get_pos_head(void) const;

		static vector<int>	goal;
		static int			nb_player;

	private:
		Window				*m_win;
		int					m_piece;
		int					m_key;
		int					m_time;
		str					m_name;
		deque<vector<int>>	m_pos;

		int					m_u;
		int					m_d;
		int					m_l;
		int					m_r;
		int					m_c;

		void	init_var();
};

void	generate_goal(vector<int> &goal, Window &win);
void	destroy_opponent(vector<Snake> &snakes);

#endif
