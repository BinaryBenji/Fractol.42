#include "fractol.h"

int 	key_pressed(int keycode, t_e *e)
{
	if (keycode == 53) // quit
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

void 	draw(t_e *e)
{
	int x = 0;
	int y = 0;

	while (x < e->img_x)
	{
		while (y < e->img_y)
		{
			e->c_r = x / e->zoom + e->x1;
			e->c_i = y / e->zoom + e->y1;
			e->z_r = 0;
			e->z_i = 0;
			e->i = 0;
			while ((e->z_r*e->z_r - e->z_i*e->z_i < 4) && e->i < e->itmax)
			{
				int tmp = e->z_r;
				e->z_r = e->z_r * e->z_r - e->z_i * e->z_i + e->c_r;
				e->z_i = 2* e->z_i*tmp + e->c_i;
				e->i++;
			}
			if (e->i == e->itmax)
				mlx_pixel_put(e->mlx, e->win, x, y, e->color);
			else
				mlx_pixel_put(e->mlx, e->win, x, y, e->color);
			y++;
		}
		x++;
	}
}

void 	ft_map(t_e *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, e->width, e->height, "Fractol");
	draw(e);
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

int 	main(int argc, char **argv)
{
	t_e e;

	if (argc != 2)
		return (usage());
	argv[1] = argv[1];
	init_map(&e);
	ft_map(&e);
	return (0);
}
