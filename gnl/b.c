/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/10 12:53:38 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/17 19:28:46 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../libft/libft.h"
#include <stdio.h>

char	*ft_return_rest(char *str)
{
	int	i;

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
	int	i;

	if (ft_strchr(to_transform, '\n'))
	{
		i = ft_strlen(to_transform) - ft_strlen(ft_strchr(to_transform, '\n'));
		to_transform = ft_strsub(to_transform, 0, i);
			return (to_transform);
	}
	to_transform = ft_strjoin(to_transform, rest); // cas sans '\n'
	return (to_transform);
}

int		ft_read_and_get_rt(const int fd, char **line, char *rest)
{
	int		rt;
	char	*buf;

	if (!(buf = ft_strnew(BUFF_SIZE + 1)))
		return (-1);
	while ((rt = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[rt] = '\0';
		*line = ft_strjoin(*line, buf);
		if (ft_strchr(*line, '\n'))
		{
			if (rest)
				*line = ft_strjoin(rest, *line);
			break ;
		}
	}
	return (rt);
}

int		get_next_line(const int fd, char **line)
{
	static char		*rest = NULL;
	int				rt;

	if (!(*line = ft_strnew(0)))
		return (-1);
	rt = ft_read_and_get_rt(fd, line, rest);
	if (rt > 0)
	{
		//printf("|||A|||\n");
		//printf("rest = '%s' line = '%s'\n", rest, *line);
		rest = ft_return_rest(*line);
		*line = ft_get_line(*line, rest);
		//printf("|||||||\n");
		//printf("rest = '%s' line = '%s'\n", rest, *line);
		//printf("|||A|||\n\n");
	}
	else if (rt == 0 && ft_strlen(rest))
	{
		//printf("|||B|||\n");
		//printf("rest = '%s' line = '%s'\n", rest, *line);
		////*line = ft_strjoin(rest, *line);
		*line = ft_get_line(rest, *line);
		rest = ft_return_rest(rest);
		//printf("|||||||\n");
		//printf("rest = '%s' line = '%s'\n", rest, *line);
		//printf("|||B|||\n\n");
	}
	return (0);
}

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	get_next_line(fd, &line);
	printf("line = '%s'\n", line);
	get_next_line(fd, &line);
	printf("line = '%s'\n", line);
	get_next_line(fd, &line);
	printf("line = '%s'\n", line);
	get_next_line(fd, &line);
	printf("line = '%s'\n", line);
	get_next_line(fd, &line);
	printf("line = '%s'\n", line);
	get_next_line(fd, &line);
	printf("line = '%s'\n", line);
	get_next_line(fd, &line);
	printf("line = '%s'\n", line);
	get_next_line(fd, &line);
	printf("line = '%s'\n", line);
	get_next_line(fd, &line);
	close(fd);
	return (0);
}
