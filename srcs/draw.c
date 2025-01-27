/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:29:03 by hhecquet          #+#    #+#             */
/*   Updated: 2025/01/27 12:46:23 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	color_n_draw(t_data *data, int i, int j, int k)
{
	int	x;
	int	y;

	x = j;
	y = i;
	if (k == 1)
		y += 1;
	else
		x += 1;
	if (ft_chrcolor(data->map_color, data) == 1)
		data->base.color = data->map_color[j][i];
	else
	{
		if (data->map[j][i] > 0 || data->map[x][y] > 0)
			data->base.color = 0xF9036B;
		else if (data->map[j][i] < 0 || data->map[x][y] < 0)
			data->base.color = 0xF7A2C6;
		else
			data->base.color = 0xFFFFFF;
		if ((data->map[j][i] < 0 && data->map[x][y] > 0)
			|| (data->map[j][i] > 0 && data->map[x][y] < 0))
			data->base.color = 0xFA599D;
	}
	mlx_put_line(data);
}

t_point	point_init(t_data *data, t_point p, int i, int j)
{
	int	m;
	int	n;

	m = j;
	n = i;
	if (data->k == 1)
		n += 1;
	else
		m += 1;
	p.x = (n) * data->scale;
	p.y = m * data->scale;
	p.z = data->map[m][n] * data->z_scale;
	rotate_point(&p, data->aglx, data->agly,
		data->aglz);
	data->p_screen_next.x = data->x_offset + (p.x
			- p.y) * cos(data->angle);
	data->p_screen_next.y = data->y_offset + (p.x
			+ p.y) * sin(data->angle)
		- p.z;
	data->a.x = data->p_screen_current.x;
	data->a.y = data->p_screen_current.y;
	data->b.x = data->p_screen_next.x;
	data->b.y = data->p_screen_next.y;
	color_n_draw(data, i, j, data->k);
	return (p);
}

void	put_on_screen(t_data *data, int i, int j)
{
	while (j < data->base.ligne)
	{
		i = 0;
		while (i < data->base.colonne)
		{
			data->p_current.x = i * data->scale;
			data->p_current.y = j * data->scale;
			data->p_current.z = data->map[j][i] * data->z_scale;
			rotate_point(&data->p_current, data->aglx, data->agly, data->aglz);
			data->p_screen_current.x = data->x_offset + (data->p_current.x
					- data->p_current.y) * cos(data->angle);
			data->p_screen_current.y = data->y_offset + (data->p_current.x
					+ data->p_current.y) * sin(data->angle) - data->p_current.z;
			data->k = 1;
			if (i + 1 < data->base.colonne)
				data->p_next_col = point_init(data, data->p_next_col, i, j);
			data->k = 2;
			if (j + 1 < data->base.ligne)
				data->p_next_row = point_init(data, data->p_next_row, i, j);
			i++;
		}
		j++;
	}
}

void	mlx_put_base(t_data *data)
{
	int		i;
	int		j;

	data->z_scale = (data->scale / data->high) * 1.5;
	data->x_offset = data->first.x;
	data->y_offset = data->first.y;
	j = 0;
	i = 0;
	create_image(data, data->win_width, data->win_height);
	put_on_screen(data, i, j);
	if (data->intro)
		mlx_destroy_image(data->mlx, data->intro);
	data->intro = mlx_xpm_file_to_image(data->mlx, "srcs/intro.xpm",
			&data->intro_width, &data->intro_height);
	if (!data->intro)
	{
		ft_putstr_fd("Error: Failed to load XPM image\n", 2);
		return ;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_put_image_to_window(data->mlx, data->win, data->intro, 0, 0);
	data->is_printing = 0;
}
