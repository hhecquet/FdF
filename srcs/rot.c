/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:42:48 by marvin            #+#    #+#             */
/*   Updated: 2025/01/27 13:09:41 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	rot_x(int keycode, t_data *data)
{
	data->is_printing = 1;
	if (keycode == 120)
		data->aglx += 2;
	else
		data->aglx -= 2;
	if (data->aglx >= 360)
		data->aglx -= 360;
	else if (data->aglx < 0)
		data->aglx += 360;
	mlx_destroy_image(data->mlx, data->img);
	mlx_put_base(data);
}

void	rot_y(int keycode, t_data *data)
{
	data->is_printing = 1;
	if (keycode == 115)
		data->agly += 2;
	else
		data->agly -= 2;
	if (data->agly >= 360)
		data->agly -= 360;
	else if (data->agly < 0)
		data->agly += 360;
	mlx_destroy_image(data->mlx, data->img);
	mlx_put_base(data);
}

void	rot_z(int keycode, t_data *data)
{
	data->is_printing = 1;
	if (keycode == 119)
		data->aglz += 2;
	else
		data->aglz -= 2;
	if (data->aglz >= 360)
		data->aglz -= 360;
	else if (data->aglz < 0)
		data->aglz += 360;
	mlx_destroy_image(data->mlx, data->img);
	mlx_put_base(data);
}

void	high(int keycode, t_data *data)
{
	data->is_printing = 1;
	if (keycode == 99)
	{
		if (data->high < 70)
			data->high += 0.2;
	}
	else
	{
		if (data->high > 0.4)
			data->high -= 0.2;
	}
	mlx_destroy_image(data->mlx, data->img);
	if (data->view.paralelle == 1)
		mlx_put_para(data);
	else
		mlx_put_base(data);
}

void	free_view(t_data *data)
{
	data->is_printing = 1;
	data->aglx = 0;
	data->agly = 0;
	data->aglz = 0;
	data->scale = 900 / fmax(data->base.ligne, data->base.colonne);
	data->first.x = 1110;
	data->first.y = 100;
	data->view.iso = 0;
	data->view.free = 1;
	data->view.paralelle = 0;
	data->angle = 30 * M_PI / 180;
	mlx_destroy_image(data->mlx, data->img);
	mlx_put_base(data);
}
