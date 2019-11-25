/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.cpp                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/25 15:29:39 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/25 15:53:30 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

/*
STL doc
	* http://www.cplusplus.com/reference/
	* https://stdcxx.apache.org/doc/stdlibref/2.html
	* http://www.martinbroadhurst.com/stl/
*/

#include <iostream>
#include <cmath> // doc http://www.cplusplus.com/reference/cmath/
#include <cctype> // test nature of char and modify it
#include <ctime>
#include <cstdlib> // for random value
#include <string>

using namespace std;
using str = string;

void	cctype_lib_ex(char c)
{
	if (isalpha(c))
		cout << "This is a letter.\n";
	else if (islower(c))
		cout << "This is lowercase.\n";
	c = toupper(c);
	cout << c << "\n";
}

void	ctime_lib_ex()
{
	int	secondes;

	secondes  = time(0);
	cout << "It has passed " << secondes << " secondes since the 01/01/1970.\n";
}

void	cstdlib_ex(int interval)
{
	srand(time(0)); // random sequence initialisation

	cout << rand() % interval << "\n"; // interval is not inclusive
}

int main()
{
	cctype_lib_ex('d');
	ctime_lib_ex();
	cstdlib_ex(10);
	return (0);
}
