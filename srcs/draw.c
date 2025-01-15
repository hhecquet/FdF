/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:29:03 by hhecquet          #+#    #+#             */
/*   Updated: 2025/01/14 16:51:18 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	key_handler(int keycode, t_data *data)
{
	if (data->is_printing == 1)
		return (0);
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
	else if (keycode == 99 || keycode == 118)
		high(keycode, data);
	else if (keycode == 116)
		top (data);
	return (0);
}

void	pixel_put(t_data *data)
{
	char	*pixel;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

	pixel = mlx_get_data_addr(data->img, &bits_per_pixel, &line_length,
			&endian);
	pixel += ((int)data->a.y * line_length + (int)data->a.x
			* (bits_per_pixel / 8));
	*(int *)pixel = data->base.color;
}

void	mlx_put_line(t_data *data)
{
	float	dx;
	float	dy;
	float	step;
	float	x_increment;
	float	y_increment;

	dx = data->b.x - data->a.x;
	dy = data->b.y - data->a.y;
	step = fmax(fabs(dx), fabs(dy));
	if (step == 0)
		return ;
	x_increment = dx / step;
	y_increment = dy / step;
	while (step > 0)
	{
		if (data->a.x >= 0 && data->a.x < data->win_width
			&& data->a.y >= 0 && data->a.y < data->win_height)
			pixel_put(data);
		data->a.x += x_increment;
		data->a.y += y_increment;
		step--;
	}
}

void	mlx_put_base(t_data *data)
{
	static t_point	tmp;
	static t_point	preva;
	static t_point	firstraw;
	int				i;
	int				j;

	j = 0;
	i = 0;
	create_image(data, data->win_width, data->win_height);
	firstraw.x = data->first.x + (data->map[j][i] * (data->scale
				/ data->high) * cosf((data->anglez * M_PI) / 180));
	firstraw.y = data->first.y + (data->map[j][i] * (data->scale
				/ data->high) * cosf((data->anglez * M_PI) / 180));
	preva = firstraw;
	tmp = firstraw;
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
				data->b.x = data->a.x + (data->scale * cosf((data->anglex
								* M_PI) / 180));
				data->b.y = data->a.y + (data->scale * sinf((data->anglex
								* M_PI) / 180));
				data->b.x = data->b.x + ((data->map[j + 1][i] - data->map[j][i])
						* ((data->scale*data->scalez) / data->high) * cosf((data->anglez
								* M_PI) / 180));
				data->b.y = data->b.y + ((data->map[j + 1][i] - data->map[j][i])
						* ((data->scale*data->scalez) / data->high) * sinf((data->anglez
								* M_PI) / 180));
				if (i == 0)
					tmp = data->b;
				if (data->map[j][i] > 0 || data->map[j + 1][i] > 0)
					data->base.color = 0xF9036B;
				else if (data->map[j][i] < 0 || data->map[j + 1][i] < 0)
					data->base.color = 0xF7A2C6;
				else
					data->base.color = 0xFFFFFF;
				if ((data->map[j][i] < 0 && data->map[j + 1][i] > 0)
						|| (data->map[j][i] > 0 && data->map[j + 1][i] < 0))
					data->base.color = 0xFA599D;
				mlx_put_line(data);
			}
			if (i == 0)
				data->a = firstraw;
			else
				data->a = preva;
			if (i + 1 < data->base.colonne)
			{
				data->b.x = data->a.x + (data->scale * cosf((data->angley
								* M_PI) / 180));
				data->b.y = data->a.y + (data->scale * sinf((data->angley
								* M_PI) / 180));
				data->b.x = data->b.x + ((data->map[j][i + 1] - data->map[j][i])
						* ((data->scale*data->scalez) / data->high) * cosf((data->anglez
								* M_PI) / 180));
				data->b.y = data->b.y + ((data->map[j][i + 1] - data->map[j][i])
						* ((data->scale*data->scalez) / data->high) * sinf((data->anglez
								* M_PI) / 180));
				preva = data->b;
				if (data->map[j][i] > 0 || data->map[j][i + 1] > 0)
					data->base.color = 0xF9036B;
				else if (data->map[j][i] < 0 || data->map[j][i + 1] < 0)
					data->base.color = 0xF7A2C6;
				else
					data->base.color = 0xFFFFFF;
				if ((data->map[j][i] < 0 && data->map[j][i + 1] > 0)
						|| (data->map[j][i] > 0 && data->map[j][i + 1] < 0))
					data->base.color = 0xFA599D;
				mlx_put_line(data);
				preva = data->b;
			}
			i++;
		}
		j++;
		firstraw = tmp;
	}
	if (data->intro)
		mlx_destroy_image(data->mlx, data->intro);
	data->intro = mlx_xpm_file_to_image(data->mlx, "srcs/intro.xpm",
			&data->intro_width, &data->intro_height);
	if (!data->intro)
	{
		ft_printf("Error: Failed to load XPM image\n");
		return ;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_put_image_to_window(data->mlx, data->win, data->intro, 0, 0);
	data->is_printing = 0;
	printf("anglex = %ld\n", data->anglex);
	printf("angley = %ld\n", data->angley);
	printf("anglez = %ld\n", data->anglez);
	//printf("scalez = %f\n", data->scalez);
	//printf("scale = %f\n", data->scale);
	printf("scale*data->scalez = %f\n", data->scale*data->scalez);
}
//abs == 90 pour la rotate passer de 0 a 1