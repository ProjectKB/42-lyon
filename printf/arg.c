/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   arg.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/15 13:33:10 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/16 18:45:11 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

void	my_print(e_lm length_modifier, void* to_display)
{
	if (length_modifier == CHAR)
		printf("%c ", (int)to_display);
	if (length_modifier == INT)
		printf("%d ", (int)to_display);
	if (length_modifier == P_CHAR)
		printf("%s ", (char*)to_display);
}

void	print_args(char *s, ...)
{
	va_list va;
	int i;
	e_lm length_modifier;

	i = 0;
	va_start(va, s);

	length_modifier = CHAR;
	my_print(length_modifier, va_arg(va, void*));
	length_modifier = INT;
	my_print(length_modifier, va_arg(va, void*));
	length_modifier = P_CHAR;
	my_print(length_modifier, va_arg(va, void*));

	va_end(va);
	return;
}



int main()
{
	char s[] = "hello";

	print_args(s, 'c', 789, "hello");
	return (0);
}
