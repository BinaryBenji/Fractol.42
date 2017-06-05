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

int 	key_pressed(int keycode, t_e *e)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 126) // up
	{
		printf("Zoom In");
		e->zoom = e->zoom * 1.5;
	}
	if (keycode == 125) // down
	{
		printf("Zoom Out");
		e->zoom = e->zoom * 0.75;
	}
	return (0);
}
