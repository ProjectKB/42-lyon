/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/18 15:56:25 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/20 20:48:38 by loiberti    ###    #+. /#+    ###.fr     */
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
	test = parse_string("%s%c%d");
	print_args(test, "coucou", 'c', 129);
	display_list_content(test);*/
	//printf("%s", test->flag);
	printf("%p", (void*)65536);
	return (0);
}
