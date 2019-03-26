/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lem_in.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/26 19:20:21 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/26 19:20:24 by loiberti    ###    #+. /#+    ###.fr     */
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

typedef struct	s_tabsoluce
{
	int	**tab;
	int	nb_soluce;
	int	*path_occur;
	int	*occur_i;
	int	*path_cost;
	int	**occur;
	int	*wrong_path;
}				t_tabsoluce;

typedef struct	s_soluce
{
	int	i;
	int	j;
	int	l;
	int	pos;
	int	len;
	int	*path;
}				t_soluce;

typedef	struct	s_info
{
	int		fd;
	int		line_nb;
	char	flags;
}				t_info;

typedef struct	s_pipe
{
	int p1;
	int	p2;
}				t_pipe;

typedef struct	s_matrix
{
	char	oriented;
	int		pipe1;
	int		pipe2;
	char	**tab;
	int		start_len;
	int		end_len;
	char	*visited;
}				t_matrix;

typedef struct	s_line
{
	char			*line;
	struct s_line	*next;
}				t_line;

typedef struct	s_booleen
{
	t_bool	start;
	t_bool	end;
	t_bool	ants;
	t_bool	room;
	t_bool	pipe;
	t_bool	general;
}				t_booleen;

typedef struct	s_room
{
	char			*name;
	int				x;
	int				y;
	struct s_room	*next;
}				t_room;

typedef struct	s_data
{
	int			ants_nb;
	int			room_nb;
	int			pipe_nb;

	t_booleen	b;
	t_line		*file;
	t_room		start;
	t_room		end;
	t_room		*room;
	t_room		**room2;
	t_matrix	matrix;
	t_tabsoluce	soluce;
	t_info		info;
}				t_data;

/*
** ERROR && DEBUG
*/
void	display_error(t_data *data, char index);
void	debug(t_data *data, int index);
void	lemin_info(t_data *data, char *str);

/*
**	ALGO  algo_lemin.c
*/
void	bfs(t_data *data);
void	put_soluce(t_data *data, int **file, int **nb_file);

/*
**	algo_queue.c
*/
void	queue_print(t_data *data, int *node, char index);
void	queue_del(int **node, int **node2);
int		queue_len(t_data *data, int *node);
int		queue_pop(t_data *data, int *node);
t_bool	queue_append(t_data *data, int *node, int add);
int		*queue_create(t_data *data);

/*
**	IS_XXXX    find_is.c
**	fonction qui check si c'est une room/pipe/commande ..
*/
t_bool	is_room(t_data *data, char *line);
void	is_valid(t_data *data, char *line);
t_bool	is_pipe(t_data *data, char **line);
t_bool	is_command(t_data *data, char *line);

/*
**	PUT_IN STRUCTS
*/
void	parse_line(t_data *data, char **line);
void	put_command(t_data *data, char **line);
void	put_room(t_data *data, char *line);
void	put_line(t_data *data, char **line);
void	put_pipe(t_data *data, char **line);
t_bool	find_nopipe(t_data *data, char **line, int j);

/*
**	FREE
*/
void	lemin_free(t_data *data);

/*
**	UTILS
*/
void	print_line(t_line *file);
char	*find_name(t_data *data, int nb);
int		ft_atol(char *line);
int		to_malloc(int nb);
void	set_or_clear_bit(char *bit, int bit_nb, int mode);
t_bool	test_bit(char *bit, int bit_nb);
void	set_bit(char *bit, int bit_nb);
void	clear_bit(char *bit, int bit_nb);
void	is_repeat(int **tab, int **occur, int sol_nb);
void	path_cost(int **tab, int **cost, int sol_nb);
int		tabintlen(int *tab);
int		count_occur(int *tab);
void	path_occur_i(int *tab, int **occur_i, int sol_nb);
void	set_occur_tab(int *path, int *ind, int ***occur);
void	wrong_path(int **occur, int **wrong_path, int limit);
#endif
