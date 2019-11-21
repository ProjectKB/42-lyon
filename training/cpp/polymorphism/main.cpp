/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.cpp                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/21 20:57:32 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/21 21:37:13 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

/*

Rule N1: If you call a masked method of B outside of the scope of the class
         you'll be in a "static link resolution", fun(A) has priority
Rule N2: If you want that fun(b) has priority we speak about
         "dynamic link resolution".
         You'll need pointer/reference and virtual method
Rule N3: There is never need of virtual method for constructor
Rule N4: Always have a virtual constructor when using polymorphism

*/

#include "vehicules.hpp"

int main()
{
	Vehicule	v{10000};
	Car			c{20000, 5};
	Motorcycle		m{5000, 220};

	present_vehicule(v);
	present_vehicule(c);
	present_vehicule(m);

	return (0);
}
