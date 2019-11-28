/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algorithms.cpp                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/26 01:30:53 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/28 13:30:18 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <list>

using namespace std;
typedef string str;

class	Generate
{
	int	m_interval;

	public:
		Generate(int interval) : m_interval(interval) {}
		int operator()() const
		{
			return rand() % m_interval;
		}
};

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

struct	Display
{
	void	operator()(int a) const
	{
		cout << a << "\n";
	}
};

int		main()
{
	srand(time(0));
	vector<int>	tab(100, 0);
	vector<int>	tab3(100, 0);
	list<str>	tab2(100, "coucou");
	vector<int>::iterator it;
	list<str>::iterator it2;

	generate(tab.begin(), tab.end(), Generate(10)); // apply on every elem of tab
	generate(tab3.begin(), tab3.end(), Generate(10)); // apply on every elem of tab
	cout << "There are " << count(tab.begin(), tab.end(), 5) << " times number 5\n"; // count occur of x
	cout << "There are " << count_if(tab2.begin(), tab2.end(), TestVowel()) << " word with vowel(s) in this tab.\n";
	it = find(tab.begin(), tab.end(), 5); // return iterator of first occur
	it2 = find_if(tab2.begin(), tab2.end(), TestVowel()); // idem with predicate
	sort(tab.begin(), tab.end()); // sort elem in ascending order, it's possible to overload the operator of comparaison
	transform(tab.begin(), tab.end(), tab3.begin(), tab3.begin(), plus<int>()); // apply functor between two vector
	for_each(tab3.begin(), tab3.end(), Display()); // apply function on every elem
}
