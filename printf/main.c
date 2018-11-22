/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/18 15:56:25 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/22 18:34:56 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

int main()
{
	t_arg *test;
	char *s;

	printf("content : '%42.19c'\n", 'a');
	s = (char*)malloc(sizeof(*s));
	test = create_elem();
	test = parse_string("%42.19c");
	parse_args(test, 'a');
	display_list_content(test);
	return (0);
}
