/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   players.hpp                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/02 12:48:49 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/09 17:46:33 by loiberti    ###    #+. /#+    ###.fr     */
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

# define U1 KEY_UP
# define D1 KEY_DOWN
# define L1 KEY_LEFT
# define R1 KEY_RIGHT

# define U2 119
# define D2 115
# define L2 97
# define R2 100

# define U3 105
# define D3 107
# define L3 106
# define R3 108

# define U4 53
# define D4 50
# define L4 49
# define R4 51

using namespace std;

typedef string str;

struct Dir
{
	int	u;
	int	d;
	int	l;
	int	r;
	int	nb;
};

class Snake
{
	public:
		Snake(Window &win, Dir d);
		Snake(Snake const &to_copy);
		~Snake(void);

		void	process(void);
		void	destroy_pieces(vector<int> to_destroy);
		bool	check_pos(Snake &target) const;
		void	set_key(int tmp_key);

		// getter
		int	get_u(void) const;
		int	get_d(void) const;
		int	get_l(void) const;
		int	get_r(void) const;
		int	get_piece(void) const;
		int	get_nb(void) const;
		deque<vector<int> >	get_pos(void) const;
		vector<int>	get_pos_head(void) const;

		static vector<int>	goal;
		static int	nb_player;
		static int	m_time;

	private:
		Window	*m_win;
		int	m_piece;
		int	m_key;
		deque<vector<int> >	m_pos;
		Dir	m_d;

		// process subfunctions
		void	erase_last_piece(void) const;
		void	manage_goal(void);
		bool	check_goal_pos(void) const;
		void	add_piece(void);
		void	manage_direction(void);
		void	manage_border(void);
		void	display_pieces(void) const;
		void	manage_speed(void) const;

		bool	prohibit_turning_back(int &o_key, int &n_key) const;

};

void	generate_goal(vector<int> &goal, Window &win);
void	destroy_opponent(vector<Snake> &snakes);

#endif
