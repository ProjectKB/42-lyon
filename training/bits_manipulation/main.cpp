/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.cpp                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/05 22:29:35 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/06 00:17:03 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <iostream>
#include <bitset>

using namespace std;

void	print_truth_table(void)
{
	cout << "\n| A | 0 | 1 | 0 | 1 |" << "\n";
	cout << "| B | 0 | 0 | 1 | 1 |" << "\n";
	cout << "|-------------------|\n";
	cout << "| & | 0 | 0 | 0 | 1 |" << "\n";
	cout << "| | | 0 | 1 | 1 | 1 |" << "\n";
	cout << "| ^ | 0 | 1 | 1 | 0 |" << "\n";
	cout << "| ~A| 1 | 0 | 1 | 0 |" << "\n\n";
}

void	print_binary(int nb)
{
	cout << bitset<8>(nb).to_string() << " -> " << nb << "\n";
}

void	set_bit(int nb, int nb_bit, int mod)
{
	switch (mod)
	{
		case 0:
			print_binary(nb | (1 << nb_bit));
			break;
		case 1:
			print_binary(nb | nb_bit);
			break;
		case 2:
			print_binary(nb ^ (1 << nb_bit));
			break;
		case 3:
			print_binary(nb ^ nb_bit);
			break;
	}
}

bool	test_bit(int bit, int bit_nb)
{
	return (!(bit & (1 << bit_nb)) ? 0 : 1);
}

int	main()
{
	print_truth_table();
	set_bit(0, 0b01010101, 1);
	set_bit(0, 0b10101010, 3);
	set_bit(0, 0, 0);
	set_bit(255, 0, 2);
	cout << test_bit(1, 0) << "\n";
	return (0);
}
