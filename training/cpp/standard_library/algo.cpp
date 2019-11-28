/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo.cpp                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/28 15:36:44 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/28 16:43:54 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo.cpp                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/28 13:30:26 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/28 15:19:09 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

using namespace std;

typedef string str;
typedef back_insert_iterator<str> b_str_it;

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

template <typename T>
void	display_tab(vector<T> tab)
{
	copy(tab.begin(), tab.end(), ostream_iterator<T>(cout, " "));
	cout << "\n";
}

void	generate_test(vector<int> &t1, vector<int> &t2) // set value into target
{

	generate(t1.begin(), t1.end() - 1, Generate(10));
	generate(t2.begin(), t2.end() - 1, Generate(10));
	//display_tab(t1);
	//display_tab(t2);
}

void	transform_test(vector<int> t1, vector<int> t2, vector<int> &t3)
{
	// see functional lib for more functor "http://www.cplusplus.com/reference/functional/"
	transform(t1.begin(), t1.end(), t2.begin(), t3.begin(), equal_to<int>());
	display_tab(t3);
	transform(t1.begin(), t1.end(), t2.begin(), t3.begin(), plus<int>());
	display_tab(t3);
	transform(t1.begin(), t1.end(), t2.begin(), t3.begin(), logical_and<int>());
	display_tab(t3);
}

template <typename T>
void	remove_and_remove_if(vector<T> t1)
{
	display_tab(t1);
	t1.erase(remove(t1.begin(), t1.end() - 1, 4)); // remove value
	//t1.erase(remove_if(t1.begin(), t1.end() - 1, bind1st(equal_to<int>(),1))); // applied on value
	//t1.erase(remove_if(t1.begin(), t1.end(), bind2nd(equal_to<int>(),8))); // applied on index
	display_tab(t1);
}

void	mirror_ends(const str &s) // palindrome
{
	cout << str(s.begin(), mismatch(s.begin(), s.end(), s.rbegin()).first) << "\n";
}

/*
see search functional
https://en.cppreference.com/w/cpp/algorithm
*/

int	main()
{
	vector<int>	t1(10);
	vector<int>	t2(10);
	vector<int>	t3(10);

	srand(time(0));
	generate_test(t1, t2);
	//transform_test(t1, t2, t3);
	//remove_and_remove_if(t1);
	//mirror_ends("aba");
	return (0);
}
