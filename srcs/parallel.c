/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paralel.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 20:06:52 by marvin            #+#    #+#             */
/*   Updated: 2025/01/26 20:06:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	z_init_x(t_data *data, int i, int j)
{
	if (j + 1 < data->base.ligne)
	{
		data->b.x = data->a.x + (data->scale * cosf((data->aglx
						* M_PI) / 180));
		data->b.y = data->a.y + (data->scale * sinf((data->aglx
						* M_PI) / 180));
		data->b.x = data->b.x + ((data->map[j + 1][i] - data->map[j][i])
				* ((data->scale * 1.5) / data->high) * cosf((
						data->aglz * M_PI) / 180));
		data->b.y = data->b.y + ((data->map[j + 1][i] - data->map[j][i])
				* ((data->scale * 1.5) / data->high) * (sinf((
							data->aglz * M_PI) / 180)));
		color_n_draw(data, i, j, 2);
		return (1);
	}
	return (0);
}

int	z_init_y(t_data *data, int i, int j)
{
	if (i + 1 < data->base.colonne)
	{
		data->b.x = data->a.x + (data->scale * cosf((data->agly
						* M_PI) / 180));
		data->b.y = data->a.y + (data->scale * sinf((data->agly
						* M_PI) / 180));
		data->b.x = data->b.x + ((data->map[j][i + 1] - data->map[j][i])
				* ((data->scale * 1.5) / data->high) * (cosf((
							data->aglz * M_PI) / 180)));
		data->b.y = data->b.y + ((data->map[j][i + 1] - data->map[j][i])
				* ((data->scale * 1.5) / data->high) * (sinf((
							data->aglz * M_PI) / 180)));
		color_n_draw(data, i, j, 1);
		return (1);
	}
	return (0);
}

void	put_on_screen_para(t_data *data, int i, int j, t_putbase base)
{
	while (j < data->base.ligne)
	{
		i = 0;
		while (i < data->base.colonne)
		{
			if (i == 0)
				data->a = base.firstraw;
			else
				data->a = base.preva;
			if (z_init_x(data, i, j) && i == 0)
				base.tmp = data->b;
			if (i == 0)
				data->a = base.firstraw;
			else
				data->a = base.preva;
			if (z_init_y(data, i, j))
				base.preva = data->b;
			i++;
		}
		j++;
		base.firstraw = base.tmp;
	}
}

int	mlx_put_para(t_data *data)
{
	t_putbase		base;
	int				i;
	int				j;

	j = 0;
	i = 0;
	create_image(data, data->win_width, data->win_height);
	base.firstraw.x = data->first.x + (data->map[j][i] * (data->scale
				/ data->high) * cosf((data->aglz * M_PI) / 180));
	base.firstraw.y = data->first.y + (data->map[j][i] * (data->scale
				/ data->high) * cosf((data->aglz * M_PI) / 180));
	base.preva = base.firstraw;
	base.tmp = base.firstraw;
	put_on_screen_para(data, i, j, base);
	if (data->intro)
		mlx_destroy_image(data->mlx, data->intro);
	data->intro = mlx_xpm_file_to_image(data->mlx, "srcs/intro.xpm",
			&data->intro_width, &data->intro_height);
	if (!data->intro)
		return (ft_putstr_fd("Error: Failed to load XPM image\n", 2), 0);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_put_image_to_window(data->mlx, data->win, data->intro, 0, 0);
	return (data->is_printing = 0, 0);
}
