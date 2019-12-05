/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test.cpp                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/02 14:30:38 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/02 22:26:50 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "Window.hpp"
#include "Snake.hpp"

int main()
{
	Window	win;
	Snake	s1(win, "TEST");
	Snake	s2(win, "TEST");

	srand(time(0));
	generate_goal(Snake::goal, win);

	while (42)
	{
		s1.process();
		s2.process();
		wrefresh(win.get_win());
	}
	endwin();
	return (0);
}
