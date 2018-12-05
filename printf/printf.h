/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printf.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/15 16:56:01 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/05 16:49:22 by loiberti    ###    #+. /#+    ###.fr     */
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

int		ft_printf(const char *format, ...) __attribute__((format(printf, 1, 2)));

typedef enum {
	WOAW,
	hh,
	h,
	l,
	ll,
	L
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
	f,
	spe,
} e_ci;

typedef struct s_arg {
	struct s_arg	*next;
	char	*flag;
	char	*field;
	int		precision;
	e_lm	length_modifier;
	e_ci	conversion_indicator;
	char	*content;
} t_arg;

/*
** TOOLS
*/
char	*charjoin(char *str, char c);
char	*charrjoin(char *str, char c);
int		str_are_equal(char *ref, char *to_compare);
int		str_is_equal(char *ref);
void	remove_char_from_str(char **to_transform, char c);
void	remove_one_char_from_str(char **to_transform, char c);
char	nb_char_occur(char *str);
char	*string_null(char *str);

/*
** LISTS TOOLS
*/
t_arg	*create_elem(void);
void	display_list_content(t_arg *list);
void	create_and_move_forward(t_arg **param);

/*
** FILL STRUCT
*/
int		stock_ordinary_char(char **str, char *format, int *i);
void	double_to_one_pourcent(char **str);
void	stock_flag(char **flag, char *format, int *i);
void	stock_field(char **field, char *format, int *i);
void	stock_precision(int *precision, char *format, int *i);
void	stock_length_modifier(e_lm *length_modifier, char *format, int *i);
void	stock_conversion_indicator(e_ci *conversion_indicator, char *format, int *i);
void	stock_arg_description(t_arg *param, char *format, int *i);
t_arg	*parse_string(const char *format);
void	stock_content(t_arg *param, char **content, void *to_display);
void	parse_args(t_arg *param, ...);
int		ft_printf(const char *format, ...);

/*
** MANAGE FLAG
*/
void	fix_impossible_comb(char **flag);
void	fix_impossible_flag(char **flag,  e_ci c_i);
void	transform_flag(t_arg *param);
void	hash_tag_comportement(t_arg **param);
void	plus_comportement(t_arg **param);
void	aq_comportement(t_arg **param);
void	zero_comportement(t_arg **param);

/*
** MANAGE FIELD
*/
void	fill_field(char **field, t_arg *param);

/*
** MANAGE PRECISION
*/
char	*precision_tr(char *content, t_arg *param);

/*
** MANAGE LENGTH MODIFIER
*/
void	stock_content_lm(t_arg *param, char **content, void *to_stock);
void	special_case_lm(t_arg *param);

/*
** FLOAT
*/
char	*ftoa(long double nb, char *s, int precision);
int		flt_len(long double n);

/*
** TRANSFORM CHAIN
*/
void	transform_chain(t_arg **param);


/*
** DISPLAY CHAIN
*/
void	final_display(t_arg *param);

#endif
