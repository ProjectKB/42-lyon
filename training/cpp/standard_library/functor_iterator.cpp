/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   functor_iterator.cpp                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/25 16:44:31 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/25 18:09:57 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;
using str = string;

/*
-> Iterators are objects use to go through containers
-> Functor are objects used like function applied on elem's container
-> list are sided-chain
*/

void	iterator_ex()
{
	vector<int>				v;
	vector<int>::iterator	it; // same syntax for every container, give the type of the targeted container

	v = {7, 8, 9};
	for (it = v.begin(); it != v.end(); ++it) // iterator are not optimized for comparaison -> use !=
		cout << "v: " << *it << "\n";
}

void	insert_erase_elem()
{
	vector<str>				names;
	vector<str>::iterator	test;

	names = {"Karen", "Mark", "Zack", "Silas"};
	names.insert(names.begin(), "Barack");
	test = names.begin() + 3;
	names.insert(test, "George");
	names.erase(test + 1);
	for (vector<str>::iterator it = names.begin(); it != names.end(); ++it)
		cout << *it << "\n";

	// Vector are not optimized for insertion/deletion at the middle, cf container img
}

void	map_is_pair_object() // map objects are sorted in ascending order
{
	map<str, int> human;

	human = {{"Jonh", 184}, {"Serena", 167}, {"Arthur", 175}};
	for (map<str, int>::iterator it = human.begin(); it != human.end(); ++it)
		cout << it->first << " is " << it->second << "cm tall.\n"; // map is a pair element (first/second)

	// to check if an elem exist use find(X) -> avoid to create the elem
}

class Fill_tab
{
	int	m_value;

	public:
		Fill_tab(int i) : m_value(i) {}
		int operator()(int nb)
		{
			++m_value;
			return m_value + nb;
		}
};

void	map_functor()
{
	vector<int> tab(100, 0);
	Fill_tab f(0);

	for (vector<int>::iterator it = tab.begin(); it != tab.end(); ++it)
	{
		*it = f(5);
		cout << *it << " ";
	}
	cout << "\n";
}

int main()
{
	//iterator_ex();
	//insert_erase_elem();
	//map_is_pair_object();
	map_functor();
	return (0);
}
