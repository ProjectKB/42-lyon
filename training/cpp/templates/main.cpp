/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   templates.cpp                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/27 18:39:35 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/27 22:51:02 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "templates.hpp"

/*
RULE N1: ALWAYS implement template class only into header file
*/

int main()
{
	Rectangle<int> r1(1, 10, 1, 10);
	Rectangle<double> r2(1.45, 10.45, 3, 10456.654987);

	cout << r1 << "\n";
	cout << r2 << "\n";
	return (0);
}
