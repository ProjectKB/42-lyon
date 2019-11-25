/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.cpp                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/25 12:59:50 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/25 13:42:35 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

/*
Rule N1: static methods/attributs can be use without instance of class
Rule N2: use statics attributs with parsimony (global)
Rule N3: friend method can access everything into target class
Rule N4: use friendship with parsimony (don't break encapsulation rules)
Rule N5: a static attribut is shared by every instance of a class
*/

#include "header.hpp"

int main()
{
	Human a;
	Human b;
	Human c;
	Human d;

	Instance_info::display();
	cout << a;
	return (0);
}
