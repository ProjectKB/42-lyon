/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   string_manipulation.cpp                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/28 16:44:37 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/28 19:22:20 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <algorithm>

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

int main()
{
	str	s1;
	str	s2;
	TestVowel f;
	back_insert_iterator<str> it(s2);

	s1 = "Bien le bonjour";

	s1.erase(remove(s1.begin(), s1.end(), ' '), s1.end());
	cout << s1 << "\n";

	s1.erase(s1.begin(), s1.begin() + 2);
	cout << s1 << "\n";

	reverse(s1.begin(), s1.end());
	cout << s1 << "\n";

	for (str::iterator it = s1.begin(); it != s1.end(); ++it)
		if (!(f(*it)))
			s2.push_back(*it);
	cout << s2 << "\n";

	return (0);
}
