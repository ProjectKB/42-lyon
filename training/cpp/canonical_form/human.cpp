/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   human.cpp                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/30 17:01:40 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/30 17:55:40 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "human.hpp"

Human::Human(void) : m_name("Unknow") {}

Human::Human(str name) : m_name(name) {}

Human::Human(Human const &to_copy)
{
	*this = to_copy;
}

Human::~Human(void) {}

Human&	Human::operator=(Human const &to_assign)
{
	if (this != &to_assign)
		m_name = to_assign.m_name;
	return *this;
}

ostream&	operator<<(ostream &flux, Human const &to_display)
{
	flux << "Hi ! My name is " << to_display.m_name << ".\n";
	return flux;
}
