/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/10 12:53:38 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/19 22:15:15 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../libft/libft.h"
#include <stdio.h>

char	*ft_return_rest(char *str)
{
	int		i;

	i = 0;
	if (ft_strchr(str, '\n'))
	{
		while (str[i] != '\n')
		{
			if (!(str[i]))
				return (NULL);
			i++;
		}
		if (*str == '\n')
			return (&str[i + 1]);
	}
	return (&str[i + 1]);
}

char	*ft_get_line(char *to_transform, char *rest)
{
	int		i;
	char	*tmp;

	if (ft_strchr(to_transform, '\n'))
	{
		i = ft_strlen(to_transform) - ft_strlen(ft_strchr(to_transform, '\n'));
		to_transform = ft_strsub(to_transform, 0, i);
		return (to_transform);
	}
	tmp = ft_strjoin(to_transform, rest);
	free(rest);
	rest = tmp;
	ft_bzero(to_transform, ft_strlen(to_transform));
	return (rest);
}

int		ft_read_and_get_rt(const int fd, char **line, char *rest)
{
	int		rt;
	char	buf[BUFF_SIZE + 1];
	char	*tmp;

	while ((rt = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[rt] = '\0';
		tmp = *line;
		*line = ft_strjoin(*line, buf);
		free(tmp);
		if (ft_strchr(*line, '\n'))
		{
			if (rest)
			{
				tmp = ft_strjoin(rest, *line);
				free(*line);
				*line = tmp;
			}
			break ;
		}
	}
	return (rt);
}

int		get_next_line(const int fd, char **line)
{
	static char		*rest[65536];
	int				rt;

	if (fd < 0 || line == NULL || !(*line = ft_strnew(0)) || (!(rest[fd]) &&
	!(rest[fd] = ft_strnew(0))))
			return (-1);
	if ((rt = ft_read_and_get_rt(fd, line, (rest[fd]))) == -1)
		return (-1);
	else if (rt > 0)
	{
		rest[fd] = ft_return_rest(*line);
		*line = ft_get_line(*line, rest[fd]);
		return (1);
	}
	else if (!rt && ft_strlen(rest[fd]))
	{
		*line = ft_get_line(rest[fd], *line);
		rest[fd] = ft_return_rest(rest[fd]);
		return (1);
	}
	else if (!rt && ft_strlen(*line))
		return (1);
	return (0);
}

/*int		main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int i;

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	i = 1;
	while (i == 1)
	{
		i = get_next_line(fd, &line);
	}
	close(fd);
}*/
