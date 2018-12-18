/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printf.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/15 16:56:01 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/16 09:20:04 by loiberti    ###    #+. /#+    ###.fr     */
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

int		ft_printf(const char *format, ...) __attribute__((format(printf,1,2)));

typedef enum	e_lm {
	WOAW,
	hh,
	h,
	l,
	ll,
	L
}				t_lm;

typedef enum	e_ci {
	woaw,
	c,
	s,
	p,
	di,
	o,
	u,
	x,
	X,
	f,
	spe,
}				t_ci;

typedef struct	s_arg {
	struct s_arg	*next;
	char			*flag;
	char			*field;
	int				pre;
	t_lm			l_m;
	t_ci			c_i;
	char			*content;
}				t_arg;

/*
** LISTS TOOLS
*/
t_arg			*create_elem(void);
void			display_list_content(t_arg *list);
void			create_and_move_forward(t_arg **param);
void			free_list(t_arg *list);

/*
** FILL STRUCT
*/
int				stock_ordinary_char(char **str, char *format, int *i);
void			double_to_one_pourcent(char **str, int *i, char *format);
void			stock_flag(char **flag, char *format, int *i);
void			stock_field(char **field, char *format, int *i);
void			stock_precision(int *precision, char *format, int *i);
void			stock_length_modifier(t_lm *length_modifier, \
														char *format, int *i);
void			stock_conversion_indicator(t_ci *c_i, char *format, int *i);
void			stock_arg_description(t_arg *param, char *format, int *i);
t_arg			*parse_string(const char *format);
void			stock_content(t_arg *param, char **content, void *to_display);
void			parse_args(t_arg *param, ...);
void			stock_global_content(t_arg *arg, va_list va, int *len_print);

/*
** MANAGE FLAG
*/
void			fix_impossible_comb(char **flag);
void			fix_impossible_flag(char **flag, t_ci c_i);
void			transform_flag(t_arg *param);
void			hash_tag_comportement(t_arg **param);
void			plus_comportement(t_arg **param);
void			aq_comportement(t_arg **param);
void			zero_comportement(t_arg **param);

/*
** MANAGE FIELD
*/
void			fill_field(char **field, t_arg *param);

/*
** MANAGE PRECISION
*/
char			*precision_tr(char *content, t_arg *param);

/*
** MANAGE LENGTH MODIFIER
*/
void			stock_content_lm(t_arg *param, char **content, void *to_stock);
void			special_case_lm(t_arg *param);

/*
** FLOAT
*/
char			*ftoa(long double nb, char *s, int precision);
int				flt_len(long double n);

/*
** TRANSFORM CHAIN
*/
void			transform_chain(t_arg **param);

/*
** DISPLAY CHAIN
*/
void			final_display(t_arg *param);
int				ft_printf(const char *format, ...);

#endif
