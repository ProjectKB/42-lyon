/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   header.hpp                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/25 13:00:16 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/25 13:42:38 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef HEADER_HPP

# define HEADER_HPP

# include <iostream>
# include <string>

using namespace std;
using str = string;

struct Instance_info
{
	static int	nb;
	static void	display();
};

class Human
{
	str m_name;

	public:
		Human(str name = "Unknow");

	private:
		void display(ostream &out) const;
		friend ostream &operator<<(ostream &flux, Human const &a);
};

#endif
