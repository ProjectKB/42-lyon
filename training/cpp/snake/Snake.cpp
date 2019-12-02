/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   snake.cpp                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/02 13:25:52 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/02 14:53:56 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "Snake.hpp"

Snake::Snake(Window &win, str name) : m_win(&win), m_name(name)
{
	m_piece = 3;
	m_key = ERR;
	m_pos.push_back({m_win->get_hmax() / 2, m_win->get_wmax() / 2});
	m_pos.push_back({m_win->get_hmax() / 2 - 1, m_win->get_wmax() / 2});
	m_pos.push_back({m_win->get_hmax() / 2 - 2, m_win->get_wmax() / 2});
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
	switch (m_key)
	{
		case KEY_UP:
			--m_pos[0][0];
			break;
		case KEY_DOWN:
			++m_pos[0][0];
			break;
		case KEY_LEFT:
			--m_pos[0][1];
			break;
		case KEY_RIGHT:
			++m_pos[0][1];
			break;
	}
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

void	Snake::display_pieces() const // nani ?
{
	mvwaddch(m_win->get_win(), m_pos[0][0], m_pos[0][1], ACS_CKBOARD);
}
