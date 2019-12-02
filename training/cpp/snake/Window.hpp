/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   Window.hpp                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/02 13:43:42 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/02 14:33:21 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef WINDOW_HPP

# define WINDOW_HPP

# include <curses.h>

class Window
{
	public:
		Window(void);
		Window(const Window &to_copy);
		~Window(void);

		int		get_hmax();
		int		get_wmax();
		WINDOW	*get_win();

	private:
		WINDOW	*m_win;
		int		m_hmax;
		int		m_wmax;

		void	init_screen(void);
		void	init_var(void);
};

#endif
