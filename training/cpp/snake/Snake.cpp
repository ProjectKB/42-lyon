/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   snake.cpp                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/02 13:25:52 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/05 20:57:59 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "Snake.hpp"

vector<int>	Snake::goal = {-1, -1};
int			Snake::nb_player = 0;

Snake::Snake(Window &win, str name, int u, int d, int l, int r, int c) : m_win(&win), m_name(name)
{
	int	rand_h;
	int	rand_w;

	m_u = u;
	m_d = d;
	m_l = l;
	m_r = r;
	m_c = c;
	m_piece = 3;
	m_time = 40000;
	++Snake::nb_player;
	rand_h = rand() % (win.get_hmax() - 10) + 5;
	rand_w = rand() % (win.get_wmax() - 10) + 5;
	m_pos.push_back({rand_h, rand_w});
	m_pos.push_back({rand_h - 1, rand_w});
	m_pos.push_back({rand_h - 2, rand_w});
}

Snake::Snake(const Snake &other)
{
	*this = other;
}

Snake::~Snake(void) {}

void	Snake::erase_last_piece(void) const
{
	mvwaddch(m_win->get_win(), m_pos[m_piece - 1][0], m_pos[m_piece - 1][1], ' ');
}

bool	Snake::prohibit_turning_back(int &o_key, int &n_key) const
{
	if (o_key == m_u && n_key == m_d)
		return (0);
	else if (n_key == m_u && o_key == m_d)
		return (0);
	else if (n_key == m_l && o_key == m_r)
		return (0);
	else if (o_key == m_l && n_key == m_r)
		return (0);
	else if (n_key != m_u && n_key != m_d && n_key != m_l && n_key != m_r)
		return (0);
	return (1);
}

void	Snake::set_key(int tmp_key)
{
	if (prohibit_turning_back(m_key, tmp_key))
		m_key = tmp_key;
}

void	Snake::manage_direction(void)
{
	m_pos.push_front(m_pos[0]);
	if (m_key == m_u)
		--m_pos[0][0];
	else if (m_key == m_d)
			++m_pos[0][0];
	else if (m_key == m_l)
			--m_pos[0][1];
	else if (m_key == m_r)
			++m_pos[0][1];
	m_pos.pop_back();
}

void	Snake::manage_border()
{
	if (m_pos[0][1] == m_win->get_wmax() - 1)
		m_pos[0][1] = 2;
	else if (m_pos[0][1] == 1)
		m_pos[0][1] = m_win->get_wmax() - 2;
	else if (m_pos[0][0] == 1)
		m_pos[0][0] = m_win->get_hmax() - 2;
	else if (m_pos[0][0] == m_win->get_hmax() - 1)
		m_pos[0][0] = 2;
}

void	Snake::display_pieces() const
{
	mvwaddch(m_win->get_win(), m_pos[0][0], m_pos[0][1], ACS_CKBOARD | COLOR_PAIR(m_c));
}

void	Snake::manage_speed(void) const
{
	(m_key == m_u || m_key == m_d) ? usleep(m_time * 2) : usleep(m_time);
}

void	Snake::add_piece(void)
{
	if (m_key == m_u)
		m_pos.push_back({m_pos[m_piece - 1][0] - 1, m_pos[m_piece - 1][1]});
	else if (m_key == m_d)
		m_pos.push_back({m_pos[m_piece - 1][0] + 1, m_pos[m_piece - 1][1]});
	else if (m_key == m_l)
		m_pos.push_back({m_pos[m_piece - 1][0], m_pos[m_piece - 1][1] - 1});
	else if (m_key == m_r)
		m_pos.push_back({m_pos[m_piece - 1][0], m_pos[m_piece - 1][1] + 1});
	++m_piece;
}

void	Snake::process(void)
{
	erase_last_piece();
	manage_goal();
	manage_direction();
	manage_border();
	display_pieces();
	manage_speed();
}

bool    Snake::check_goal_pos(void)
{
	for (int i(0); i < m_piece; ++i)
		if (Snake::goal[0] == m_pos[i][0] || goal[1] == m_pos[i][1])
			return (0);
	return (1);
}

void	generate_goal(vector<int> &goal, Window &win)
{
	goal[0] = rand() % (win.get_hmax() - 10) + 5;
	goal[1] = rand() % (win.get_wmax() - 10) + 5;
}


void	Snake::manage_goal()
{
	if (m_pos[0][0] == Snake::goal[0] && m_pos[0][1] == Snake::goal[1])
	{
		mvwaddch(m_win->get_win(), Snake::goal[0], Snake::goal[1], ACS_CKBOARD | COLOR_PAIR(5));
		while (!(check_goal_pos()))
			generate_goal(Snake::goal, *m_win);
		m_time /= 2;
		add_piece();
	}
	mvwaddch(m_win->get_win(), Snake::goal[0], Snake::goal[1], 'x' | COLOR_PAIR(5));
}

int		Snake::get_u(void) const
{
	return (m_u);
}

int		Snake::get_d(void) const
{
	return (m_d);
}

int		Snake::get_l(void) const
{
	return (m_l);
}

int		Snake::get_r(void) const
{
	return (m_r);
}

deque<vector<int>>	Snake::get_pos(void) const
{
	return (m_pos);
}

vector<int>	Snake::get_pos_head(void) const
{
	return (m_pos[0]);
}

int		Snake::get_piece(void) const
{
	return (m_piece);
}

int		Snake::get_nb(void) const
{
	return (m_c);
}

bool	Snake::check_pos(Snake &target) const
{
	deque<vector<int>> t;

	t = target.get_pos();
	for (int i(target.get_piece() - 1); i > 2; --i)
	{
		if (m_pos[0][0] == t[i][0] && m_pos[0][1] == t[i][1])
			return (1);
		else if (m_pos[1][0] == t[i][0] && m_pos[1][1] == t[i][1])
			return (1);
		else if (m_pos[2][0] == t[i][0] && m_pos[2][1] == t[i][1])
			return (1);
	}
	return (0);
}

void	Snake::destroy_pieces(vector<int> to_destroy)
{
	for (int i(m_piece - 1); i > 2; --i)
	{
		mvwaddch(m_win->get_win(), m_pos[i][0], m_pos[i][1], ' ');
		m_pos.pop_back();
		--m_piece;
		if (m_pos[i][0] == to_destroy[0] && m_pos[i][1] == to_destroy[1])
			return;
	}
}

void	destroy_opponent(vector<Snake> &snakes)
{
	vector<int> pos;

	for (int j(0); j < Snake::nb_player; ++j)
		for (int i(0); i < Snake::nb_player; ++i)
			if (j != i && snakes[j].check_pos(snakes[i]))
			{
				pos = snakes[j].get_pos_head();
				snakes[i].destroy_pieces(pos);
			}
}
