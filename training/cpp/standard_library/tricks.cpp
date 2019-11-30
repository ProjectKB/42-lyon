/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tricks.cpp                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/30 14:29:56 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/30 17:00:34 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

typedef string str;

void	display(str &s)
{
	copy(s.begin(), s.end(), ostream_iterator<char> (cout, ""));
	cout << "\n";
}

void	to_upper(char &c)
{
	c = toupper(c);
}

char	to_upper2(const char &c)
{
	return toupper(c);
}

struct	To_Upper
{
	void	operator()(char &c) const
	{
		c = toupper(c);
	}
};

struct	To_Upper2
{
	char	operator()(const char &c) const
	{
		return toupper(c);
	}
};

int main()
{
	str s1("aCcA");
	str s2("aCcA");
	str s3("aCcA");
	str s4("aCcA");
	str s5("aCcA");
	str s6("aCcA");
	str s7("aCcA");
	str s8("aCcA");
	str s9("aCcA");
	str s9c;
	back_insert_iterator<str> it(s9c);
	To_Upper f;
	To_Upper2 f2;

	for_each(s1.begin(), s1.end(), to_upper);
	display(s1);

	for_each(s3.begin(), s3.end(), To_Upper());
	display(s3);

	transform(s2.begin(), s2.end(), s2.begin(), to_upper2);
	display(s2);

	transform(s4.begin(), s4.end(), s4.begin(), To_Upper2());
	display(s4);

	for (str::iterator it(s5.begin()); it != s5.end(); ++it)
		f(*it);
	display(s5);

	for (str::iterator it(s6.begin()); it != s6.end(); ++it)
		*it = f2(*it);
	display(s6);

	for (size_t i(0); i < s7.size(); ++i)
		to_upper(s7[i]);
	display(s7);

	for (size_t i(0); i < s8.size(); ++i)
		s8[i] = to_upper2(s8[i]);
	display(s8);

	transform(s9.begin(), s9.end(), it, to_upper2);
	display(s9);
	display(s9c);
	return (0);
}
