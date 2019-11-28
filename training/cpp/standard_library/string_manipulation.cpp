/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   string_manipulation.cpp                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/28 16:44:37 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/28 16:58:13 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
typedef string str;

struct IsVowel
{
	bool operator()(const str &s) const
	{
		for (size_t i(0); i < s.size(); ++i)
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

int main()
{
	str	s1;

	s1 = "Bien le bonjour";
	remove_if(s1.begin(), s1.end(), IsVowel(s1));
	cout << s1 << "\n";
}
