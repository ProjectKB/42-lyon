/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.cpp                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/21 20:57:32 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/25 12:54:04 by loiberti    ###    #+. /#+    ###.fr     */
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
Rule N4: Always have a virtual desconstructor when using polymorphism
Rule N5: an heterogeneous collection can be created with childs of class
         (think about the garage example)
Rule N6: A pure virtual function is a function describe in mother class (proto)
         and written in child(s) class;
Rule N7: If A contain a pure virtual function you can't create A instance
Rule N8: A virtual method can be redefined in child class.
         A pure virtual method must be redefined in child class.

*/

#include "vehicules.hpp"

int main()
{
	vector<Vehicule*>	vehicule_lst;

	vehicule_lst.push_back(new Car(15000, 5));
	vehicule_lst.push_back(new Car(12000, 3));
	vehicule_lst.push_back(new Motorcycle(2000, 212));


	for (int i(0); i < (int)vehicule_lst.size(); ++i)
	{
		vehicule_lst[i]->display();
		cout << "It has " << vehicule_lst[i]->nbr_wheels() << " wheels.\n\n";
		delete vehicule_lst[i];
		vehicule_lst[i] = 0;
	}

	return (0);
}
