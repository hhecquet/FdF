/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 13:55:57 by marvin            #+#    #+#             */
/*   Updated: 2025/01/25 13:55:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	key_handler(int keycode, t_data *data)
{
	if (data->is_printing == 1)
		return (0);
	else if (keycode == 105 || keycode == 112)
		isometric(data, keycode);
	else if (keycode == 99 || keycode == 118)
		high(keycode, data);
	else if (keycode == 102)
		free_view(data);
	else if (keycode == 65307)
		handle_error(NULL, data);
	else if (keycode == 65362 || keycode == 65364)
		move_up_down(keycode, data);
	else if (keycode == 65361 || keycode == 65363)
		move_left_right(keycode, data);
	else if (keycode == 61 || keycode == 45)
		zoom_in_out(keycode, data);
	else if (data->view.iso == 1)
		return (0);
	else if (keycode == 120 || keycode == 122)
		rot_x(keycode, data);
	else if (keycode == 115 || keycode == 97)
		rot_y(keycode, data);
	else if (keycode == 119 || keycode == 113)
		rot_z(keycode, data);
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

int	ft_chrcolor(int **map_color, t_data *data)
{
	int	i;
	int	j;

	j = 0;
	while (j < data->base.ligne)
	{
		i = 0;
		while (i < data->base.colonne)
		{
			if (map_color[j][i] != 0xFFFFFF)
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

void	rotate_point(t_point *p, float anglex, float angley, float anglez)
{
	t_rotate	point;

	point.radx = anglex * M_PI / 180;
	point.rady = angley * M_PI / 180;
	point.radz = anglez * M_PI / 180;
	point.x = p->x;
	point.y = p->y;
	point.z = p->z;
	point.y1 = point.y * cos(point.radx) - point.z * sin(point.radx);
	point.z1 = point.y * sin(point.radx) + point.z * cos(point.radx);
	point.y = point.y1;
	point.z = point.z1;
	point.x1 = point.x * cos(point.rady) + point.z * sin(point.rady);
	point.z1 = -point.x * sin(point.rady) + point.z * cos(point.rady);
	point.x = point.x1;
	point.z = point.z1;
	point.x1 = point.x * cos(point.radz) - point.y * sin(point.radz);
	point.y1 = point.x * sin(point.radz) + point.y * cos(point.radz);
	p->x = point.x1;
	p->y = point.y1;
	p->z = point.z;
}
