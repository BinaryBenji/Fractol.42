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

t_e		init_julia(t_e *e)
{
	e->width = 1000;
	e->height = 1000;
	e->cRe = -0.7;
	e->cIm = 0.27015;
	e->x = 0;
	e->y = 0;
	e->i = 0;
	e->zoom = 1;
	e->movex = 0;
	e->movey = 0;
	e->color = 0;
	e->itmax = 300;
	e->color = 0x00ffff;
	return (*e);
}


void 	draw_julia(t_e *e)
{
	while (e->y < e->height)
	{
		while (e->x < e->width)
		{
			e->newRe = 1.5 * (e->x - e->width / 2) / (0.5 * e->zoom * e->width) + e->movex;
			e->newIm = (e->y - e->height / 2) / (0.5 * e->zoom * e->height) + e->movey;
			while (e->i < e->itmax)
			{
				e->oldRe = e->newRe;
				e->oldIm = e->newIm;
				e->newRe = e->oldRe * e->oldRe - e->oldIm * e->oldIm + e->cRe;
				e->newIm = 2 * e->oldRe * e->oldIm + e->cIm;
				if((e->newRe * e->newRe + e->newIm * e->newIm) > 4)
					break;
				//e->color = HSVtoRGB(ColorHSV(e->i % 256, 255, 255 * (e->i < e->itmax)));
				e->i++;
			}
			e->i = 0;
			mlx_pixel_put(e->mlx, e->win, e->x, e->y, e->color);
			e->x++;
		}
		e->x = 0;
		e->y++;
	}
}