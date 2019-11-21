/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   character.cpp                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/21 19:50:42 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/21 20:23:41 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "warrior.hpp"

Warrior::Warrior(string name) : Character(name)
{
	buff();
};

void	Warrior::introduce_ourself() const
{
	Character::introduce_ourself();
	cout << "I'm a furious warior !\n";
}

void	Warrior::buff()
{
	m_life += 5;
}
