/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.cpp                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/21 17:52:34 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/21 18:44:48 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "human.hpp"
#include "weapon.hpp"

int main()
{
	Human henri{"Henri"};
	Human jack{"Jack"};
	Human arnold{henri};
	Human brandon;

	brandon = henri;
	cout << henri << "\n";
	cout << jack << "\n";
	cout << arnold << "\n";
	cout << brandon << "\n";


	return (0);
}
