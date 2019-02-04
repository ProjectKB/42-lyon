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

	i = -1;
	step_x = end.x - start.x;
	step_y = end.y - start.y;
	
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
		pos_x = start.x + i * step_x;
		pos_y = start.y + i * step_y;
		if ((pos_x >= 0 && pos_x <= param->width) && (pos_y >= 0 && pos_y <= param->height))
			img_put_pixel(param, pos_x, pos_y, start.c);
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
    img_put_pixel(param, x, y, 255);
} 

void	xiaolin(t_coord start, t_coord end, t_param *param) 
{ 
    int steep = absolute((param->midle + end.y * param->fact) - (param->midle + start.y * param->fact)) > absolute((param->midle + end.x * param->fact) - (param->midle + start.x * param->fact)) ; 
  
    // swap the co-ordinates if slope > 1 or we 
    // draw backwards 
    if (steep) 
    { 
        swap(&start.x , &start.y); 
        swap(&end.x , &end.y); 
    } 
    if ((param->midle + start.x * param->fact) > (param->midle + end.x * param->fact)) 
    { 
        swap(&start.x ,&end.x); 
        swap(&start.y ,&end.y); 
    } 
  
    //compute the slope 
	float dx = (param->midle + end.x * param->fact) - (param->midle + start.x * param->fact);
	float dy = (param->midle + end.y * param->fact) - (param->midle + start.y * param->fact);
    float gradient = dy/dx; 
    if (dx == 0.0) 
        gradient = 1; 
  
    int xpxl1 = (param->midle + start.x * param->fact); 
    int xpxl2 = (param->midle + end.x * param->fact); 
    float intersectY = (param->midle + start.y * param->fact); 
  
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