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

int 	key_pressed(int keycode, t_e *e)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 37)
	{
		if (e->mov_juju == 1)
			e->mov_juju = 0;
		else
			e->mov_juju = 1;
	}
	if (keycode == 123 || keycode == 124 || keycode == 126 || keycode == 125)
	{
		if (keycode == 123)
			e->movex+=1;
		if (keycode == 124)
			e->movex-=1;
		if (keycode == 126)
			e->movey+=1;
		if (keycode == 125)
			e->movey-=1;
		launch_draw(e);
	}
	return (0);
}

/*
**	Mouse for julia
*/

int 	mouse_juju(int x, int y, t_e *e)
{
	if (e->mov_juju == 1)
	{
		e->c_r = (double)x / (double)(e->zoom / 2) +1;
	 	e->c_i = (double)y / (double)(e->zoom / 2) +1;
	    e->c_r*=0.0002;
	    e->c_i*=0.0002;
	    draw_julia(e);
	}
	return (0);
}

/*
**	Zoom (mouse)
*/

int		mouse_pressed(int mousecode, int x, int y,t_e *e)
{
	if (mousecode == 4 || mousecode == 1)
	{
		zoom(e,x,y);
		launch_draw(e);
	}
	else if (mousecode == 5 || mousecode == 2)
	{
		dezoom(e, x, y);
		launch_draw(e);
	}
	return (0);
}