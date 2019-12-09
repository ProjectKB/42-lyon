/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.cpp                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/09 11:37:03 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/09 13:39:22 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <iostream>
#include <string>

using namespace std;

typedef string str;

int	main(void)
{
	int	*ptr;
	str	*ptr_str;

	ptr = new int[5];
	ptr_str = new str[50];

	*(ptr + 1) = 100;
	cout << *(ptr + 1) << ptr[1] << "\n";
	delete ptr; // classic free
	delete[] ptr_str; // double dimension free
	return (0);
}
