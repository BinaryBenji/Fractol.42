/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzmuda <bzmuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 10:27:58 by bzmuda            #+#    #+#             */
/*   Updated: 2017/06/21 10:28:01 by bzmuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	e->zoom = 1;
	e->itmax = 200;
	e->x = 0;
	e->y = 0;
	e->i = 0;
	e->z_r = 0;
	e->z_i = 0;
	e->width = 1000;
	e->height = 1000;
	e->indexfrac = 3;
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
		printf("calc : %f\n", e->cRe * e->cIm + e->z_i * e->z_i);
		if (e->cRe * e->cIm + e->z_i * e->z_i < 4)
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
			exten_tricorn(e);
			if (e->i == e->itmax)
				pix_to_img(e, e->i * 0);	
			else
				pix_to_img(e, (e->i * 150000));
			e->x++;
			e->i = 0;
			//e->z_r = 0;
			//e->z_i = 0;
		}
		e->x = 0;
		e->y++;
	}
	e->x = 0;
	e->y = 0;
	mlx_put_image_to_window(e->mlx, e->win, e->imgptr, 0, 0);
}
