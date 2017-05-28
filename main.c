#include "fractol.h"

int 	key_pressed(int keycode, void *mlx, void *win, t_env env)
{
	if (keycode == 53) // quit
		exit(0);
	if (keycode == 126) // up
	{
		printf("Zoom In");
		env.zoom = env.zoom * 1.5;
	}
	if (keycode == 125) // down
	{
		printf("Zoom Out");
		env.zoom = env.zoom * 0.75;
	}
	// mlx_clear_window(env.mlx, env.win);
	// draw(env);
	return (0);
}

void 	draw(t_env env)
{
	int x = 0;
	int y = 0;
	
	while (x < env.img_x)
	{
		while (y < env.img_y)
		{
			env.c_r = x / env.zoom + env.x1;
			env.c_i = y / env.zoom + env.y1;
			env.z_r = 0;
			env.z_i = 0;
			env.i = 0;
			while ((env.z_r*env.z_r - env.z_i*env.z_i < 4) && env.i < env.itmax)
			{
				int tmp = env.z_r;
				env.z_r = env.z_r * env.z_r - env.z_i * env.z_i + env.c_r;
				env.z_i = 2* env.z_i*tmp + env.c_i;
				env.i++;
			}
			if (env.i == env.itmax)
				mlx_pixel_put(env.mlx, env.win, x, y, 0xFFFFFF);
			else
				mlx_pixel_put(env.mlx, env.win, x, y, 0xFFE4E1);
			y++;
		}
		x++;
	}
}

void 	ft_map(t_env env)
{
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, 1000, 1000, "Fractol");

	draw(env);
	mlx_key_hook(env.win, key_pressed, NULL);
	//mlx_clear_window(env.mlx, env.win);
	mlx_loop(env.mlx);
}

t_env	init_map(t_env env)
{
	env.x1 = -2.1;
	env.x2 = 2.6;
	env.y1 = -1.2;
	env.y2 = 1.2;
	env.itmax = 50;
	env.zoom = 100;
	env.img_x = (env.x2 - env.x1) * env.zoom;
	env.img_y = (env.y2 - env.y1) * env.zoom;
	return (env);
}

int 	main ()
{
	t_env env;

	env = init_map(env);
	ft_map(env);
	return (0);
}