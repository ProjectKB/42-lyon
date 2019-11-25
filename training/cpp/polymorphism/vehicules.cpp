/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   vehicules.cpp                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/21 21:22:05 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/25 12:54:48 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "vehicules.hpp"

Vehicule::Vehicule(int price) : m_price(price) {};

Vehicule::~Vehicule() {};

void	Vehicule::display() const
{
	cout << "This vehicule cost " << m_price << " euros.\n";
}



Car::Car(int price, int doors) : Vehicule(price), m_doors(doors), m_wheels(4) {};

Car::~Car() {};

void	Car::display() const
{
	cout << "This vehicule cost " << m_price << "euros and has " << m_doors << " doors.\n";
}

int		Car::nbr_wheels() const
{
	return m_wheels;
}


Motorcycle::Motorcycle(int price, int speed) : Vehicule(price), m_speed(speed), m_wheels(2) {};

Motorcycle::~Motorcycle() {};

void	Motorcycle::display() const
{
	cout << "This vehicule cost " << m_price << " euros and reach " << m_speed << " km.\n";
}

int		Motorcycle::nbr_wheels() const
{
	return m_wheels;
}


/*
** None Object Functions
*/


void	present_vehicule(Vehicule const& v)
{
	v.display();
}
