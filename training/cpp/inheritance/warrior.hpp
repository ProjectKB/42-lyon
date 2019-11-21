/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   character.hpp                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/21 19:42:14 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/21 20:18:59 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef WARRIOR_HPP

# define WARRIOR_HPP

# include <iostream>
# include <string>
# include "character.hpp"

using namespace std;
using str = string;

class Warrior : public Character
{

	public:
		Warrior(string name);
		
		void	introduce_ourself() const;
		void	buff();

};

#endif
