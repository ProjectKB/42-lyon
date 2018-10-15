/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.h                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/10 12:51:08 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/15 20:38:59 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/uio.h>
#include <fcntl.h>

# define GET_NEXT_LINE_H
# define BUFF_SIZE 5

int		get_next_line(const int fd, char **line);
char	*ft_transform_line(char *line);
int		ft_read(const int fd, char *buf, char **line, char *rest);

#endif
