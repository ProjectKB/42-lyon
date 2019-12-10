/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   range_loop.cpp                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/10 18:34:32 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/10 20:53:20 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void	ranged_based_for(vector<int> &v)
{
	for (auto d : v)
		cout << d << "\n";
	cout <<"\n";
}

int	greather_than(int a, int b)
{
	return (a > b);
}

void	lambdas_function(function<int(int, int)> f, vector<int> &v, int mod)
{
	auto f2 = [](int a, int b){return a > b;};

	switch (mod)
	{
		case 1:
			sort(v.begin(), v.end(), f);
			break;
		case 2:
			sort(v.begin(), v.end(), [](int a, int b){return a < b;});
			break;
		case 3:
			sort(v.begin(), v.end(), f2);
			break;
	}
	ranged_based_for(v);
}

void	lambdas_function2(vector<int> &v)
{
	auto f = [](int &i){++i;};
	auto f2 = [](int i){return i + 1;};

	for_each(v.begin(), v.end(), f);
	ranged_based_for(v);
	transform(v.begin(), v.end(), v.begin(), f2);
	ranged_based_for(v);
}

int	main(void)
{
	vector<int>	v{1, 2, 3, 4};

	lambdas_function(greather_than, v, 1);
	lambdas_function(greather_than, v, 2);
	lambdas_function(greather_than, v, 3);
	lambdas_function2(v);
	return (0);
}
