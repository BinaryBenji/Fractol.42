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

// void	zoom(t_e *e)
// {
// 	// e->x2 = x;
// 	// e->y2 = y;
// 	// e->x1 = (x / e->zoom + e->x1) - ((e->zoom * 1.3) / 2);
// 	// e->x1 += ((e->zoom * 1.3) / 2) - (x / (e->zoom * 1.3));
// 	// e->y1 = (y / e->zoom + e->y1) - ((e->zoom * 1.3) / 2);
// 	// e->y1 += ((e->zoom * 1.3) / 2) - (y / (e->zoom * 1.3));
// 	// e->zoom *= 1.3;
// 	printf("%d\n", e->itmax);
// 	//e->itmax = e->itmax;
// 	printf("zoom");
// }

// void	dezoom(t_e *e)
// {
// 	// e->x1 = (e->x2 / e->zoom + e->x1) - ((e->zoom / 1.3) / 2);
// 	// e->x1 += ((e->zoom / 1.3) / 2) - (e->x2 / (e->zoom / 1.3));
// 	// e->y1 = (e->y2 / e->zoom + e->y1) - ((e->zoom / 1.3) / 2);
// 	// e->y1 += ((e->zoom / 1.3) / 2) - (e->y2 / (e->zoom / 1.3));
// 	// e->zoom /= 1.3;
// 	// e->it_max--;
// 	printf("%d\n", e->itmax);
// 	//e->itmax = e->itmax;
// 	printf("unzoom");
// }