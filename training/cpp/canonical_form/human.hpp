/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   human.hpp                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/30 17:01:39 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/30 17:55:36 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef HUMAN_HPP

# define HUMAN_HPP

# include <iostream>
# include <string>

using namespace std;
typedef string str;

class Human
{
	public:
		Human(void);
		Human(str const name);
		Human(Human const &to_copy);
		~Human(void);

		Human& operator=(Human const &to_assign);

	private:
		str	m_name;

		friend ostream& operator<<(ostream &flux, Human const &to_display);
};


#endif
