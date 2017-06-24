/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzmuda <bzmuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 09:47:39 by bzmuda            #+#    #+#             */
/*   Updated: 2017/06/06 09:47:40 by bzmuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void 	bfr_pix(t_e *e)
{
	if (e->i == e->itmax)
		pix_to_img(e, 0);	
	else
		pix_to_img(e, (e->i * 1100000));
}

void	pix_to_img(t_e *e, int color)
{
	e->color = mlx_get_color_value(e->mlx, color);
	ft_memmove(e->imgstr + (4 * (e->width * e->y))
		+ (e->x * 4), &e->color, sizeof(int));
}

void	zoom(t_e *e, int x, int y)
{
	double x_n;
	double y_n;

	if (y > 0 && x > 0)
	{
		x_n = (x / e->zoom) + e->x1;
		y_n = (y / e->zoom) + e->y1;
		e->zoom *= 1.35;
		e->x1 = x_n - (x / e->zoom);
		e->y1 = y_n - (y / e->zoom);
		launch_draw(e);
	}
}

void	dezoom(t_e *e, int x, int y)
{
	double x_n;
	double y_n;

	x_n = (x / e->zoom) + e->x1;
	y_n = (y / e->zoom) + e->y1;
	e->zoom /= 1.35;
	e->x1 = x_n - (x / e->zoom);
	e->y1 = y_n - (y / e->zoom);
	launch_draw(e);
}