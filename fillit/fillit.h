/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <loiberti@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/29 11:51:22 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/07 12:15:54 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLIT_H

# define FILLIT_H

# define BUFF_SIZE 32

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"

# ifndef GRAPHIC
#  define GRAPHIC 0
# endif

char			*read_file(const int fd);

/*
** STRUCT:
*/
typedef struct	s_init
{
	int			nb_pieces;
	int			canva_side_min;
	char		*file;
	char		**models;
	char		**canva;
	char		***init_tab;
}				t_init;

/*
** ERRORS:
*/
void			check_global(char *file);
int				check_tetriminos(char *file, char **s);
void			check_errors(char *file, char**s);
void			display_usage(int argc);

/*
** PIECES:
*/
char			***stock_pieces(char *file, char **s, int nb_pieces, \
																char ***tab);
char			*get_piece(const char *file, char *needle);

/*
** CANVA:
*/
char			**create_canva(int nb, int size);
int				piece_to_canva(char ***canva, int width, int height, \
																char **piece);

/*
** ALGORITHM:
*/
void			fillit(t_init *data, char ***tab);

/*
** UTILITIES:
*/
void			fillit_error(void);
char			**get_tetriminos(void);
int				count_pieces(char *file);
char			***get_tab(int size);
t_init			*init_vars(const int fd);
void			global_free(t_init *data, char ***tab);

/*
** DISPLAY:
*/
void			classic_display(char **canva);
void			display(char ***tab);
void			dynamic_display(char **canva);
void			crazy_display(char **canva);

#endif
