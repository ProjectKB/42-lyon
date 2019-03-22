/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lem_in.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/14 12:54:22 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/22 15:46:09 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "../libft/includes/libft.h"
# include "color.h"
# include <fcntl.h>
# define TRUE	1
# define FALSE	0

typedef char bool;

typedef struct	s_pipe
{
	int p1;
	int	p2;
}				t_pipe;

typedef struct	s_matrix
{
	int	pipe1;
	int	pipe2;
	char	**tab;
	int		start_len;
	int		end_len;
	char	*visited;
}				t_matrix;

typedef struct s_line
{
	char *line;
	struct s_line	*next;
}				t_line;

typedef struct	s_bool
{
	bool	start;
	bool	end;
	bool	ants;
	bool	room;
	bool	pipe;
	bool	general;
}				t_bool;

typedef struct	s_room
{
	char			*name;
	int				x;
	int				y;
	int 			define;
	struct	s_room	*next;
}				t_room;

typedef struct	s_data
{
	int		ants_nb;
	int		room_nb;
	int		pipe_nb;
	int		line_nb;

	t_bool	b;
	t_line	*file;
	t_room	*start;
	t_room	*end;

	t_room	*room;
	t_matrix	matrix;
}				t_data;

/*
** ERROR && DEBUG
*/
void	display_error(t_data *data);
void	debug(t_data *data, int index);

/*
**	ALGO  algo_lemin.c
*/

void	bfs(t_data *data);

/*
**	IS_XXXX    find_is.c
**	fonction qui check si c'est une room/pipe/commande ..
*/
bool	is_room(t_data *data, char *line);
void	is_valid(t_data *data, char *line);
bool	is_pipe(t_data *data, char *line);
bool	is_command(t_data *data, char *line);

/*
**	PUT_IN STRUCTS
*/

void	parse_line(t_data *data, char **line);
void	put_command(t_data *data, char **line);
void	put_room(t_data *data, char *line);
void	put_line(t_data *data, char **line);
void	put_pipe(t_data *data, char **line);
bool	find_nopipe(t_data *data, char *line, int j);

/*
**	FREE
*/
void	lemin_free(t_data *data);

/*
**	UTILS
*/
void	print_line(t_line *file);
int		ft_atol(char *line);
int		to_malloc(int nb);
void	set_or_clear_bit(char *bit, int bit_nb, int mode);
bool	test_bit(char *bit, int bit_nb);
void	set_bit(char *bit, int bit_nb);
void	clear_bit(char *bit, int bit_nb);
#endif
