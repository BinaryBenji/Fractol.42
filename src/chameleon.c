/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chameleon.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzmuda <bzmuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 10:27:58 by bzmuda            #+#    #+#             */
/*   Updated: 2017/06/21 10:28:01 by bzmuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
**	Initialize parameters for Chameleon fractal.
*/

void				init_chameleon(t_e *e)
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
	e->c_r = 0.29;
	e->c_i = 0.02;
	e->itmax = 140;
	e->zoom = 200;	
	e->indexfrac = 3;
}

/*
**	Calculate, for each iterations
*/

void 	exten_chameleon(t_e *e)
{
	while (e->z_r * e->z_r + e->z_i * e->z_i < 4 && e->i < e->itmax)
	{
		e->tmp = e->z_r;
		e->z_r = e->z_r * e->z_r - e->z_i * e->z_i + e->c_r;
		e->z_i = -2 * e->z_i * e->tmp + e->c_i;
		e->i++;
	}
}

/*
**	Create image of Chameleon fractal.
*/

void				draw_chameleon(t_e *e)
{
	while (e->y < e->height)
	{		
		while (e->x < e->width)
		{
			e->c_r = e->c_r;
			e->c_i = e->c_i;
			e->z_r = e->x / e->zoom + e->x1;
			e->z_i = e->y / e->zoom + e->y1;
			exten_chameleon(e);
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
