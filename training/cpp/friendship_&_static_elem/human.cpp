/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   human.cpp                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/25 13:06:45 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/25 13:37:40 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "header.hpp"

int Instance_info::nb = 0;

void	Instance_info::display()
{
	if (Instance_info::nb < 2)
		cout << "There is " << Instance_info::nb << " instance.\n";
	else
		cout << "There are " << Instance_info::nb << " instances.\n";
}



Human::Human(str name) : m_name(name)
{
	Instance_info::nb++;
	Instance_info::display();
}

void	Human::display(ostream &flux) const
{
	flux << "My name is " << m_name << ".\n";
}

ostream &operator<<(ostream &flux, Human const &a)
{
	a.display(flux);
	return (flux);
}
