/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/13 22:45:32 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/13 23:55:59 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void    find_xy_max(char **argv, t_param *param)
{
    int     fd;
    int     test;
    int     count;
    char    *line;

    count = 0;
    fd = open(argv[1], O_RDONLY);
    get_next_line(fd, &line);
    param->x_max = ft_strlen(line) - ft_nb_char_occurs(line, ' ');
    while ((get_next_line(fd, &line)))
        count++;
    param->y_max = count + 1;
    close(fd);
}

int    *str_to_tabint(char *str, t_param *param)
{
    int j;
    int *tab;
    char **split;
    int i;
  
    j = -1;
    i = 0;
    if (!(tab = (int*)malloc(sizeof(*tab) * param->x_max)))
        return (NULL);
    split = ft_strsplit(str, ' ');
    while (split[++j])
        tab[i++] = ft_atoi(split[j]);
    return (tab);
}

int    **file_to_data(char **argv, t_param *param)
{
    int     **tab;
    char    *data;
    int     i;
    int     fd;

    i = 0;
    fd = open(argv[1], O_RDONLY);
    if (!(tab = (int**)malloc(sizeof(*tab) * param->y_max)))
        return (NULL);
    while (i < param->y_max)
    {
        get_next_line(fd, &data);
        tab[i] = str_to_tabint(data, param);
        i++;
    }
    close(fd);
    return (tab);
}

double     **calcul_iso(int **tab, t_param *param)
{
    int i;
    int j;
    int k;
    double **coord_iso;

    i = 0;
    j = 0;
    k = 0;
    param->iso = 1;
    param->obl = 0;
    if (!(coord_iso = (double**)malloc(sizeof(double*) * (param->y_max))))
        return (NULL);
    while (i < param->y_max)
    {
        while (j < param->x_max)
        {
            if (!j)
                if (!(coord_iso[i] = (double*)malloc(sizeof(double) * (param->x_max * 2))))
                    return (NULL);
            //coord_iso[i][k] = (double)j * (sqrt((double)2) / (double)2) - (double)i * (sqrt((double)2) / (double)2);
            //coord_iso[i][k + 1] = (double)-j * ((double)1 / sqrt((double)6)) - (double)i * ((double)1 / sqrt((double)6)) + (double)tab[i][j] * sqrt((double)2 / (double)3);
            coord_iso[i][k] = 0.707f * (j - i);
            coord_iso[i][k + 1] = (sqrt(0.666f) * -tab[i][j]) - 0.408f * (j + i);
            k += 2;
            j++;
        }
        k = 0;
        j = 0;
        i++;
    }
    return (coord_iso);
}

double     **calcul_obl(int **tab, t_param *param)
{
    int i;
    int j;
    int k;
    double **coord_obl;

    i = 0;
    j = 0;
    k = 0;
    param->iso = 0;
    param->obl = 1;
    if (!(coord_obl = (double**)malloc(sizeof(double*) * (param->y_max))))
        return (NULL);
    while (i < param->y_max)
    {
        while (j < param->x_max)
        {
            if (!j)
                if (!(coord_obl[i] = (double*)malloc(sizeof(double) * (param->x_max * 2))))
                    return (NULL);
            //coord_iso[i][k] = j;
            //coord_iso[i][k + 1] = i;
            coord_obl[i][k] = j + tab[i][j] * 1;
            coord_obl[i][k + 1] = i + tab[i][j] * 1;
            k += 2;
            j++;
        }
        k = 0;
        j = 0;
        i++;
    }
    return (coord_obl);
}