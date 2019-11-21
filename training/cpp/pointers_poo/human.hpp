/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   human.hpp                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/21 17:39:39 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/21 18:31:15 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef HUMAN_CPP

# define HUMAN_CPP

# include <iostream>
# include "weapon.hpp"

using namespace std;
using str = string;

class Human {
	str		m_name;
	Weapon	*m_weap;

	public:
		Human(str name = "No Name");
		Human(const Human &other);
		~Human();

		//assignation operator
		Human& operator=(Human const &other);

		// display object
		void	display(ostream &flux) const;
};

// display operator
ostream&operator<<(ostream &flux, Human const &to_display);

#endif
