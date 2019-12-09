/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   Window.hpp                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/02 13:43:42 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/06 03:51:54 by loiberti    ###    #+. /#+    ###.fr     */
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

		void	set_screen();

		int		get_hmax() const;
		int		get_wmax() const;
		WINDOW	*get_win() const;

	private:
		WINDOW	*m_win;
		int		m_hmax;
		int		m_wmax;

		void	init_screen(void) const;
		void	init_colors(void) const;
		void	init_var(void);
};

#endif
