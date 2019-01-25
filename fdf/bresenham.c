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

/*void	bresenham(int x1, int y1, int x2, int y2, t_param *param)
{
	int dx;
	int dy;
	int e;

	dx = x2 - x1;
	dy = y2 - y1;

	if (dx)
	{
		if (dx > 0)
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
						if (x1++ == x2)
							break;
						if ((e -= dy) < 0)
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
						if (y1++ == y2)
							break;
						if ((e -= dx) < 0)
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
						if (x1++ == x2)
							break;
						if ((e += dy) < 0)
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
						if (y1-- == y2)
							break;
						if ((e += dx) > 0)
						{
							x1 += 1;
							e += dy;
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
			if ((dy = y2 - y1) != 0)
			{
				if (dy > 0 && -dx >= dy) // vecteur oblique dans le 2d quadran
				{
					e = dx;
					dx = e * 2;
					dy *= 2;
					while (1)
					{
						mlx_pixel_put(param->mlx_ptr, param->win_ptr, x1, y1, 0xFFFFFF);	
						if (x1-- == x2)
							break;
						if ((e += dy) > 0)
						{
							y1 += 1;
							e += dx;
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
							if (x1-- == x2)
								break;
							if ((e -= dy) >= 0)
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
							if (y1-- == y2)
								break;
							if ((e -= dx) >= 0)
							{
								x1 -= 1;
								e += dy;
							}
						}
					}
				}
				else if (dy == 0 && dx < 0)
					while (x1-- != x2)
						mlx_pixel_put(param->mlx_ptr, param->win_ptr, x1, y1, 0xFFFFFF);	
			}
		}
	}
	else if (dx == 0 && (dy = y2 - y1) != 0i)
	{
		if (dy > 0)
			while (y1++ != y2)
				mlx_pixel_put(param->mlx_ptr, param->win_ptr, x1, y1, 0xFFFFFF);	
		else if (dy < 0 && dx == 0)
			while (y1-- != y2)
				mlx_pixel_put(param->mlx_ptr, param->win_ptr, x1, y1, 0xFFFFFF);	
	}
}*/

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
void drawPixel( int x , int y , float brightness, t_param *param) 
{ 
    mlx_pixel_put(param->mlx_ptr, param->win_ptr, x, y, 0xFFFFFF);
} 
  
void	bresenham(int x0, int y0, int x1, int y1, t_param *param) 
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
            drawPixel(iPartOfNumber(intersectY), x, 
                        rfPartOfNumber(intersectY), param); 
            drawPixel(iPartOfNumber(intersectY)-1, x, 
                        fPartOfNumber(intersectY), param); 
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
            drawPixel(x, iPartOfNumber(intersectY), 
                        rfPartOfNumber(intersectY), param); 
            drawPixel(x, iPartOfNumber(intersectY)-1, 
                          fPartOfNumber(intersectY), param); 
            intersectY += gradient; 
        } 
    } 
  
}