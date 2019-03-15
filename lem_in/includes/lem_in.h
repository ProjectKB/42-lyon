/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lem_in.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/14 12:54:22 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/14 16:00:07 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LEM_IN_H

# define LEM_IN_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>

typedef struct	s_bool {
	bool	start;
	bool	end;
	bool	lem;
	bool	room;
	bool	pipe;
}				t_bool;

typedef struct	s_room {
	char			*name;
	int				x;
	int				y;
}				t_room;

typedef struct	s_pipe {
	char			*r1;
	char			*r2;
}				t_pipe;

typedef struct	s_data {
	int		lem_nb;
	int		room_nb;
	int		pipe_nb;
	t_bool	b;
	t_room	**room;
	t_pipe	**pipe;
}				t_data;

/*
** STRUCTS & LISTS
*/
void	init_struct(t_data *data);
void	add_room(t_room *room);
void	add_pipe(t_pipe *pipe);

/*
** ERROR
*/
void	display_error(void);

#endif
