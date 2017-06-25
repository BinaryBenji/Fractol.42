/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzmuda <bzmuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 11:09:29 by bzmuda            #+#    #+#             */
/*   Updated: 2017/06/05 11:09:31 by bzmuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
**	Initialize parameters for Julia fractal.
*/

void	init_julia(t_e *e)
{
	e->width = 1600;
	e->height = 1000;
	e->x = 0;
	e->y = 0;
	e->i = 0;
	e->x1 = -4;
	e->x2 = 2.5;
	e->y1 = -2.5;
	e->y2 = 3;
	e->c_r = -0.63;
	e->c_i = -0.54;
	e->itmax = 100;
	e->zoom = 200;
	e->indexfrac = 0;
	e->mov_juju = 1;
}

/*
**	Calculate, for each iterations
*/

void	exten_julia(t_e *e)
{
	while (e->z_r * e->z_r + e->z_i * e->z_i < 4 && e->i < e->itmax)
	{
		e->tmp = e->z_r;
		e->z_r = e->z_r * e->z_r - e->z_i * e->z_i + e->c_r;
		e->z_i = 2 * e->z_i * e->tmp + e->c_i;
		e->i++;
	}
}

/*
**	Create image of Julia fractal.
*/

void	draw_julia(t_e *e)
{
	while (e->y < e->height)
	{
		while (e->x < e->width)
		{
			e->c_r = e->c_r;
			e->c_i = e->c_i;
			e->z_r = e->x / e->zoom + e->x1;
			e->z_i = e->y / e->zoom + e->y1;
			exten_julia(e);
			bfr_pix(e);
			e->i = 50;
			e->x++;
		}
		e->y++;
		e->x = 0;
	}
	e->x = 0;
	e->y = 0;
	mlx_put_image_to_window(e->mlx, e->win, e->imgptr, 0, 0);
}
