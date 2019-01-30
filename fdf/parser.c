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
    param->x_max = ft_nb_nbr(line, ' ');
    while ((get_next_line(fd, &line)))
        count++;
    param->y_max = count + 1;
    close(fd);
    param->fact = (param->width - param->width / 6) / param->x_max;
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

t_coord     **calcul_iso(int **tab, t_param *param)
{
    int i;
    int j;
    int k;
    t_coord **coord_iso;

    i = 0;
    j = 0;
    k = 0;
    param->iso = 1;
    param->obl = 0;
    if (!(coord_iso = (t_coord**)malloc(sizeof(t_coord*) * (param->y_max))))
        return (NULL);
    if (!(param->color = (int**)malloc(sizeof(int*) * (param->y_max))))
        return (NULL);
    while (i < param->y_max)
    {
        while (j < param->x_max)
        {
            if (!j)
            {
                if (!(coord_iso[i] = (t_coord*)malloc(sizeof(t_coord) * (param->x_max))))
                    return (NULL);
                if (!(param->color[i] = (int*)malloc(sizeof(int) * (param->x_max * 2))))
                    return (NULL);
            }
            matrix(j, i, tab[i][j], param);
            coord_iso[i][k].x = 0.707f * (param->rot->xr_x - param->rot->xr_y);
            coord_iso[i][k].y = (param->z_iso * -param->rot->xr_z) - 0.408f * (param->rot->xr_x + param->rot->xr_y);
            param->color[i][k] = 255;
            //if (tab[i][j] == 10)
              //  param->color[i][k] = 10 * 900000;
            //printf("%d\n", tab[i][j]);
            k++;
            j++;
        }
        k = 0;
        j = 0;
        i++;
    }
    return (coord_iso);
}

t_coord     **calcul_obl(int **tab, t_param *param)
{
    int i;
    int j;
    int k;
    int t;
    t_coord **coord_obl;

    i = 0;
    j = 0;
    k = 0;

    param->iso = 0;
    param->obl = 1;
    if (!(coord_obl = (t_coord**)malloc(sizeof(t_coord*) * (param->y_max))))
        return (NULL);
    while (i < param->y_max)
    {
        while (j < param->x_max)
        {
            if (!j)
                if (!(coord_obl[i] = (t_coord*)malloc(sizeof(t_coord) * (param->x_max * 2))))
                    return (NULL);
            matrix(j, i, tab[i][j], param);
            coord_obl[i][k].x = param->rot->xr_x + param->rot->xr_z * param->z_obl;
            coord_obl[i][k].y = param->rot->xr_y + param->rot->xr_z * param->z_obl + param->move_h;
            k++;
            j++;
        }
        k = 0;
        j = 0;
        i++;
    }
    return (coord_obl);
}