/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzmuda <bzmuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 11:09:39 by bzmuda            #+#    #+#             */
/*   Updated: 2017/06/05 11:09:43 by bzmuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "../libft/libft.h"
# include <fcntl.h>
# include "mlx.h"

typedef struct 		s_e
{
	void 			*mlx;
	void 			*win;
	double			cRe;
	double			cIm;
	int 			x;
	int 			y;
	int 			i;
	double			zoom;
	double 			movex;
	double 			movey;
	double			newRe;
	double			newIm;
	double			oldRe;
	double 			oldIm;
	double			pr;
	double			pi;
	int 			itmax;
	int				width;	
	int				height;
	unsigned long 	color;
	int 			indexfrac;
}			   		t_e;

void 				draw_mandel(t_e *e);
void 				ft_map(t_e *e);
int 				key_pressed(int keycode, t_e *e);
t_e					init_mandel(t_e *e);
t_e					init_julia(t_e *e);
int					exiterror(void);
int					error(void);
int					usage(void);
int 				select_frac(t_e *e, char *param);
void 				draw_julia(t_e *e);
t_e					reinit_mandel(t_e *e);
void 				launch_draw(t_e *e);
#endif
