/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   arg.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/15 13:33:10 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/15 17:48:35 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

/*void	my_print(l_modificator TYPE_ARG, void* to_display)
{
	if (TYPE_ARG == INT)
		printf("%d ", (int)to_display);
	if (TYPE_ARG == P_CHAR)
		printf("%s ", (char*)to_display);
}

void	print_args(char *s, ...)
{
	va_list va;
	int i;
	l_modificator TYPE_ARG;

	i = 0;
	va_start(va, s);
	while (i++ < 2)
	{
		TYPE_ARG = INT;
		my_print(TYPE_ARG, va_arg(va, void*));
	}
	va_end(va);
	return;
}*/



int main()
{
	char s[] = "hello";

	print_args(s, 42, 789, "hello");
	return (0);
}
