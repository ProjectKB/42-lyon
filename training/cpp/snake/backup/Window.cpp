/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   Window.cpp                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/02 13:48:35 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/02 20:05:57 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "Window.hpp"

Window::Window(void)
{
	init_screen();
	init_var();
}

Window::Window(const Window &to_copy)
{
	*this = to_copy;
}

Window::~Window(void) {}

void	Window::init_screen(void)
{
	initscr();
	keypad(stdscr, TRUE);
	cbreak();
	noecho();
	nodelay(stdscr, TRUE);
	curs_set(0);
}

void	Window::init_var(void)
{
	getmaxyx(stdscr, m_hmax, m_wmax);
	m_win = newwin(m_hmax, m_wmax, 0, 0);
}

int		Window::get_hmax()
{
	return (m_hmax);
}

int		Window::get_wmax()
{
	return (m_wmax);
}

WINDOW*	Window::get_win()
{
	return (m_win);
}
