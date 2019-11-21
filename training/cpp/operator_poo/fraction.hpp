/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fraction.hpp                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/20 16:32:47 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/21 16:42:31 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FRACTION_HPP

# define FRACTION_HPP

# include <iostream>
# include <string>
# include <vector>
# include <map>
# include <stdio.h>
# include <cmath>

using namespace std;
using str = string;

class Zfraction
{
	int	m_num;
	int	m_den;

	public:
		Zfraction(int num = 0, int den = 1);
		Zfraction(const Zfraction &other);
		~Zfraction();

		// comparaison between objects
		bool	eq(Zfraction const &b) const;
		bool	lt(Zfraction const &b) const;

		// operation between objects
		Zfraction	do_op_obj(Zfraction const &b, char op) const;

		// operation on object
		void	operator+=(Zfraction const &b);
		void	operator-=(Zfraction const &b);
		void	operator*=(Zfraction const &b);
		void	operator/=(Zfraction const &b);
		void	operator%=(Zfraction const &b);

		// display object
		void	display(ostream &flux) const;
		double	get_real() const;

		void	get_reduced_form();
};

// comparison operator
bool	operator==(Zfraction const &a, Zfraction const &b);
bool	operator!=(Zfraction const &a, Zfraction const &b);
bool	operator<(Zfraction const &a, Zfraction const &b);
bool	operator>(Zfraction const &a, Zfraction const &b);
bool	operator<=(Zfraction const &a, Zfraction const &b);
bool	operator>=(Zfraction const &a, Zfraction const &b);

// calcul operator
Zfraction	operator+(Zfraction const &a, Zfraction const &b);
Zfraction	operator-(Zfraction const &a, Zfraction const &b);
Zfraction	operator*(Zfraction const &a, Zfraction const &b);
Zfraction	operator/(Zfraction const &a, Zfraction const &b);
Zfraction	operator%(Zfraction const &a, Zfraction const &b);

// display operator
ostream	&operator<<(ostream &flux, Zfraction const &to_display);

//other
int		do_op(int a, char op, int b);
void	division_by_zero();

#endif
