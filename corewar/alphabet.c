/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   alphabet.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/05 17:01:19 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/05 22:05:53 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_letter {
	int	l[25];
}				t_letter;

void	print_arena(unsigned char *arena)
{
	int	i;

	i = -1;
	while (++i < 4096)
	{
		if (!(i % 64))
			printf("\n");
		arena[i] ? printf("\033[34;01m%d\033[00m ", arena[i]) : printf("\033[34;02m%d\033[00m ", arena[i]);
	}
	printf("\n");
}

const t_letter	*get_alphabet(void)
{
	static const t_letter alphabet[25] = {
		{
			1, 1, 1, 1, 1,
			1, 0, 0, 0, 1,
			1, 1, 1, 1, 1,
			1, 0, 0, 0, 1,
			1, 0, 0, 0, 1
		},
		{
			1, 1, 1, 1, 1,
			1, 0, 0, 0, 1,
			1, 0, 1, 1, 0,
			1, 0, 0, 0, 1,
			1, 1, 1, 1, 1
		},
		{
			1, 1, 1, 1, 1,
			1, 0, 0, 0, 0,
			1, 0, 0, 0, 0,
			1, 0, 0, 0, 0,
			1, 1, 1, 1, 1
		},
		{
			1, 1, 1, 1, 0,
			1, 0, 0, 0, 1,
			1, 0, 0, 0, 1,
			1, 0, 0, 0, 1,
			1, 1, 1, 1, 0
		},
		{
			1, 1, 1, 1, 1,
			1, 0, 0, 0, 0,
			1, 1, 1, 0, 0,
			1, 0, 0, 0, 0,
			1, 1, 1, 1, 1
		},
		{
			1, 1, 1, 1, 1,
			1, 0, 0, 0, 0,
			1, 1, 1, 0, 0,
			1, 0, 0, 0, 0,
			1, 0, 0, 0, 0
		},
		{
			1, 1, 1, 1, 1,
			1, 0, 0, 0, 0,
			1, 0, 0, 1, 1,
			1, 0, 0, 0, 1,
			1, 1, 1, 1, 1
		},
		{
			1, 0, 0, 0, 1,
			1, 0, 0, 0, 1,
			1, 1, 1, 1, 1,
			1, 0, 0, 0, 1,
			1, 0, 0, 0, 1
		},
		{
			1, 1, 1, 1, 1,
			0, 0, 1, 0, 0,
			0, 0, 1, 0, 0,
			0, 0, 1, 0, 0,
			1, 1, 1, 1, 1
		},
		{
			1, 1, 1, 1, 1,
			0, 0, 1, 0, 0,
			0, 0, 1, 0, 0,
			1, 0, 1, 0, 0,
			1, 1, 1, 0, 0
		},
		{
			1, 0, 0, 0, 1,
			1, 0, 0, 1, 0,
			1, 1, 1, 0, 0,
			1, 0, 0, 1, 0,
			1, 0, 0, 0, 1
		},
		{
			1, 0, 0, 0, 0,
			1, 0, 0, 0, 0,
			1, 0, 0, 0, 0,
			1, 0, 0, 0, 0,
			1, 1, 1, 1, 1
		},
		{
			1, 0, 0, 0, 1,
			1, 1, 0, 1, 1,
			1, 0, 1, 0, 1,
			1, 0, 0, 0, 1,
			1, 0, 0, 0, 1
		},
		{
			1, 0, 0, 0, 1,
			1, 1, 0, 0, 1,
			1, 0, 1, 0, 1,
			1, 0, 0, 1, 1,
			1, 0, 0, 0, 1
		},
		{
			1, 1, 1, 1, 1,
			1, 0, 0, 0, 1,
			1, 0, 0, 0, 1,
			1, 0, 0, 0, 1,
			1, 1, 1, 1, 1
		},
		{
			1, 1, 1, 1, 1,
			1, 0, 0, 0, 1,
			1, 1, 1, 1, 1,
			1, 0, 0, 0, 0,
			1, 0, 0, 0, 0
		},
		{
			1, 1, 1, 1, 1,
			1, 0, 0, 0, 1,
			1, 0, 1, 1, 1,
			1, 0, 0, 1, 0,
			1, 0, 0, 0, 1
		},
		{
			1, 1, 1, 1, 1,
			1, 0, 0, 0, 0,
			1, 1, 1, 1, 1,
			0, 0, 0, 0, 1,
			1, 1, 1, 1, 1
		},
		{
			1, 1, 1, 1, 1,
			0, 0, 1, 0, 0,
			0, 0, 1, 0, 0,
			0, 0, 1, 0, 0,
			0, 0, 1, 0, 0
		},
		{
			1, 0, 0, 0, 1,
			1, 0, 0, 0, 1,
			1, 0, 0, 0, 1,
			1, 0, 0, 0, 1,
			1, 1, 1, 1, 1
		},
		{
			1, 0, 0, 0, 1,
			1, 0, 0, 0, 1,
			0, 1, 0, 1, 0,
			0, 1, 0, 1, 0,
			0, 0, 1, 0, 0
		},
		{
			1, 0, 0, 0, 1,
			1, 0, 0, 0, 1,
			1, 0, 1, 0, 1,
			1, 1, 0, 1, 1,
			1, 0, 0, 0, 1
		},
		{
			1, 0, 0, 0, 1,
			0, 1, 0, 1, 0,
			0, 0, 1, 0, 0,
			0, 1, 0, 1, 0,
			1, 0, 0, 0, 1
		},
		{
			1, 0, 0, 0, 1,
			1, 0, 0, 0, 1,
			0, 1, 0, 1, 0,
			0, 0, 1, 0, 0,
			0, 0, 1, 0, 0
		},
		{
			1, 1, 1, 1, 1,
			0, 1, 0, 0, 0,
			0, 0, 1, 0, 0,
			0, 0, 0, 1, 0,
			1, 1, 1, 1, 1
		}
	};
	return (alphabet);
}

int		count_word(char *str)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (str[++i])
		if (str[i + 1] == ' ' || !str[i + 1])
			count++;
	return (count);
}

void	print_letter(char letter, unsigned char *arena, const t_letter *alphabet, int *pos)
{
	int	i;
	int	j;
	int	line;
	int	pos_tmp;

	i = -1;
	letter < 'Q' ? letter -= 65 : (letter -= 66);
	line = 0;
	while (++i < 5 && (j = -1))
	{
		pos_tmp = *pos;
		while (++j < 5)
			arena[pos_tmp + j + (line * 64)] = alphabet[letter].l[j + (line * 5)];
		line++;
	}
	*pos += 6;
}

int		size_word(char *str, int s, int mod)
{
	int			size_word;
	int			size;

	size_word = 0;
	size = 0;
	while (str[s] && str[s] != ' ')
	{
		size++;
		s++;
	}
	size_word = (size * 5) + size - 1 + 3;
	return (!mod ? size : size_word);
}

void	print_word(char *word, unsigned char *arena, const t_letter *alphabet, int start, int w_start)
{
	int	w_size;
	int	len;
	int	i;

	i= -1;
	len = size_word(word, w_start, 0);
	printf("%d\n", len);
	while (++i < len)
		print_letter(word[w_start++], arena, alphabet, &start);
}


int	main(void)
{
	unsigned char	arena[4096];
	const t_letter *alphabet;
	int	i;

	i = -1;
	bzero(arena, 4096);
	alphabet = get_alphabet();
	print_word("CORE BLA", arena, alphabet, 0, 0);
	print_word("CORE BLA", arena, alphabet, 512, 5);
	//printf("%d\n", size_word("coucou", 0, 1));
	//printf("%d\n", size_word("coucou", 0, 0));
	print_arena(arena);
	return (0);
}
