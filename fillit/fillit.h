/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <loiberti@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/29 11:51:22 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/02 15:43:58 by loiberti    ###    #+. /#+    ###.fr     */
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

char	*ft_read_file(const int fd);
/*
** ERRORS:
*/
void	ft_check_global(char *file);
int		ft_check_tetriminos(char *file, char **s);
void	ft_check_errors(char *file, char**s);
/*
** PIECES:
*/
char	***ft_stock_pieces(char *file, char **s, int nb_pieces, char ***tab);
char	*ft_get_piece(const char *file, char *needle);
/*
** CANVA:
*/
char	**ft_create_canva(int nb, char ***tab);
int		ft_piece_to_canva(char ***canva, int width, int height, char **piece);
/*
** ALGORITHM:
*/
int		ft_occupied(char **canva, int height, int width, char **piece);
int		ft_exceed_canva(char **canva, int height, int width, char **piece);
int		ft_clean_canva(char ***canva, int height, int width, char **piece);
int		ft_resolve(char ***canva, char ***tab, int count, int position);
/*
** UTILITIES & DISPLAY:
*/
char	**ft_get_tetriminos(void);
void	ft_error(void);
int		ft_count_pieces(char *file);
char	***get_tab(int size);
void	ft_display_canva(char **canva);
/*
** !!!!!!!!!!!!!!!!!!!!DEEBUG!!!!!!!!!!!!!!!!!!!!!!!!!:
*/
void	ft_display(char ***tab);
void	ft_cool_display(char **canva);

#endif
