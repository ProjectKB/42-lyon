/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/18 15:56:25 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/20 20:07:12 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

int main()
{
	t_arg *test;
	int i = 42;
	char flagada[] = "#0-+ ";

	/*test = create_elem();
	test->flag = flagada;
	test->conversion_indicator = c;*/
	test = parse_string("%#+- 04dbonjour%08d%%%%%dyalalahihou%%%d");
	display_list_content(test);
	//print_args(test, 129, 42, 684, 101);
	//printf("%s", test->flag);
	//printf("%#042x", 50);
	return (0);
}
