/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/23 11:42:57 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/06 15:31:05 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

/*static char			*ft_return_rest(char *str)
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
	}*/

/*char    *free_join(char *dst, char *src)
{
	char    *tmp;

	tmp = dst;
	dst = ft_strjoin(dst, src);
	free(tmp);
	return (dst);
}

static void    sf_repos(char **str)
{
	void    *tmp;
	size_t    l;

	tmp = ft_strchr(*str, '\n');
	if (tmp == NULL)
	{
		ft_strclr(*str);
		return ;
	}
	tmp++;
	l = ft_strlen(tmp);
	ft_memcpy((void *)*str, tmp, l + 1);
}

static int    sf_save(char **line, int state)
{
	static char *str_save = NULL;
	char        *tmp;

	if (state)
	{
		if (str_save == NULL)
			return (0);
		if ((tmp = ft_strchr(str_save, '\n')) != NULL)
		{
			*tmp = '\0';
			*line = ft_strdup(str_save);
			*tmp = '\n';
		}
		else
			*line = ft_strdup(str_save);
		sf_repos(&str_save);
		return ((tmp != NULL) ? 1 : 2);
	}
	if (str_save != NULL)
		ft_strclr(str_save);
	tmp = ft_strchr(*line, '\n');
	ft_strdel(&str_save);
	str_save = ft_strdup(tmp + 1);
	*tmp = '\0';
	return (0);
}

static int    sf_finaltest(int ret, char **line, char *tmp)
{
	if (ret == -1)
		return (ret);
	if (ft_strchr(*line, '\n') != NULL)
	{
		sf_save(line, 0);
		ft_strdel(&tmp);
		return (1);
	}
	*line = free_join(*line, tmp);
	ft_strdel(&tmp);
	if (ft_strchr(*line, '\n') != NULL)
	{
		sf_save(line, 0);
		return (1);
	}
	if (!ft_strlen(*line))
		return (0);
	return (1);
}

int            get_next_line(const int fd, char **line)
{
	int        ret;
	char    *tmp;

	if (fd < 0 || line == NULL)
		return (-1);
	if ((ret = sf_save(line, 1)) == 1)
		return (1);
	else if (ret == 0)
		*line = ft_strnew(0);
	ret = BUFF_SIZE;
	tmp = ft_strnew(BUFF_SIZE);
	while ((ret = read(fd, tmp, BUFF_SIZE)) != 0)
	{
		if (ret == -1)
			return (-1);
		tmp[ret] = '\0';
		*line = free_join(*line, tmp);
		if (ft_strchr(tmp, '\n'))
			break ;
		ft_strclr(tmp);
	}
	return (sf_finaltest(ret, line, tmp));
}*/

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