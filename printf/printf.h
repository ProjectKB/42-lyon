/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printf.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/15 16:56:01 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/16 22:11:40 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef PRINTF_H

# define PRINTF_H

# include <stdarg.h>
# include <wchar.h>
# include <locale.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef enum {
	WOAW,
	CHAR,
	INT,
	DOUBLE,
	SIGNED_UNSIGNED_CHAR,
	SHORT_UNSIGNED_SHORT_INT,
	LONG_DOUBLE,
	LONG_UNSIGNED_LONG_INT,
	LONG_LONG_UNSIGNED_LONG_LONG_INT,
	L_N_OR_F,
	P_CHAR,
	P_VOID
} e_lm;

typedef enum {
	woaw,
	c,
	s,
	p,
	di,
	o,
	u,
	x,
	X,
	f
} e_ci;

typedef struct s_arg {
	struct s_arg	*next;
	char	*flag;
	int		field;
	int		precision;
	e_lm	length_modifier;
	e_ci	conversion_indicator;
	char	*content;
	int		len_print;
} t_arg;

/*
** TOOLS
*/
char	*charjoin(char *str, char c);

/*
** LISTS TOOLS
*/
t_arg	*create_elem(void);
void	display_list_content(t_arg *list);

t_arg	*parse_string(const char *format);

#endif
