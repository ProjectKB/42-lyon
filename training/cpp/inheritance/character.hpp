/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   character.hpp                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/21 19:42:14 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/21 20:18:50 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef CHARACTER_HPP

# define CHARACTER_HPP

# include <iostream>
# include <string>

using namespace std;
using str = string;

class Character
{
	protected:
		str	m_name;
		int	m_life;

	public:
		Character(str name = "Unknow");
		
		void	introduce_ourself() const;

};

#endif
