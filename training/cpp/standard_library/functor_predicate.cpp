/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   functor_predicate.cpp                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/25 18:11:24 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/25 18:40:50 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>
#include <functional> // see http://www.cplusplus.com/reference/functional/
#include <map>

/*
-> functors are kind of pointer to function
-> see functional lib for pre-defined functor
*/

using namespace std;
using str = string;

struct	TestVowel
{
	bool operator()(const str &s) const
	{
		for (int i(0); i < (int)s.size(); ++i)
			switch (s[i])
			{
				case 'a':
				case 'e':
				case 'i':
				case 'o':
				case 'u':
				case 'y':
					return true;
				default:
					break;
			}
		return false;
	}
};

void	test_predicate()
{
	vector<str>	tab;
	TestVowel	f;

	tab = {"Hello", "Lalala", "NRV", "Yalalahihou"};
	for (vector<str>::iterator it = tab.begin(); it != tab.end(); ++it)
		cout << *it << (f(*it) ? ": True\n" : ": False\n");
}

struct	Compare_length
{
	bool operator()(const str &s1, const str &s2) const
	{
		return s1.length() < s2.length();
	}
};

void	test_map_functor_modified()
{
	map<str, int, Compare_length> h;

	h = {{"Zoro", 185}, {"Belios", 285}, {"Argos", 200}};
	for (map<str, int>::iterator it = h.begin(); it != h.end(); ++it)
		cout << it->first << " is " << it->second << "cm tall.\n";
}

int main()
{
	test_predicate();
	return (0);
}
