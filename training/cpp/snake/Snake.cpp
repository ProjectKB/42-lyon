/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   snake.cpp                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/02 13:25:52 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/02 22:26:33 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "Snake.hpp"

vector<int>	Snake::goal = {-1, -1};
int			Snake::nb_player = 0;

Snake::Snake(Window &win, str name) : m_win(&win), m_name(name)
{
	m_piece = 3;
	m_time = 40000;
	++Snake::nb_player;
	m_pos.push_back({m_win->get_hmax() / (2 + Snake::nb_player), m_win->get_wmax() / 2});
	m_pos.push_back({m_win->get_hmax() / (2 + Snake::nb_player) - 1, m_win->get_wmax() / 2});
	m_pos.push_back({m_win->get_hmax() / (2 + Snake::nb_player) - 2, m_win->get_wmax() / 2});
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

void	Snake::manage_direction(void)
{
	int	tmp_key;

	if ((tmp_key = getch()) != ERR && prohibit_turning_back(m_key, tmp_key))
		m_key = tmp_key;
	m_pos.push_front(m_pos[0]);
	if (m_key == KEY_UP)
		--m_pos[0][0];
	else if (m_key == KEY_DOWN)
			++m_pos[0][0];
	else if (m_key == KEY_LEFT)
			--m_pos[0][1];
	else if (m_key == KEY_RIGHT)
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
	mvwaddch(m_win->get_win(), m_pos[0][0], m_pos[0][1], ACS_CKBOARD);
}

void	Snake::manage_speed(void) const
{
	(m_key == KEY_UP || m_key == KEY_DOWN) ? usleep(m_time * 2) : usleep(m_time);
}

void	Snake::add_piece(void)
{
	switch (m_key)
	{
		case KEY_UP:
			m_pos.push_back({m_pos[m_piece - 1][0] - 1, m_pos[m_piece - 1][1]});
			break;
		case KEY_DOWN:
			m_pos.push_back({m_pos[m_piece - 1][0] + 1, m_pos[m_piece - 1][1]});
			break;
		case KEY_LEFT:
			m_pos.push_back({m_pos[m_piece - 1][0], m_pos[m_piece - 1][1] - 1});
			break;
		case KEY_RIGHT:
			m_pos.push_back({m_pos[m_piece - 1][0], m_pos[m_piece - 1][1] + 1});
			break;
	}
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


void    Snake::manage_goal()
{
	if (m_pos[0][0] == Snake::goal[0] && m_pos[0][1] == Snake::goal[1])
	{
		while (!(check_goal_pos()))
			generate_goal(Snake::goal, *m_win);;
		add_piece();
	}
	mvwaddch(m_win->get_win(), Snake::goal[0], Snake::goal[1], 'o');
}
