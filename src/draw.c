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
