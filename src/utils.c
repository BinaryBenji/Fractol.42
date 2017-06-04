/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzmuda <bzmuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 18:07:08 by bzmuda            #+#    #+#             */
/*   Updated: 2017/06/01 13:31:14 by bzmuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
**	Error case
*/

int		exiterror(void)
{
	ft_putstr_fd("error\n", 1);
	exit(-1);
}

int		error(void)
{
	ft_putstr_fd("error\n", 1);
	return (-1);
}

/*
**	Usage
*/

int		usage(void)
{
	ft_putstr_fd("usage: ./fractol [julia]/[mandelbrot]/[other] \n", 2);
	return (-1);
}
