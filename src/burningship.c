/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzmuda <bzmuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 11:56:23 by bzmuda            #+#    #+#             */
/*   Updated: 2017/06/25 11:56:25 by bzmuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
**	Initialize parameters for Burningship fractal.
*/

void	init_burn(t_e *e)
{
	e->width = 1600;
	e->height = 1000;
	e->x = 0;
	e->y = 0;
	e->i = 0;
	e->x1 = -5;
	e->x2 = 2.5;
	e->y1 = -3.25;
	e->y2 = 3;
	e->itmax = 19;
	e->zoom = 150;
	e->indexfrac = 4;
}

/*
**	Calculate, for each iterations.
*/

void	exten_burn(t_e *e)
{
	while (e->z_r * e->z_r + e->z_i * e->z_i < 4 && e->i < e->itmax)
	{
		e->tmp = e->z_r;
		e->z_r = fabs(e->z_r * e->z_r - e->z_i * e->z_i + e->c_r);
		e->z_i = fabs(2 * e->z_i * e->tmp + e->c_i);
		e->i++;
	}
}

/*
**	Create image of Burningship fractal.
*/

void	draw_burn(t_e *e)
{
	while (e->y < e->height)
	{
		while (e->x < e->width)
		{
			e->c_r = e->x / e->zoom + e->x1;
			e->c_i = e->y / e->zoom + e->y1;
			e->z_r = 0;
			e->z_i = 0;
			exten_burn(e);
			bfr_pix(e);
			e->i = 0;
			e->x++;
		}
		e->y++;
		e->x = 0;
	}
	e->x = 0;
	e->y = 0;
	mlx_put_image_to_window(e->mlx, e->win, e->imgptr, 0, 0);
}
