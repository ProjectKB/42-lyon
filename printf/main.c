/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/18 15:56:25 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/22 13:59:33 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

int main()
{
	t_arg *test;
	char *s;

	printf("content : '%p'\n", (void*)"coucou");
	s = (char*)malloc(sizeof(*s));
	test = create_elem();
	test = parse_string("%p");
	parse_args(test, (void*)"coucou");
	//printf("content : '%p'\n", (void*)"coucou");
	display_list_content(test);
	return (0);
}
