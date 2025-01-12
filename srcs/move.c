/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:42:03 by hhecquet          #+#    #+#             */
/*   Updated: 2025/01/12 16:20:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	move_up_down(int keycode, t_data *data)
{
	if (keycode == 65362)
	{
		data->first.y -= 10;
	}
	else
	{
		data->first.y += 10;
	}
	mlx_clear_window(data->mlx, data->win);
	mlx_put_base(data);
}

void	move_left_right(int keycode, t_data *data)
{
	if (keycode == 65363)
	{
		data->first.x += 10;
	}
	else
	{
		data->first.x -= 10;
	}
	mlx_clear_window(data->mlx, data->win);
	mlx_put_base(data);
}

void	zoom_in_out(int keycode, t_data *data)
{
	if (keycode == 61)
	{
		if (data->scale < 230)
			data->scale *= 1.1;
	}
	else
	{
		if (data->scale > 0.01)
			data->scale /= 1.1;
	}
	mlx_clear_window(data->mlx, data->win);
	mlx_put_base(data);
}

void	isometric(t_data *data)
{
	data->anglex = 30;
	data->angley = 330;
	data->anglez = 270;
	data->anglefirst = 180;
	data->scale = 3.3 * fmax(data->base.ligne, data->base.colonne);
	data->first.x = 960 + (720 * cos((data->anglefirst * M_PI) / 180));
	data->first.y = 540 + (405 * sin((data->anglefirst * M_PI) / 180));
	mlx_clear_window(data->mlx, data->win);
	mlx_put_base(data);
}

void	paralelle(t_data *data)
{
	data->anglex = 45;
	data->angley = 0;
	data->anglez = 270;
	data->anglefirst = 210;
	data->scale = 3.3 * fmax(data->base.ligne, data->base.colonne);
	data->first.x = 960 + (750 * cos((data->anglefirst * M_PI) / 180));
	data->first.y = 540 + (500 * sin((data->anglefirst * M_PI) / 180));
	mlx_clear_window(data->mlx, data->win);
	mlx_put_base(data);
}
