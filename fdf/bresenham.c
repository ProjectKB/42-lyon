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

void	bresenham(t_coord start, t_coord end, t_param *param)
{
	double				n;
	int				i;
	double				step_x;
	double				step_y;
	double				pos_x;
	double				pos_y;
	double				t;
	double				u;
    int c_s;
    int c_e;
    int c_m;
    int test = 1;
    int q;

	i = -1;
	step_x = end.x - start.x;
	step_y = end.y - start.y;
    c_s = calcul_color(0, 0, 255);
    c_e = calcul_color(200, 200, 255);
    //printf("z1 : %d\nz2 : %d\n", start.z, end.z);
	
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
    q = n / (param->z_max - param->z_min);
	while (++i < n)
	{
		pos_x = start.x + i * step_x;
		pos_y = start.y + i * step_y;
        if (start.z == param->z_min && end.z == param->z_min)
            start.c = c_s;
        else if (start.z == param->z_max && end.z == param->z_max)
            start.c = c_e;
        else if (start.z > end.z)
            start.c = calcul_color(200 - test, 200 - test, 255);
        else if (start.z < end.z)
            start.c = calcul_color(0 + test, 0 + test, 255);
		if ((pos_x >= 0 && pos_x <= param->width) && (pos_y >= 0 && pos_y <= param->height))
			img_put_pixel(param, pos_x, pos_y, start.c);
        if (200 - test > 0)
            test++;
	}
}

void swap(double *a , double *b) 
{ 
    double temp = *a; 
    *a = *b; 
    *b = temp; 
} 

	float absolute(float x ) 
{ 
    if (x < 0) return -x; 
    else return x; 
} 
  
int iPartOfNumber(float x) 
{ 
    return (int)x; 
} 
  
int roundNumber(float x) 
{ 
    return iPartOfNumber(x + 0.5) ; 
} 
  
float fPartOfNumber(float x) 
{ 
    if (x>0) return x - iPartOfNumber(x); 
    else return x - (iPartOfNumber(x)+1); 
  
} 
  
float rfPartOfNumber(float x) 
{ 
    return 1 - fPartOfNumber(x); 
} 
  
void drawPixel( int x , int y , t_param *param) 
{ 
    img_put_pixel(param, x, y, 255);
} 

void	xiaolin(t_coord start, t_coord end, t_param *param) 
{ 
    int steep = absolute(end.y - start.y) > absolute(end.x - start.x) ; 
  
    if (steep) 
    { 
        swap(&start.x , &start.y); 
        swap(&end.x , &end.y); 
    } 
    if (start.x > end.x) 
    { 
        swap(&start.x ,&end.x); 
        swap(&start.y ,&end.y); 
    } 
  
	float dx = end.x - start.x;
	float dy = end.y - start.y;
    float gradient = dy/dx; 
    if (dx == 0.0) 
        gradient = 1; 
  
    int xpxl1 = start.x; 
    int xpxl2 = end.x; 
    float intersectY = start.y; 
  
    if (steep) 
    { 
        int x; 
        for (x = xpxl1 ; x <=xpxl2 ; x++) 
        { 
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
            drawPixel(x, iPartOfNumber(intersectY), param); 
            drawPixel(x, iPartOfNumber(intersectY)-1, param); 
            intersectY += gradient; 
        } 
    } 
  
}