/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   exception_assertion.cpp                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/26 22:21:37 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/26 22:40:19 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <exception>
#include <stdlib.h>
#include <cassert>

/*
Exception Errors :
-> domain_error | logique | Erreur de domaine mathématique
-> invalid_argument | logique | Argument invalide passé à une fonction.
-> length_error | logique | Taille invalide.
-> out_of_range | logique | Erreur d'indice de tableau.
-> logic_error | logique | Autre problème de logique.
-> range_error | exécution | Erreur de domaine.
-> overflow_error | exécution | Erreur d'overflow.
-> underflow_error | exécution | Erreur d'underflow.
-> runtime_error | exécution | Autre type d'erreur.
*/

using namespace std;
using str = string;

int	division(int a, int b)
{
	if (!b)
		throw domain_error("Division by zero.\n");
	return a / b;
}

int	main(int argc, char **argv)
{
	int	rez(0);

	if (argc == 3)
	{
		try
		{
			rez = division(atoi(argv[1]), atoi(argv[2]));
		}
		catch(exception const& e)
		{
			cerr << e.what();
		}
	}
	assert(rez != 0);
	cout << "Result is: " << rez << "\n";
	return (0);
}
