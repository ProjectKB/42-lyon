/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/10 12:53:38 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/12 19:03:06 by loiberti    ###    #+. /#+    ###.fr     */
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
	return (&str[i + 1]);
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

char	*ft_read(const int fd)
{
	static int	rt = 0;
	static char	*rest = NULL;
	static char	*copy_rest = NULL;
	char		buf[BUFF_SIZE + 1];
	char		*str;

	if (!(str = (char*)malloc(sizeof(*str) * (BUFF_SIZE + 1))))
		return (NULL);
	while (!(ft_strchr(buf, '\n')))
	{
		rt = read(fd, buf, BUFF_SIZE);
		str = ft_strjoin(str, buf);
		buf[BUFF_SIZE] = '\0';
	}
	copy_rest = rest;
	rest = ft_return_rest(str);
	str = ft_transform_line(str, copy_rest);
	ft_putstr(str);
	return (str);
}

int	main(int argc, char **argv)
{
	int	fd;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	ft_read(fd);
	ft_read(fd);
	ft_putchar('\n');
	ft_read(fd);
	ft_putchar('\n');
	ft_read(fd);
	return (0);
}
