/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   human.cpp                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/21 17:43:56 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/21 18:25:14 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "weapon.hpp"

Weapon::Weapon(str name) : m_name(name) {};

Weapon::Weapon(const Weapon &other) : m_name(other.m_name) {};

Weapon::~Weapon()
{
	;
}

void Weapon::display(ostream &flux) const
{
	flux << "Weapon name: " << m_name << "\n";
	flux << "address: " << this << "\n";
}







/*
** None object functions
*/

ostream &operator<<(ostream &flux, Weapon const &to_display)
{
	to_display.display(flux);
	return flux;
}
