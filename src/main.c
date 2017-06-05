/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzmuda <bzmuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 11:09:52 by bzmuda            #+#    #+#             */
/*   Updated: 2017/06/05 11:09:53 by bzmuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void 	launch_draw(t_e *e)
{
	if (e->indexfrac == 1)
		draw_julia(e);
	else if (e->indexfrac == 2)
		draw_mandel(e);
	else
		printf("oth");
}

void 	ft_map(t_e *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, e->width, e->height, "Fractol");
	launch_draw(e);
	mlx_key_hook(e->win, key_pressed, NULL);
	mlx_loop(e->mlx);
}

t_e		init_map(t_e *e)
{
	e->x1 = -2.1;
	e->x2 = 2.6;
	e->y1 = -1.2;
	e->y2 = 1.2;
	e->itmax = 50;
	e->zoom = 100;
	e->color = 0xFFFFFF;
	e->width = 1200;
	e->height = 1200;
	e->img_x = (e->x2 - e->x1) * e->zoom;
	e->img_y = (e->y2 - e->y1) * e->zoom;
	return (*e);
}

int 	select_frac(t_e *e, char *param)
{
	if (ft_strcmp(param, "julia") == 0)
		e->indexfrac = 1;
	else if (ft_strcmp(param, "mandelbrot") == 0)
		e->indexfrac = 2;
	else if (ft_strcmp(param, "oth") == 0)
		e->indexfrac = 3;
	else
		return (0);
	return (1);
}

int 	main(int argc, char **argv)
{
	t_e e;

	if (argc != 2)
		return (usage());
	if (select_frac(&e, argv[1]) == 0)
		return (usage());
	init_map(&e);
	ft_map(&e);
	return (0);
}
