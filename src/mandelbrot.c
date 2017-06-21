/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzmuda <bzmuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 11:21:24 by bzmuda            #+#    #+#             */
/*   Updated: 2017/06/05 11:21:25 by bzmuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
**	Initialize parameters for Mandelbrot fractal.
*/

void		init_mandel(t_e *e)
{
	e->width = 1400;
	e->height = 1000;
	e->cRe = -0.7;
	e->cIm = 0.27015;
	e->x = 0;
	e->y = 0;
	e->i = 20;
	e->zoom = 0.2;
	e->movex = -0.5;
	e->movey = 0;
	e->itmax = 400;
	e->newRe = 0;
	e->oldRe = 0;
	e->newIm = 0;
	e->oldIm = 0;
	e->indexfrac = 2;
}

/*
**	Reinitialize real part & imaginary part to 0
*/

void		reinit_mandel(t_e *e)
{
	e->newRe = 0;
	e->oldRe = 0;
	e->newIm = 0;
	e->oldIm = 0;
}

/*
**	Calculate, for each iterations.
*/

void	exten_mandel(t_e *e)
{
	while (e->i < e->itmax)
	{
		e->oldRe = e->newRe;
		e->oldIm = e->newIm;
		e->newRe = e->oldRe * e->oldRe - e->oldIm * e->oldIm + e->pr;
		e->newIm = 2 * e->oldRe * e->oldIm + e->pi;
		if ((e->newRe * e->newRe + e->newIm * e->newIm) > 4)
			break;
		e->i++;
	}
}

/*
**	Create image of Mandelbrot fractal.
*/

void 	draw_mandel(t_e *e)
{
	while (e->y < e->height)
	{
		while (e->x < e->width)
		{
			e->pr = 1.5 * (e->x - e->width / 2) / (0.5 * e->zoom * e->width) + e->movex;
    		e->pi = (e->y - e->height / 2) / (0.5 * e->zoom * e->height) + e->movey;
    		reinit_mandel(e);
			exten_mandel(e);
			if (e->i == e->itmax)
				pix_to_img(e, e->i * 0);
			else
				pix_to_img(e, e->i * 20000000);
			e->x++;
			e->i = 20;
		}
		e->x = 0;
		e->y++;
	}
	e->x = 0;
	e->y = 0;
	mlx_put_image_to_window(e->mlx, e->win, e->imgptr, 0, 0);
}
