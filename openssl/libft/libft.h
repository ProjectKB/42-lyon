/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libft.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <loiberti@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 18:22:33 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/09 18:17:23 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H
# define BUFF_SIZE 1000

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

void				*ft_memset(void *b, int c, size_t len);
void				ft_putcolor(char *s, int type, int color);
void				ft_charcolor(char c, int type, int color);
void				ft_bzero(void *s, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				ft_sort_integer_table(int *tab, int size);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_strlen(const char *str);
int					ft_floatlen(long double nb);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strdup(const char *src);
char				*ft_strfdup(const char *src, char	*ptr_to_free);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
unsigned int		ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle,
		size_t len);
size_t				ft_recursive_power(int nb, int power);
long double			ft_recursive_npower(int power);
char				*ft_strupcase(char *str);
char				*ft_lowercase(char *str);
char				*ft_strcapitalize(char *str);
void				ft_swap(int *a, int *b);
char				*ft_strrev(char *str);
size_t				ft_utoi(const char *str);
int					ft_atoi(const char *str);
long long			ft_atoi_base(const char *str, int base);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strfsub(char *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strffulljoin(char const *s1, char const *s2);
char				*ft_strffjoin(char const *s1, char const *s2);
char				*ft_strfsjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(long long n);
char				*ft_utoa(size_t n);
char				*ft_itoa_base(unsigned long n, int base);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
char				*ft_double_to_binary_converter(double nb);
char				*ft_convert_binary_to_hexa(char *to_convert);
char	            *ft_strjoin2(void *s1, void *s2);

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					ft_check_char(const char *str, char c);

void				ft_freedbtab(void **tab);
void				ft_freedbint(void **tab, int y);
void				ft_putdbstr(char **dbstr, char c);
void				ft_putdbtab(void **dbtab, int y);
char				**ft_dbstrnew(int size);
char				ft_getchar();
char				*ft_charjoin(char *str, char c);
char				*ft_charrjoin(char *str, char c);
void				ft_remove_char_from_str(char **to_transform, char c);
void				ft_remove_one_char_from_str(char **to_transform, char c);
char				ft_nb_char_occur(char *str);
int					ft_nb_char_occurs(char *str, char c);
int					ft_is_hexa(char *str);
double				ft_get_rounder(int precision);
char				*ft_ftoa(long double nb, char *s, int precision);
int					get_next_line(const int fd, char **line);
void				ft_putdbint(int **dbint, int x, int y);
void				ft_debug(void);
int					ft_nb_nbr(char *str, char c);
double				ft_fabs(double v);
void				ft_fswap(double *a, double *b);
int					ft_ipart_of_numb(float x);
int					ft_round(float x);
float				ft_fpart_of_numb(float x);
float				ft_rfpart_of_numb(float x);
int					ft_find_char(char *str, char c);
int					ft_nb_char_occurs_c(char **tab, int x, int y_max, char c);
int					ft_find_char_c(char **tab, int x, int y_max, char c);

typedef enum		e_lm {
	WOAW,
	hh,
	h,
	l,
	ll,
	L
}					t_lm;

typedef enum		e_ci {
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
}					t_ci;

typedef struct		s_arg {
	struct s_arg	*next;
	char			*flag;
	char			*field;
	int				pre;
	t_lm			l_m;
	t_ci			c_i;
	char			*content;
	int				color;
}					t_arg;

/*
** LISTS TOOLS
*/
t_arg				*create_elem(void);
void				display_list_content(t_arg *list);
void				create_and_move_forward(t_arg **param);
void				free_list(t_arg *list);

/*
** FILL STRUCT
*/
int					stock_ordinary_char(char **str, char *format, int *i);
void				double_to_one_pourcent(char **str, int *i, char *format);
void				stock_flag(char **flag, char *format, int *i);
void				stock_field(char **field, char *format, int *i);
void				stock_precision(int *precision, char *format, int *i);
void				stock_length_modifier(t_lm *length_modifier, \
														char *format, int *i);
void				stock_conversion_indicator(t_ci *c_i, \
														char *format, int *i);
void				stock_arg_description(t_arg *param, char *format, int *i);
t_arg				*parse_string(const char *format);
void				stock_content(t_arg *param, char **content, \
															void *to_display);
void				parse_args(t_arg *param, ...);
void				stock_global_content(t_arg *arg, va_list va, \
															int *len_print);

/*
** MANAGE FLAG
*/
void				fix_impossible_comb(char **flag);
void				fix_impossible_flag(char **flag, t_ci c_i);
void				transform_flag(t_arg *param);
void				hash_tag_comportement(t_arg **param);
void				plus_comportement(t_arg **param);
void				aq_comportement(t_arg **param);
void				zero_comportement(t_arg **param);

/*
** MANAGE FIELD
*/
void				fill_field(char **field, t_arg *param);

/*
** MANAGE PRECISION
*/
char				*precision_tr(char *content, t_arg *param);

/*
** MANAGE LENGTH MODIFIER
*/
void				stock_content_lm(t_arg *param, char **content, \
															void *to_stock);
void				special_case_lm(t_arg *param);

/*
** FLOAT
*/
char				*ftoa(long double nb, char *s, int precision);
int					flt_len(long double n);

/*
** TRANSFORM CHAIN
*/
void				transform_chain(t_arg **param);

/*
** DISPLAY CHAIN
*/
void				final_display(t_arg *param);
char				*final_stock(t_arg *arg, char *str);
int					ft_printf(const char *format, ...);
char				*ft_sprintf(const char *format, ...);

#endif
