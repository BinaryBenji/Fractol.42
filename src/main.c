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

/*
**	Draw the right fractal.
*/

void 	launch_draw(t_e *e)
{
	if (e->indexfrac == 1)
	{	
		draw_julia(e);
	}
	else if (e->indexfrac == 2)
	{
		draw_mandel(e);
	}
	else if (e->indexfrac == 3)
		printf("oth");
	else
		printf("incorrect");
}

/*
**	Drawing loop
*/

void 	ft_map(t_e *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, e->width, e->height, "Fractol");
	e->imgptr = mlx_new_image(e->mlx, e->width, e->height);
	e->imgstr = mlx_get_data_addr(e->imgptr, &(e->bpp), &(e->s_l), &(e->endian));
	launch_draw(e);
	mlx_key_hook(e->win, key_pressed, NULL);
	if (e->indexfrac == 1)
		mlx_hook(e->win, 6, 1L < 6, mouse_juju, e);
	mlx_loop(e->mlx);
}

/*
**	Verify params & store the good info
*/

int 	select_frac(t_e *e, char *param)
{
	if (ft_strcmp(param, "julia") == 0)
	{
		init_julia(e);
		e->indexfrac = 1;
	}
	else if (ft_strcmp(param, "mandelbrot") == 0)
	{
		init_mandel(e);
		e->indexfrac = 2;
	}
	else if (ft_strcmp(param, "oth") == 0)
	{
		e->indexfrac = 3;
	}
	else
		return (0);
	return (1);
}

/*
**	Main
*/

int 	main(int argc, char **argv)
{
	t_e e;

	if ((argc != 2) || (select_frac(&e, argv[1]) == 0))
		return (usage());
	ft_map(&e);
	return (0);
}
