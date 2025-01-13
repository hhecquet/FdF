/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:29:03 by hhecquet          #+#    #+#             */
/*   Updated: 2025/01/13 09:04:09 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	key_handler(int keycode, t_data *data)
{
	if (keycode == 65307)
		handle_error(NULL, data);
	else if (keycode == 65362 || keycode == 65364)
		move_up_down(keycode, data);
	else if (keycode == 65361 || keycode == 65363)
		move_left_right(keycode, data);
	else if (keycode == 61 || keycode == 45)
		zoom_in_out(keycode, data);
	else if (keycode == 120 || keycode == 122)
		rot_x(keycode, data);
	else if (keycode == 115 || keycode == 97)
		rot_y(keycode, data);
	else if (keycode == 119 || keycode == 113)
		rot_z(keycode, data);
	else if (keycode == 105)
		isometric(data);
	else if (keycode == 112)
		paralelle(data);
	return (0);
}

void pixel_put(t_data *data)
{
    char    *pixel;
    int     bits_per_pixel;
    int     line_length;
    int     endian;

    pixel = mlx_get_data_addr(data->img, &bits_per_pixel, &line_length, &endian);
    pixel += (data->a.y * line_length + data->a.x * (bits_per_pixel / 8));
    *(int *)pixel = data->base.color;
}

void	mlx_put_line(void *mlx, void *win, t_data *data)
{
	double	dx;
	double	dy;
	double	step;
	double	x_increment;
	double	y_increment;

	dx = data->b.x - data->a.x;
	dy = data->b.y - data->a.y;
	step = fmax(fabs(dx), fabs(dy));
	if (step == 0)
		return ;
	x_increment = dx / step;
	y_increment = dy / step;
	while (step > 0)
	{
		pixel_put(data);
		data->a.x += x_increment;
		data->a.y += y_increment;
		step--;
	}
}

void	mlx_put_base(t_data *data)
{
	static t_point	init;
	static t_point	preva;
	static t_point	firstraw;
	int				i;
	int				j;

	j = 0;
	i = 0;
	init = data->first;
	preva.x = data->first.x + (data->map[j][0] * (data->scale / 10)
			* cos((data->anglez * M_PI) / 180));
	preva.y = data->first.y + (data->map[j][0] * (data->scale / 10)
			* sin((data->anglez * M_PI) / 180));
	firstraw = preva;
	while (j < data->base.ligne)
	{
		i = 0;
		while (i < data->base.colonne)
		{
			if (i == 0)
				data->a = firstraw;
			else
				data->a = preva;
			if (j + 1 < data->base.ligne)
			{
				data->b.x = init.x + (data->scale * cos((data->anglex
								* M_PI) / 180));
				data->b.y = init.y + (data->scale * sin((data->anglex
								* M_PI) / 180));
				data->b.x = data->b.x + (data->map[j + 1][i] * (data->scale
							/ 10) * cos((data->anglez * M_PI) / 180));
				data->b.y = data->b.y + (data->map[j + 1][i] * (data->scale
							/ 10) * sin((data->anglez * M_PI) / 180));
				if (data->map[j][i] > 0 || data->map[j + 1][i] > 0)
					data->base.color = 0xFF0000;
				else if (data->map[j][i] < 0 || data->map[j + 1][i] < 0)
					data->base.color = 0x0000FF;
				else
					data->base.color = 0xFFFFFF;
				if ((data->map[j][i] < 0 && data->map[j + 1][i] > 0)
						|| (data->map[j][i] > 0 && data->map[j][i + 1] < 0))
					data->base.color = 0xAA00FF;
				mlx_put_line(data->mlx, data->win, data);
			}
			if (i == 0)
				data->a = firstraw;
			else
				data->a = preva;
			if (i == 0)
				firstraw = data->b;
			if (i + 1 < data->base.colonne)
			{
				data->b.x = init.x + (data->scale * cos((data->angley * M_PI)
							/ 180));
				data->b.y = init.y + (data->scale * sin((data->angley * M_PI)
							/ 180));
				init = data->b;
				data->b.x = data->b.x + (data->map[j][i + 1] * (data->scale
							/ 10) * cos((data->anglez * M_PI) / 180));
				data->b.y = data->b.y + (data->map[j][i + 1] * (data->scale
							/ 10) * sin((data->anglez * M_PI) / 180));
				if (data->map[j][i] > 0 || data->map[j][i + 1] > 0)
					data->base.color = 0xFF0000;
				else if (data->map[j][i] < 0 || data->map[j][i + 1] < 0)
					data->base.color = 0x0000FF;
				else
					data->base.color = 0xFFFFFF;
				if ((data->map[j][i] < 0 && data->map[j][i + 1] > 0)
						|| (data->map[j][i] > 0 && data->map[j][i + 1] < 0))
					data->base.color = 0xAA00FF;
				mlx_put_line(data->mlx, data->win, data);
				preva = data->b;
			}
			i++;
		}
		j++;
		if (j < data->base.ligne)
		{
			init.x = firstraw.x - (data->map[j][i] * (data->scale / 10)
					* cos((data->anglez * M_PI) / 180));
			init.y = firstraw.y - (data->map[j][i] * (data->scale / 10)
					* sin((data->anglez * M_PI) / 180));
		}
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
	//data->img = mlx_xpm_file_to_image(data->mlx, "intro.xpm", &data->win_width, &data->win_height);
	//