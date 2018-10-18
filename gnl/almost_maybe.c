/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/10 12:53:38 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/18 10:18:48 by loiberti    ###    #+. /#+    ###.fr     */
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
	rest = ft_strjoin(to_transform, rest); // case without line feed '\n'
	ft_bzero(to_transform, ft_strlen(to_transform));
	return (rest);
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
		return (1);
		//printf("|||||||\n");
		//printf("rest = '%s' line = '%s'\n", rest, *line);
		//printf("|||A|||\n\n");
	}
	else if (rt == 0 && ft_strlen(rest))
	{
		//printf("|||B|||\n");
		//printf("rest = '%s' line = '%s'\n", rest, *line);
		////*line = ft_strjoin(rest, *line);
		//printf("|||||||\n");
		*line = ft_get_line(rest, *line);
		//printf("rest = '%s' line = '%s'\n", rest, *line);
		rest = ft_return_rest(rest);
		//printf("|||||||\n");
		//printf("rest = '%s' line = '%s'\n", rest, *line);
		//printf("|||B|||\n\n");
		return (1);
	}
	else if (rt == 0 && ft_strlen(*line))
		return (1);
	return (0);
}

int		main(int argc, char **argv)
{
	int		fd;
	int		i;
	char	*line;

	i = 1;
	fd = open(argv[1], O_RDONLY);
	while (i == 1)
	{
		i = get_next_line(fd, &line);
		printf("rt = '%d' line = '%s'\n", i, line);
	}
	close(fd);
	/*i = get_next_line(fd, &line);
	printf("line = '%s' rt = '%d'\n", line, i);
	i = get_next_line(fd, &line);
	printf("line = '%s' rt = '%d'\n", line, i);
	i = get_next_line(fd, &line);
	printf("line = '%s' rt = '%d'\n", line, i);
	i = get_next_line(fd, &line);
	printf("line = '%s' rt = '%d'\n", line, i);
	i = get_next_line(fd, &line);
	printf("line = '%s' rt = '%d'\n", line, i);
	i = get_next_line(fd, &line);
	printf("line = '%s' rt = '%d'\n", line, i);
	i = get_next_line(fd, &line);
	printf("line = '%s' rt = '%d'\n", line, i);
	i = get_next_line(fd, &line);
	printf("line = '%s' rt = '%d'\n", line, i);
	i = get_next_line(fd, &line);
	printf("line = '%s' rt = '%d'\n", line, i);
	//printf("line = '%s'\n", line);*/
	return (0);
}
