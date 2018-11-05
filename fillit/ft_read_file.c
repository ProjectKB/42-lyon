/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_read_file.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/30 14:41:57 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/30 15:06:15 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_read_file(const int fd)
{
	char	*buf;
	char	*tmp;
	char	*file;
	int		rt;

	if (!(buf = ft_strnew(BUFF_SIZE + 1)))
		ft_error();
	if (!(file = ft_strnew(546)))
		ft_error();
	while ((rt = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[rt] = '\0';
		if (!(tmp = ft_strjoin(file, buf)))
			ft_error();
		ft_strdel(&file);
		file = tmp;
	}
	free(buf);
	return (file);
}
