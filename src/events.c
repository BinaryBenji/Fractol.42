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
**	Main function for events.
*/

int 	key_pressed(int keycode, t_e *e)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 69)
	{
		e->itmax++;
		mlx_clear_window(e->mlx, e->win);
		launch_draw(e);
	}
	if (keycode == 78)
	{
		e->itmax--;
		mlx_clear_window(e->mlx, e->win);
		launch_draw(e);
	}
	return (0);
}
