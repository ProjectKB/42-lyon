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
#define PI

void    find_xy_max(char **argv, t_pmax *p_max)
{
    int     fd;
    int     test;
    int     count;
    char    *line;

    count = 0;
    fd = open(argv[1], O_RDONLY);
    get_next_line(fd, &line);
    p_max->x = ft_strlen(line) - ft_nb_char_occurs(line, ' ');
    while ((get_next_line(fd, &line)))
        count++;
    p_max->y = count + 1;
    close(fd);
}

int    *str_to_tabint(char *str, t_pmax *p_max)
{
    int j;
    int *tab;
    char **split;
    int i;
  
    j = -1;
    i = 0;
    if (!(tab = (int*)malloc(sizeof(*tab) * p_max->x)))
        return (NULL);
    split = ft_strsplit(str, ' ');
    while (split[++j])
        tab[i++] = ft_atoi(split[j]);
    return (tab);
}

int    **file_to_data(char **argv, t_pmax *p_max)
{
    int     **tab;
    char    *data;
    int     i;
    int     fd;

    i = 0;
    fd = open(argv[1], O_RDONLY);
    if (!(tab = (int**)malloc(sizeof(*tab) * p_max->y)))
        return (NULL);
    while (i < p_max->y)
    {
        get_next_line(fd, &data);
        tab[i] = str_to_tabint(data, p_max);
        i++;
    }
    close(fd);
    return (tab);
}

/*int     **calcul_xy_iso(int **tab, t_pmax *p_max)
{
    int i;
    int j;
    int k;
    double a;
    double b;
    double c;
    int **coord_iso;

    i = 0;
    j = 0;
    k = 0;
    a = 0.71;
    b = -0.41;
    c = 0.82;
    if (!(coord_iso = (int**)malloc(sizeof(int*) * (p_max->y))))
        return (NULL);
    while (i < p_max->y)
    {
        while (j < p_max->x)
        {
            if (!j)
                if (!(coord_iso[i] = (int*)malloc(sizeof(int) * (p_max->x * 2))))
                    return (NULL);
            coord_iso[i][k] = j;
            coord_iso[i][k + 1] = i;
            //coord_iso[i][k] = 500 + 30 * (cos(0) * j + sin(0) * i);
            //coord_iso[i][k + 1] = 500 + 30 * (sin(0) * (sin(0) * j - cos(0) * i) + cos(0) * tab[i][j]);
            //coord_iso[i][k] = 0 + 100 * (a * (j - i));
            //coord_iso[i][k + 1] = 0 + 100 * (b * (j + i) + c * tab[i][j]);
            k += 2;
            j++;
        }
        k = 0;
        j = 0;
        i++;
    }
    return (coord_iso);
}*/

double     **calcul_classic(int **tab, t_pmax *p_max)
{
    int i;
    int j;
    int k;
    double **coord_iso;
    t_point point;

    i = 0;
    j = 0;
    k = 0;
    if (!(coord_iso = (double**)malloc(sizeof(double*) * (p_max->y))))
        return (NULL);
    while (i < p_max->y)
    {
        while (j < p_max->x)
        {
            point.x = j;
            point.y = i;
            point.z = tab[i][j];
            if (!j)
                if (!(coord_iso[i] = (double*)malloc(sizeof(double) * (p_max->x * 2))))
                    return (NULL);
            //coord_iso[i][k] = j;
            //coord_iso[i][k + 1] = i;
            //coord_iso[i][k] = (double)j * (sqrt((double)2) / (double)2) - (double)i * (sqrt((double)2) / (double)2);
            //coord_iso[i][k + 1] = (double)-j * ((double)1 / sqrt((double)6)) - (double)i * ((double)1 / sqrt((double)6)) + (double)tab[i][j] * sqrt((double)2 / (double)3);
            //coord_iso[i][k] = j + tab[i][j] * 1;
            //coord_iso[i][k + 1] = i + tab[i][j] * 1;
            coord_iso[i][k] = 0.707f * (point.x - point.y);
            coord_iso[i][k + 1] = (sqrt(0.666f) * point.z) - 0.408f * (point.x + point.y);
            k += 2;
            j++;
        }
        k = 0;
        j = 0;
        i++;
    }
    return (coord_iso);
}