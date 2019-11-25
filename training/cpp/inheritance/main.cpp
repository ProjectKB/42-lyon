/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.cpp                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/21 19:11:47 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/21 20:56:39 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

/*
RULE N1 : There is inheritance when we can say : A is a B
RULE N2 : B inherit of every caracteristics of A
RULE N3 : A = B is valid || B = A is not
RULE N4 : a masked function is a function inside B who has the same name than
          another function of A, fun(B) has priority
RULE N5 : to unmasked a function just call A::fun() into B
RULE N6 : In B's construct call A constructor into initiation list
RULE N7 : Protected(A) = Private except for B where Protected(A) = Public
*/

#include "character.hpp"
#include "warrior.hpp"

int main()
{
	Character rand{"Jonh"};
	Warrior war{"Grodam"};

	rand.introduce_ourself();
	cout << "\n";
	war.introduce_ourself();
	return (0);
}
