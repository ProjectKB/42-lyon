/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   human.hpp                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/21 17:39:39 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/21 18:00:46 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef WEAPON_CPP

# define WEAPON_CPP

# include <iostream>

using namespace std;
using str = string;

class Weapon {
	str m_name;

	public:
		Weapon(str name = "Basic Sword");
		Weapon(const Weapon &other);
		~Weapon();

		// display object
		void	display(ostream &flux) const;
};

// display operator
ostream&operator<<(ostream &flux, Weapon const &to_display);

#endif
