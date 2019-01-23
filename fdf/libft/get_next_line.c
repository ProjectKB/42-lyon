/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/23 11:42:57 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/15 14:22:54 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static char			*ft_return_rest(char *str)
{
	int		i;

	i = -1;
	if (ft_strchr(str, '\n'))
	{
		while (*str++ != '\n')
			;
		if (*str == '\n')
			return (&str[i + 1]);
	}
	return (&str[i + 1]);
}

static char			*ft_get_line(char *to_transform, char *rest)
{
	int		i;
	char	*tmp;

	i = 0;
	if (ft_strchr(to_transform, '\n'))
	{
		i = ft_strlen(to_transform) - ft_strlen(ft_strchr(to_transform, '\n'));
		if (!(to_transform = ft_strsub(to_transform, 0, i)))
			return (NULL);
		return (to_transform);
	}
	if (!(tmp = ft_strjoin(to_transform, rest)))
		return (NULL);
	ft_strdel(&rest);
	rest = tmp;
	ft_bzero(to_transform, ft_strlen(to_transform));
	return (rest);
}

static int			ft_read_and_get_rt(const int fd, char **line, char *rest)
{
	int		rt;
	char	buf[BUFF_SIZE + 1];
	char	*tmp;

	while ((rt = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[rt] = '\0';
		if (!(tmp = ft_strjoin(*line, buf)))
			return (-1);
		ft_strdel(line);
		*line = tmp;
		if (ft_strchr(*line, '\n'))
		{
			if (rest)
			{
				if (!(tmp = ft_strjoin(rest, *line)))
					return (-1);
				ft_strdel(line);
				*line = tmp;
			}
			break ;
		}
	}
	return (rt);
}

int					get_next_line(const int fd, char **line)
{
	static char		*rest[4864];
	int				rt;

	if (fd < 0 || fd > 4864 || !line || !(*line = ft_strnew(0)) ||
	(!(rest[fd]) && !(rest[fd] = "")) || BUFF_SIZE < 1)
		return (-1);
	if ((rt = ft_read_and_get_rt(fd, line, (rest[fd]))) == -1)
		return (-1);
	else if (rt > 0)
	{
		rest[fd] = ft_return_rest(*line);
		if (!(*line = ft_get_line(*line, rest[fd])))
			return (-1);
		return (1);
	}
	else if (!rt && ft_strlen(rest[fd]))
	{
		if (!(*line = ft_get_line(rest[fd], *line)))
			return (-1);
		rest[fd] = ft_return_rest(rest[fd]);
		return (1);
	}
	else if (!rt && ft_strlen(*line))
		return (1);
	return (0);
}
