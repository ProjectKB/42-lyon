/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/10 12:53:38 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/13 13:55:09 by loiberti    ###    #+. /#+    ###.fr     */
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
	while (str[i] != '\n')
	{
		if (!(str[i]))
			return (NULL);
		i++;
	}
	return (&str[i]);
}

char	*ft_transform_line(char *str, char *rest)
{
	int			i;

	i = ft_strlen(str) - ft_strlen(ft_strchr(str, '\n'));
	str = ft_strsub(str, 0, i);
	if (rest)
		str = ft_strjoin(rest, str);
	return (str);
}

char	*ft_read(const int fd, char **line)
{
	static int	rt = 0;
	static char	*rest = NULL;
	char		*copy_rest;
	char		buf[BUFF_SIZE + 1];

	if (!(*line = ft_strnew(0)))
		return (NULL);
	while (!(ft_strchr(buf, '\n')) && (rt = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[rt] = '\0';
		*line = ft_strjoin(*line, buf);
	}
	if (rt > 0)
	{
		copy_rest = rest;
		rest = ft_return_rest(*line);
		*line = ft_transform_line(*line, copy_rest);
	}
	return (*line);
}

int	main(int argc, char **argv)
{
	int	fd;
	int	i;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	printf("%s", ft_read(fd, &line));
	printf("%s", ft_read(fd, &line));
	printf("%s", ft_read(fd, &line));
	printf("%s", ft_read(fd, &line));
	close(fd);
	return (0);
}
