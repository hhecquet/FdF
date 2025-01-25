/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:42:03 by hhecquet          #+#    #+#             */
/*   Updated: 2025/01/16 10:59:40 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	move_up_down(int keycode, t_data *data)
{
	data->is_printing = 1;
	if (keycode == 65362)
	{
		data->first.y -= 10;
	}
	else
	{
		data->first.y += 10;
	}
	mlx_destroy_image(data->mlx, data->img);
	mlx_put_base(data);
}

void	move_left_right(int keycode, t_data *data)
{
	data->is_printing = 1;
	if (keycode == 65363)
	{
		data->first.x += 10;
	}
	else
	{
		data->first.x -= 10;
	}
	mlx_destroy_image(data->mlx, data->img);
	mlx_put_base(data);
}

void	zoom_in_out(int keycode, t_data *data)
{
	data->is_printing = 1;
	if (keycode == 61)
	{
		if (data->scale < 1500)
			data->scale *= 1.1;
	}
	else
	{
		if (data->scale > 0.01)
			data->scale /= 1.1;
	}
	mlx_destroy_image(data->mlx, data->img);
	mlx_put_base(data);
}

void	isometric(t_data *data, int keycode)
{
	if (keycode == 112)
	{
		paralelle(data);
		return ;
	}
	data->is_printing = 1;
	data->aglx = 0;
	data->agly = 0;
	data->aglz = 0;
	data->scale = 900 / fmin(data->base.ligne, data->base.colonne);
	data->first.x = 1110;
	data->first.y = 100;
	data->view.iso = 1;
	data->view.free = 0;
	mlx_destroy_image(data->mlx, data->img);
	mlx_put_base(data);
}

void	paralelle(t_data *data)
{
	data->is_printing = 1;
	data->aglx = 26;
	data->agly = 24;
	data->aglz = 18;
	data->scale = 900 / fmin(data->base.ligne, data->base.colonne);
	data->first.y = 120;
	data->first.x = 1280;
	data->view.iso = 1;
	data->view.free = 0;
	mlx_destroy_image(data->mlx, data->img);
	mlx_put_base(data);
}
