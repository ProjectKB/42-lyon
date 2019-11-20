/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fraction.cpp                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/20 16:42:12 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/20 21:46:42 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fraction.hpp"

Zfraction::Zfraction() : m_num(0), m_den(1) {}

Zfraction::Zfraction(int num, int den) : m_num(num), m_den(den)
{
	get_reduced_form();
}

Zfraction::Zfraction(const Zfraction &other) : m_num(other.m_num), m_den(other.m_den)
{
	get_reduced_form();
}

Zfraction::~Zfraction()
{
	;
}


// comparaison between objects
bool Zfraction::eq(Zfraction const &b) const
{
	return (m_num == b.m_num && m_den == b.m_den);
}

bool Zfraction::lt(Zfraction const &b) const
{
	return (m_num * b.m_den < m_den * b.m_num);
}


// operation between objects
Zfraction Zfraction::do_op(Zfraction const &b, char op) const
{
	Zfraction rez{m_num + b.m_num, m_den + b.m_den};

	if (op == '-')
		Zfraction rez{m_num - b.m_num, m_den - b.m_den};
	else if (op == '*')
		Zfraction rez{m_num * b.m_num, m_den * b.m_den};
	else if (op == '/')
		Zfraction rez{m_num / b.m_num, m_den / b.m_den};
	else if (op == '%')
		Zfraction rez{m_num % b.m_num, m_den % b.m_den};
	return rez;
}


// operation on object
void	Zfraction::operator+=(Zfraction const &b)
{
	m_num += b.m_num;
	m_den += b.m_den;
}

void	Zfraction::operator-=(Zfraction const &b)
{
	m_num -= b.m_num;
	m_den -= b.m_den;
}

void	Zfraction::operator*=(Zfraction const &b)
{
	m_num *= b.m_num;
	m_den *= b.m_den;
}

void	Zfraction::operator/=(Zfraction const &b)
{
	m_num /= b.m_num;
	m_den /= b.m_den;
}

void	Zfraction::operator%=(Zfraction const &b)
{
	m_num %= b.m_num;
	m_den %= b.m_den;
}


// display object
void	Zfraction::display(ostream &flux) const
{
	m_den != 1 ? flux << m_num << "/" << m_den : cout << m_num;
}



void	Zfraction::get_reduced_form()
{
	while (!(m_num % 2) && !(m_den % 2))
	{
		m_num /= 2;
		m_den /= 2;
	}
}


/*
** none class functions :
*/


// comparison operator
bool operator==(Zfraction const& a, Zfraction const &b)
{
	return a.eq(b);
}

bool operator!=(Zfraction const& a, Zfraction const &b)
{
	return !(a.eq(b));
}

bool operator<(Zfraction const& a, Zfraction const &b)
{
	return a.lt(b);
}

bool operator>(Zfraction const& a, Zfraction const &b)
{
	return b.lt(a);
}

bool operator<=(Zfraction const& a, Zfraction const &b)
{
	return !(b.lt(a));
}

bool operator>=(Zfraction const& a, Zfraction const &b)
{
	return !(a.lt(b));
}


// calcul operator
Zfraction operator+(Zfraction const& a, Zfraction const &b)
{
	return a.do_op(b, '+');
}

Zfraction operator-(Zfraction const& a, Zfraction const &b)
{
	return a.do_op(b, '-');
}

Zfraction operator*(Zfraction const& a, Zfraction const &b)
{
	return a.do_op(b, '*');
}

Zfraction operator/(Zfraction const& a, Zfraction const &b)
{
	return a.do_op(b, '/');
}

Zfraction operator%(Zfraction const& a, Zfraction const &b)
{
	return a.do_op(b, '%');
}


// display operator
ostream &operator<<(ostream &flux, Zfraction const &to_display)
{
	to_display.display(flux);
	return flux;
}
