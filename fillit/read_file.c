/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   read_file.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/30 14:41:57 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2018/11/06 18:41:52 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

char	*read_file(const int fd)
{
	char	*buf;
	char	*tmp;
	char	*file;
	int		rt;

	if (!(buf = ft_strnew(BUFF_SIZE + 1)))
		fillit_error();
	if (!(file = ft_strnew(546)))
		fillit_error();
	while ((rt = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[rt] = '\0';
		if (!(tmp = ft_strjoin(file, buf)))
			fillit_error();
		ft_strdel(&file);
		file = tmp;
	}
	free(buf);
	return (file);
}
