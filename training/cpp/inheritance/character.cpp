/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   character.cpp                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/21 19:50:42 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/21 20:19:10 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "character.hpp"

Character::Character(str name) : m_name(name), m_life(10) {};

void	Character::introduce_ourself() const
{
	cout << "Hi ! My name is " << m_name << " !\n";
	cout << "I've got " << m_life << " life points.\n";
}
