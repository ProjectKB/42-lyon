/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   Window.cpp                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/02 13:48:35 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/06 03:54:54 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "Window.hpp"

Window::Window(void){}

Window::Window(const Window &to_copy)
{
	*this = to_copy;
}

Window::~Window(void) {}



/*
** SET SCREEN ******************************************************************
*/

void	Window::set_screen(void)
{
	init_screen();
	init_var();
	init_colors();
}

void	Window::init_screen(void) const
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

void	Window::init_colors(void) const
{
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_CYAN, COLOR_BLACK);
	init_pair(5, COLOR_WHITE, COLOR_BLACK);
}



/*
** GETTERS *********************************************************************
*/

int		Window::get_hmax() const
{
	return (m_hmax);
}

int		Window::get_wmax() const
{
	return (m_wmax);
}

WINDOW*	Window::get_win() const
{
	return (m_win);
}
