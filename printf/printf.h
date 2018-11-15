/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printf.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/15 16:56:01 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/15 21:12:35 by loiberti    ###    #+. /#+    ###.fr     */
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
	CHAR,
	INT,
	DOUBLE,
	SIGNED_CHAR,
	UNSIGNED_CHAR,
	UNSIGNED_INT,
	SHORT_INT,
	LONG_DOUBLE,
	LONG_INT,
	LONG_LONG_INT,
	P_CHAR,
	P_VOID
} e_LM;

typedef enum {
	c,
	s,
	p,
	d,
	i,
	o,
	u,
	x,
	X,
	f
} e_CI;

typedef struct s_arg {
	struct s_arg	*next;
	char	*flag;
	int		width;
	int		precision;
	e_LM	length_modifier;
	e_CI	conversion_indicator;
	void	*content;
	int		size_content;
} t_arg;

t_arg	*create_elem(void);
void	push_back(t_arg **param);

t_arg	*parse_string(const char *format);

#endif
