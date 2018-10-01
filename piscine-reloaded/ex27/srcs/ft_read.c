/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_read.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/01 17:57:47 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/01 18:49:50 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/uio.h>
#include <fcntl.h>
#include <unistd.h>
#define BUFF_SIZE 4096

int	main(int argc, char **argv)
{
	int		fd;
	int		rt;
	char	buf[BUFF_SIZE + 1];

	if (argc == 1)
		ft_puterror("File name missing.");
	else if (argc > 2)
		ft_puterror("Too many arguments.");
	else
	{
		fd = open(argv[1], O_RDONLY);
		while ((rt = read(fd, buf, BUFF_SIZE)))
		{
			buf[rt] = '\0';
			ft_putstr(buf);
		}
		close(fd);
	}
	return (0);
}
