/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   human.cpp                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/21 17:43:56 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/21 18:49:18 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "human.hpp"

Human::Human(str name) : m_name(name), m_weap(0)
{
	m_weap = new Weapon();
};

Human::Human(const Human &other) : m_name(other.m_name), m_weap(0)
{
	// we have to dereference the pointeur to topy only his content
	m_weap = new Weapon(*(other.m_weap));
};

Human::~Human()
{
	delete m_weap;
}

Human& Human::operator=(Human const & other)
{
	// check if obj is not himself
	if (this != &other)
	{
		m_name = other.m_name;
		// m_weap is allocated we have to free before copy
		delete m_weap;
		// we have to dereference the pointer to topy only his content
		m_weap = new Weapon(*(other.m_weap));
	}
	// this == address and *this == pointer content;
	return *this;
}


void Human::display(ostream &flux) const
{
	flux << "Human name: " << m_name << "\n";
	flux << "address: " << this << "\n";
	flux << *(this->m_weap) << "\n";
}



/*
** None object functions
*/

ostream &operator<<(ostream &flux, Human const &to_display)
{
	to_display.display(flux);
	return flux;
}
