/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   templates.hpp                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/27 18:47:23 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/27 22:48:36 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef TEMPLATES_HPP

# define TEMPLATES_HPP

# include <iostream>
# include <string>
# include <vector>

using namespace std;

typedef string str;

/*template <typename T>
T	addition(const T &a, const T &b)
{
	return a + b;
}*/

template <typename T>
class Rectangle
{
	T	m_left;
	T	m_right;
	T	m_up;
	T	m_down;

	public:
		Rectangle(T left, T right, T up, T down) : m_left(left), m_right(right), m_up(up), m_down(down) {}

		T	get_height() const
		{
			return m_up - m_down;
		}

		T	is_inside(T x, T y) const
		{
			return ((x >= m_left) && (x <= m_right) && (y <= m_up) && (y >= m_down));
		}
	
	private:
		void	display(ostream &flux) const
		{
			flux << "left : " << m_left << " | right: " << m_right << " | up : " << m_up << " | down: " << m_down;
		}

		friend ostream& operator<<(ostream &flux, Rectangle<T> const &other)
		{
			other.display(flux);
			return flux;
		}
};

#endif
