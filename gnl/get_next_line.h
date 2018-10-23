/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.h                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/10 12:51:08 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 11:42:01 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include "libft/includes/libft.h"

# define BUFF_SIZE 1

int		get_next_line(const int fd, char **line);

#endif
