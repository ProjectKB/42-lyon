/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   length_modifier.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/06 17:55:49 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/12 00:21:21 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

void	di_l_m(t_arg *arg, char **content, void *to_stock)
{
	if (arg->l_m == hh)
		*content = precision_tr((ft_itoa((signed char)to_stock)), arg);
	else if (arg->l_m == h)
		*content = precision_tr((ft_itoa((signed short int)to_stock)), arg);
	else if (arg->l_m == l)
		*content = precision_tr((ft_itoa((long int)to_stock)), arg);
	else if (arg->l_m == ll)
		*content = precision_tr((ft_itoa((long long int)to_stock)), arg);
}

char	*oxbigx_l_m(t_arg *arg, char *content, void *to_stock, int base)
{
	if (arg->l_m == hh)
		content = precision_tr(
							ft_itoa_base((unsigned char)to_stock, base), arg);
	else if (arg->l_m == h)
		content = precision_tr(
						ft_itoa_base((unsigned short int)to_stock, base), arg);
	else if (arg->l_m == l)
		content = precision_tr(
						ft_itoa_base((unsigned long int)to_stock, base), arg);
	else if (arg->l_m == ll)
		content = precision_tr(
					ft_itoa_base((unsigned long long int)to_stock, base), arg);
	return (content);
}

void	u_l_m(t_arg *arg, char **content, void *to_stock)
{
	if (arg->l_m == hh)
		*content = precision_tr(ft_utoa((unsigned char)to_stock), arg);
	else if (arg->l_m == h)
		*content = precision_tr(ft_utoa((unsigned short int)to_stock), arg);
	else if (arg->l_m == l)
		*content = precision_tr(ft_utoa((unsigned long int)to_stock), arg);
	else if (arg->l_m == ll)
		*content = precision_tr(
							ft_utoa((unsigned long long int)to_stock), arg);
}

void	stock_content_lm(t_arg *arg, char **content, void *to_stock)
{
	free(arg->content);
	if (arg->c_i == di)
		di_l_m(arg, content, to_stock);
	else if (arg->c_i == o)
		*content = oxbigx_l_m(arg, *content, to_stock, 8);
	else if (arg->c_i == x)
		*content = oxbigx_l_m(arg, *content, to_stock, 16);
	else if (arg->c_i == X)
		*content = ft_strupcase(oxbigx_l_m(arg, *content, to_stock, 16));
	else if (arg->c_i == u)
		u_l_m(arg, content, to_stock);
}

void	special_case_lm(t_arg *arg)
{
	if (arg->c_i == p)
		arg->l_m = WOAW;
}
