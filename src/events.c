/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzmuda <bzmuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 11:09:17 by bzmuda            #+#    #+#             */
/*   Updated: 2017/06/05 11:09:22 by bzmuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


/*
**	"Main" function for events.
*/

int 	key_pressed(int keycode)
{
	if (keycode == 53)
		exit(0);
	return (0);
}

/*
**	Mouse for julia
*/

int 	mouse_juju(int x, int y, t_e *e)
{
	printf("x : %d\n", x);
	printf("y : %d\n", y);
	e->ix = (double)x / (double)(e->zoom / 2) - 1;
  	e->iy = (double)y / (double)(e->zoom / 2) - 1;
    e->ix*=0.0002;
    e->iy*=0.0002;
    e->ix++;
    e->iy++;
    draw_julia(e);
	return (0);
}

/*
**	Zoom (mouse)
*/

int		mouse_pressed(int mousecode, int x, int y, t_e e)
{
	// if (mousecode == 4 || mousecode == 1)
	// 	zoom(x, y, e);
	// else if (mousecode == 5 || mousecode == 2)
	// 	dezoom(e);
	printf("Mousecode : %d\n", mousecode);
	printf("x : %d\n", x);
	printf("y : %d\n", y);
	launch_draw(&e);
	return (0);
}

// int                mouse_julia(int x, int y, t_env *e)
// {
//     if (e->on == 1)
//     {
//         e->julx = (double)x / (double)(e->zoom / 2) - 1;
//         e->july = (double)y / (double)(e->zoom / 2) - 1;
//     }
//     ft_draw(e);
//     return (0);
// }