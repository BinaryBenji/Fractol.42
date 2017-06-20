#include "fractol.h"

/*
**	Initialize parameters for Tricorn fractal.
*/

void				init_tricorn(t_e *e)
{
	e->x1 = -3;
	e->x2 = 2.5;
	e->y1 = -2;
	e->y2 = 3;
	e->zoom = 259.37;
	e->itmax = 80;
	e->x = 0;
}

/*
**	Calculate, for each iterations
*/

void 	exten_tricorn(t_e *e)
{
	while (e->i < e->itmax)
	{
		e->tmp = e->z_r;
		e->z_r = e->z_r * e->z_r - e->z_i * e->z_i + e->cRe;
		e->z_i = -2 * e->z_i * e->tmp + e->cIm;
		if (e->z_r * e->z_r + e->z_i * e->z_i < 4)
			break;
		e->i++;
	}
}

/*
**	Create image of Tricorn fractal.
*/

void				draw_tricorn(t_e *e)
{
	while (e->y < e->height)
	{
		while (e->x < e->width)
		{
			e->cRe = e->x / e->zoom + e->x1;
			e->cIm = e->y / e->zoom + e->y1;
			e->z_r = 0;
			e->z_i = 0;
			e->i = 0;
			exten_tricorn(e);
			if (e->i == e->itmax)
				pix_to_img(e, e->i * 0);	
			else
				pix_to_img(e, (e->i * 150000));
			e->x++;
		}
		e->x = 0;
		e->y++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->imgptr, 0, 0);
}
