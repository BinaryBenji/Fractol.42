#ifndef FRACTOL_H
# define FRACTOL_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "../libft/libft.h"
#include <fcntl.h>
#include "mlx.h"

typedef struct 		s_e
{
	void 			*mlx;
	void 			*win;
	double			x1;
	double 			x2;
	double			y1;
	double			y2; 
	double			itmax; 
	double			zoom; 
	double			img_x;
	double			img_y;
	double			c_i;
	double			c_r;
	double			z_r;
	double			z_i;
	double			i;
	int				width;	
	int				height;
	unsigned long 	color;
}			   		t_e;

void 	draw(t_e *e);
void 	ft_map(t_e *e);
int 	key_pressed(int keycode, t_e *e);
t_e		init_map(t_e *e);
int		exiterror(void);
int		error(void);
int		usage(void);
#endif