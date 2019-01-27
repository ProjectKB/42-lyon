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

double	ABS(double v)
{
	if (v < 0)
		v = -v;
	return (v);
}

void	bresenham(int x1, int y1, int x2, int y2, t_param *param)
{
	double				n;
	int				i;
	double				step_x;
	double				step_y;
	double				pos_x;
	double				pos_y;
	double				t;
	double				u;

	i = -1;
	step_x = x2 - x1;
	step_y = y2 - y1;
	
	t = ABS(step_x);
	u = ABS(step_y);
	if (t > u)
	{
		n = ABS(step_x);
		step_y /= ABS(step_x);
		step_x /= ABS(step_x);
	}
	else
	{
		n = ABS(step_y);
		step_x /= ABS(step_y);
		step_y /= ABS(step_y);
	}
	while (++i < n)
	{
		pos_x = x1 + i * step_x;
		pos_y = y1 + i * step_y;
		if ((pos_x >= 0 && pos_x <= param->width) && (pos_y >= 0 && pos_y <= param->height))
			mlx_pixel_put(param->mlx_ptr, param->win_ptr, pos_x, pos_y, 0xFFFFFF);
	}

	/*int dx;
	int dy;
	int e;
	dx = x2 - x1;
	dy = y2 - y1;
	if (dx)
	{
		if (dx > 0)
		{
			dy = y2 - y1;
			if (dy)
			{
				if (dy > 0) // vecteur oblique 1er cadran
				{
					if (dx >= dy) // vecteur diagonal ou oblique proche de l’horizontale, dans le 1er octant
					{
						e = dx;
						dx = e * 2;
						dy *= 2;
						while (1)
						{
							mlx_pixel_put(param->mlx_ptr, param->win_ptr, x1, y1, 0xFFFFFF);
							x1++;
							if (x1 == x2)
								break;
							e -= dy;
							if (e < 0)
							{
								y1 += 1;
								e += dx;
							}
						}
					}
					else // vecteur oblique proche de la verticale, dans le 2d octant
					{
						e = dy;
						dy = e * 2;
						dx *= 2;
						while (1)
						{
							mlx_pixel_put(param->mlx_ptr, param->win_ptr, x1, y1, 0xFFFFFF);
							y1++;
							if (y1 == y2)
								break;
							e -= dx;
							if (e < 0)
							{
								x1 += 1;
								e += dy;
							}
						}	
					}
				}

				else if (dy < 0 && dx > 0) // vecteur oblique dans le 4e cadran
				{
					if (dx >= -dy) // vecteur diagonal ou oblique proche de l’horizontale, dans le 8e octant
					{
						e = dx;
						dx = e * 2;
						dy *= 2;
						while (1)
						{
							mlx_pixel_put(param->mlx_ptr, param->win_ptr, x1, y1, 0xFFFFFF);
							x1++;
							if (x1 == x2)
								break;
							e += dy;
							if (e < 0)
							{
								y1 -= 1;
								e += dx;
							}
						}
					}
					else // vecteur oblique proche de la verticale, dans le 7e octant
					{
						e = dy;
						dy = e * 2;
						dx *= 2;
						while (1)
						{
							mlx_pixel_put(param->mlx_ptr, param->win_ptr, x1, y1, 0xFFFFFF);
							y1--;
							if (y1 == y2)
								break;
							e += dx;
							if (e > 0)
							{
								x1 += 1;
								e += dy;
							}
						}	
					}
				}
			}

			else if (dy == 0 && dx > 0) // // vecteur horizontal vers la droite
			{
				while (x1++ != x2)
				{
					mlx_pixel_put(param->mlx_ptr, param->win_ptr, x1, y1, 0xFFFFFF);	
				}
			}
		}


		else if (dx < 0)
		{
			dy = y2 - y1;
			if (dy)
			{
				if (dy > 0)
				{
					if (-dx >= dy) // vecteur oblique dans le 2d quadran
					{
						e = dx;
						dx = e * 2;
						dy *= 2;
						while (1)
						{
							mlx_pixel_put(param->mlx_ptr, param->win_ptr, x1, y1, 0xFFFFFF);
							x1--;	
							if (x1 == x2)
								break;
							e += dy;
							if (e >= 0)
							{
								y1 += 1;
								e += dx;
							}
						}
					}
					else
					{
						e = dy;
						dy = e * 2;
						dx *= 2;
						while (x1 > x2)
						{
							mlx_pixel_put(param->mlx_ptr, param->win_ptr, x1, y1, 0xFFFFFF);
							y1++;	
							//if (y1 == x2)
								//break;
							if ((e += dx) <= 0)
							{
								x1 -= 1;
								e += dy;
							}
						}
					}
				}
				else if (dy < 0 && dx < 0) // vecteur oblique dans le 3e cadran
				{
					if (dx <= dy) // vecteur diagonal ou oblique proche de l’horizontale, dans le 5e octant
					{
						e = dx;
						dx = e * 2;
						dy *= 2;
						while (1)
						{
							mlx_pixel_put(param->mlx_ptr, param->win_ptr, x1, y1, 0xFFFFFF);	
							x1--;
							if (x1 == x2)
								break;
							e -= dy;
							if (e >= 0)
							{
								y1 -= 1;
								e += dx;
							}
						}
					}
					else // vecteur oblique proche de la verticale, dans le 6e octant
					{
						e = dy;
						dy = e * 2;
						dx *= 2;
						while (1)
						{
							mlx_pixel_put(param->mlx_ptr, param->win_ptr, x1, y1, 0xFFFFFF);	
							y1--;
							if (y1 == y2)
								break;
							e -= dx;
							if (e >= 0)
							{
								x1 -= 1;
								e += dy;
							}
						}
					}
				}
			}
			else if (dy == 0 && dx < 0)
				while (x1-- != x2)
					mlx_pixel_put(param->mlx_ptr, param->win_ptr, x1, y1, 0xFFFFFF);	
		}
	}

	else if (dx == 0)
	{
		dy = y2 - y1;
		if (dy != 0)
		{
			if (dy > 0)
				while (y1++ != y2)
					mlx_pixel_put(param->mlx_ptr, param->win_ptr, x1, y1, 0xFFFFFF);	
			else if (dy < 0 && dx == 0)
				while (y1-- != y2)
					mlx_pixel_put(param->mlx_ptr, param->win_ptr, x1, y1, 0xFFFFFF);	
		}
	}*/
}

void swap(int *a , int *b) 
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 

	float absolute(float x ) 
{ 
    if (x < 0) return -x; 
    else return x; 
} 
  
//returns integer part of a floating point number 
int iPartOfNumber(float x) 
{ 
    return (int)x; 
} 
  
//rounds off a number 
int roundNumber(float x) 
{ 
    return iPartOfNumber(x + 0.5) ; 
} 
  
//returns fractional part of a number 
float fPartOfNumber(float x) 
{ 
    if (x>0) return x - iPartOfNumber(x); 
    else return x - (iPartOfNumber(x)+1); 
  
} 
  
//returns 1 - fractional part of number 
float rfPartOfNumber(float x) 
{ 
    return 1 - fPartOfNumber(x); 
} 
  
// draws a pixel on screen of given brightness 
// 0<=brightness<=1. We can use your own library 
// to draw on screen 
void drawPixel( int x , int y , t_param *param) 
{ 
    mlx_pixel_put(param->mlx_ptr, param->win_ptr, x, y, 0xFFFFFF);
} 

void	xiaolin(int x0, int y0, int x1, int y1, t_param *param) 
{ 
    int steep = absolute(y1 - y0) > absolute(x1 - x0) ; 
  
    // swap the co-ordinates if slope > 1 or we 
    // draw backwards 
    if (steep) 
    { 
        swap(&x0 , &y0); 
        swap(&x1 , &y1); 
    } 
    if (x0 > x1) 
    { 
        swap(&x0 ,&x1); 
        swap(&y0 ,&y1); 
    } 
  
    //compute the slope 
    float dx = x1-x0; 
    float dy = y1-y0; 
    float gradient = dy/dx; 
    if (dx == 0.0) 
        gradient = 1; 
  
    int xpxl1 = x0; 
    int xpxl2 = x1; 
    float intersectY = y0; 
  
    // main loop 
    if (steep) 
    { 
        int x; 
        for (x = xpxl1 ; x <=xpxl2 ; x++) 
        { 
            // pixel coverage is determined by fractional 
            // part of y co-ordinate 
            drawPixel(iPartOfNumber(intersectY), x, param); 
            drawPixel(iPartOfNumber(intersectY)-1, x, param); 
            intersectY += gradient; 
        } 
    } 
    else
    { 
        int x; 
        for (x = xpxl1 ; x <=xpxl2 ; x++) 
        { 
            // pixel coverage is determined by fractional 
            // part of y co-ordinate 
            drawPixel(x, iPartOfNumber(intersectY), param); 
            drawPixel(x, iPartOfNumber(intersectY)-1, param); 
            intersectY += gradient; 
        } 
    } 
  
}