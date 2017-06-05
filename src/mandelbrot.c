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

void 	draw_mandel(t_e *e)
{
	int x = 0;
	int y = 0;

	while (x < e->img_x)
	{
		while (y < e->img_y)
		{
			e->c_r = x / e->zoom + e->x1;
			e->c_i = y / e->zoom + e->y1;
			e->z_r = 0;
			e->z_i = 0;
			e->i = 0;
			while ((e->z_r*e->z_r - e->z_i*e->z_i < 4) && e->i < e->itmax)
			{
				int tmp = e->z_r;
				e->z_r = e->z_r * e->z_r - e->z_i * e->z_i + e->c_r;
				e->z_i = 2* e->z_i*tmp + e->c_i;
				e->i++;
			}
			if (e->i == e->itmax)
				mlx_pixel_put(e->mlx, e->win, x, y, e->color);
			else
				mlx_pixel_put(e->mlx, e->win, x, y, e->color);
			y++;
		}
		x++;
	}
}
