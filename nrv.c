void	mlx_win_init(t_fractol *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, WIDTH, "Fractol");
	data->img = mlx_new_image(data->mlx, WIDTH, WIDTH);
	data->img_ptr = mlx_get_data_addr(data->img,
			&data->bpp, &data->sl, &data->endian);
}


t_fractol *data;

if (!(data = (t_fractol *)malloc(sizeof(t_fractol))))
return (-1);

int		mouse_julia(int x, int y, t_fractol *data)
{
	if (data->fract == 1 && data->julia_mouse == 1)
	{
		data->c_r = x * 2;
		data->c_i = y * 2 - 800;
		fract_calc(data);
	}
	return (0);
}

int			key_mouse_t(int key, int x, int y, t_env *e)
{
	double x_real;
	double y_real;

	if (y > 0)
	{
		x_real = (x / e->zoom) + e->x1;
		y_real = (y / e->zoom) + e->y1;
		if (key == 4)
		{
			e->zoom *= 1.1;
			e->x1 = x_real - (x / e->zoom);
			e->y1 = y_real - (y / e->zoom);
			key_redraw_tricorn(e);
		}
		if (key == 5)
		{
			e->zoom /= 1.1;
			e->x1 = x_real - (x / e->zoom);
			e->y1 = y_real - (y / e->zoom);
			key_redraw_tricorn(e);
		}
	}
	return (0);
}