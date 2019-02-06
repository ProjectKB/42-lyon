/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/23 11:42:57 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/06 19:38:35 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	ft_read(const int fd, char **str)
{
	char	buf[BUFF_SIZE + 1];
	char	*test;
	int		x;

	if ((x = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[x] = '\0';
		test = ft_strdup(*str);
		ft_strdel(&(*str));
		*str = ft_strjoin(test, buf);
		ft_strdel(&test);
	}
	return (x);
}

static void	finish(char **str, char *last)
{
	char	*next;

	next = ft_strdup(last + 1);
	ft_strdel(&(*str));
	*str = ft_strdup(next);
	ft_strdel(&next);
}

int			get_next_line(const int fd, char **line)
{
	static char	*str[5000];
	char		*last;
	int			x;

	if (fd < 0 || fd > 2147483647 - 1 || line == NULL)
		return (-1);
	if (!str[fd])
		str[fd] = ft_strnew(1);
	while ((last = ft_strchr(str[fd], '\n')) == NULL)
	{
		if ((x = ft_read(fd, &str[fd])) < 0)
			return (-1);
		if (x == 0 && !last)
		{
			if (str[fd][0] == '\0')
				return (0);
			*line = ft_strdup(str[fd]);
			return (1);
		}
	}
	*line = ft_strsub(str[fd], 0, last - str[fd]);
	finish(&str[fd], last);
	return (1);
}
