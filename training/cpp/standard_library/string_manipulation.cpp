/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   string_manipulation.cpp                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/28 16:44:37 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/30 14:29:47 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <cctype>
#include <functional>

using namespace std;
typedef string str;

struct	TestVowel
{
	bool operator()(unsigned char c)
	{
		switch (c)
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

template <typename T>
void	display_tab(T tab)
{
	copy(tab.begin(), tab.end(), ostream_iterator<char>(cout, ""));
	cout << "\n";
}

struct To_Upper
{
	void	operator()(char &c)
	{
		c = toupper(c);
	}
};

void	to_upper(char &c)
{
	c = toupper(c);
}

char	to_upper2(const char &c)
{
	return toupper(c);
}

bool	is_palind(str palind)
{
	back_insert_iterator<str>	it(palind);

	for_each(palind.begin(), palind.end(), to_upper);
	transform(palind.begin(), palind.end(), palind.begin(), to_upper2);
	cout << palind;
	if (*(mismatch(palind.begin(), palind.end(), palind.rbegin()).first))
		return false;
	return true;
}

int main()
{
	str	s1;
	str	s2;
	TestVowel	f;
	back_insert_iterator<str>	it(s2);
	str::iterator	it2;
	str	haystack;
	str	needle;
	str	palind;

	s1 = "Bien le bonjour";
	haystack = "La bonne journee, sir.";
	needle = "bonne journee";
	str::iterator n;

	// remove x
	s1.erase(remove(s1.begin(), s1.end(), ' '), s1.end());
	display_tab(s1);

	// remove with range
	s1.erase(s1.begin(), s1.begin() + 2);
	display_tab(s1);

	// reverse x
	reverse(s1.begin(), s1.end());
	display_tab(s1);

	// apply functor for create new x
	for (str::iterator it = s1.begin(); it != s1.end(); ++it)
		if (!(f(*it)))
			s2.push_back(*it);
	display_tab(s2);

	// find elem
	it2 = find(s2.begin(), s2.end(), 'j');
	it2 != s2.end() ? cout << *it2 << "\n" : cout << "Element not found.\n";

	// find subsequence into x
	n = search(haystack.begin(), haystack.end(), needle.begin(), needle.end());
	n != haystack.end() ? cout << "Item found at index " << n-haystack.begin() << "\n":
		cout << "Element not foun.\n";

	// test if palind us palindrome
	cout << is_palind("aCCA") << "\n";

	return (0);
}
