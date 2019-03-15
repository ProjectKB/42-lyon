/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parser.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/14 13:40:11 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/14 15:46:02 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	parse_nb_lem(t_data *data, char *line)
{
	if ((data->lem_nb = ft_atoi(line)) < 1)
		display_error();
}

bool	is_comment(char *line)
{
	return (line[0] == '#' ? true : false);
}

bool	is_command(char *line)
{
	return (line[0] == '#' && line[1] == '#' ? true : false);
}

bool	is_room(char *line)
{
	int		i;
	bool	check;

	i = -1;
	check = false;
	while (line[++i])
	{
		if (line[i] == ' ')
			check = true;
		else if (check)
			;
	}
	return (check);
}

void	parse_line(t_data *data, char *line)
{
	static int	start = 0;

	if (!start && (start = 1))
		parse_nb_lem(data, line);
	else
	{
		if (is_command(line))
			;
		else if (is_comment(line))
			;
		else if (!ft_strchr(line, '-'))
			;
	}
}
