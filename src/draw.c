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

void	pix_to_img(t_e *e, int color)
{
	e->color = mlx_get_color_value(e->mlx, color);
	ft_memmove(e->imgstr + (4 * (e->width * e->y))
		+ (e->x * 4), &e->color, sizeof(int));
}

void	zoom(t_e *e, int x, int y)
{
	// printf("x : %d\n", x);
	// printf("y : %d\n", y);
	e->x2 = x;
	e->y2 = y;
	e->x1 = (x / e->zoom + e->x) - ((e->zoom * 1.25) / 2);
	e->y1 = (y / e->zoom + e->y) - ((e->zoom * 1.25) / 2);
	e->x1 += ((e->zoom * 1.25) / 2) - (x / (e->zoom * 1.25));
	// e->y1 = (y / e->zoom + e->y1) - ((e->zoom * 1.25) / 2);
	e->y1 += ((e->zoom * 1.25) / 2) - (y / (e->zoom * 1.25));
	// e->movex = x;
	// e->movey = y;
	e->zoom *= 1.25;
}

void	dezoom(t_e *e)
{
	e->x1 = (e->x2 / e->zoom + e->x1) - ((e->zoom / 1.25) / 2);
	e->x1 += ((e->zoom / 1.25) / 2) - (e->x2 / (e->zoom / 1.25));
	e->y1 = (e->y2 / e->zoom + e->y1) - ((e->zoom / 1.25) / 2);
	e->y1 += ((e->zoom / 1.25) / 2) - (e->y2 / (e->zoom / 1.25));
	e->zoom /= 1.25;
}