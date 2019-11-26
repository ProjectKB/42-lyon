/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   iterator_on_flux.cpp                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/26 02:44:31 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/26 03:46:01 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <sstream> // flux on string

using namespace std;
using str = string;

void	set_iterator_on_output_flux()
{
	ostream_iterator<str>	it(cout, " ");

	*it = "Hello";
	*it = "World!";
}

void	set_iterator_on_input_flux()
{
	ifstream				file("./test.txt");
	istream_iterator<str>	it(file);
	istream_iterator<str>	end; // end signal

	while (it != end)
	{
		cout << *it << "\n";
		++it;
	}
}

void	copy_algorithm()
{
	vector<str>							tab;
	ifstream							file("./test.txt");
	istream_iterator<str>				it(file);
	istream_iterator<str>				end; // end signal
	back_insert_iterator<vector<str>>	it2(tab); // add a new case at the of end of tab

	copy(it, end, it2);
	copy(tab.begin(), tab.end(), ostream_iterator<str>(cout, "\n"));
}

void	min_max_elem()
{
	ifstream file("./test.txt");
	cout << *min_element(istream_iterator<str>(file), istream_iterator<str>()) << "\n";
	cout << *max_element(istream_iterator<str>(file), istream_iterator<str>()) << "\n";
}

void	flux_on_string()
{
	ostringstream	flux;
	str				s;
	str				test("Ceci");

	flux << test << " est un " << 42;
	s = flux.str();
	cout << s << "\n";
}

int		main()
{
	//set_iterator_on_output_flux();
	//set_iterator_on_input_flux();
	//copy_algorithm();
	//min_max_elem();
	flux_on_string();
	return (0);
}
