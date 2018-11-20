/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/08 13:14:08 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/20 12:43:59 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <wchar.h>
#include <locale.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

/*int ft_printf(const char *format-string, ...)
  {
  va_list va;
  va_start (va, n);
  int i = 0;

  while (i < ap)
  {
  int x = va_arg (va, int);

  }

  printf("%c ", x);
  printf("%s ", z);
  printf("%d", y);

  putchar ('\n');
  va_end (va);
  }*/


int main (void)
{
	wchar_t *s;
	int *t;

	s = (wchar_t *) malloc(sizeof(wchar_t) * 2);
	s[0] = 0x80;
	s[1] = 0xC2;
	t = (int*) malloc(sizeof(*t) * 2);
	t[0] = 206;
	t[1] = 177;
	write(1, &(t[0]), 1);
	write(1, &(t[1]), 1);

	setlocale(LC_ALL, "");

	printf("%C\n", 945);
	putwchar(945);

	return (0);
}


