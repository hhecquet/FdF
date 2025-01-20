/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:42:48 by marvin            #+#    #+#             */
/*   Updated: 2025/01/16 13:36:19 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	scale_z(t_data *data, int keycode)
{
	if (keycode == 120)
	{
		if ((data->anglez > 270 && data->anglez < 360) || (data->anglez > 90 && data->anglez < 180))
			data->scalez -= 0.02;
		else
			data->scalez += 0.02;//ptit prob ici
	}
	else if (keycode == 122)
	{
		if ((data->anglez > 270 && data->anglez < 360) || (data->anglez > 90 && data->anglez < 180))
			data->scalez += 0.02;
		else
			data->scalez -= 0.02;
	}
	if (keycode == 97)
	{
		if ((data->anglez > 270 && data->anglez < 360) || (data->anglez > 90 && data->anglez < 180))
			data->scalez -= 0.02;
		else
			data->scalez += 0.02;//ptit prob ici
	}
	else if (keycode == 115)
	{
		if ((data->anglez > 270 && data->anglez < 360) || (data->anglez > 90 && data->anglez < 180))
			data->scalez += 0.02;
		else
			data->scalez -= 0.02;
	}
}

void	rot_x(int keycode, t_data *data)
{
	data->is_printing = 1;
	if (keycode == 120)
	{
		data->anglex += 2;
		data->anglez += 2;
	}
	else
	{
		data->anglex -= 2;
		data->anglez -= 2;
	}
	if (data->anglex > 360)
		data->anglex -= 360;
	if (data->anglez > 360)
		data->anglez -= 360;
	if (data->anglex < 0)
		data->anglex += 360;
	if (data->anglez < 0)
		data->anglez += 360;
	scale_z(data, keycode);
	mlx_destroy_image(data->mlx, data->img);
	mlx_put_base(data);
}

void	rot_y(int keycode, t_data *data)
{
	data->is_printing = 1;
	if (keycode == 115)
	{
		data->angley += 2;
		data->anglez -= 1;
	}
	else
	{
		data->angley -= 2;
		data->anglez += 1;
	}
	if (data->angley > 360)
		data->angley -= 360;
	if (data->anglez > 360)
		data->anglez -= 360;
	if (data->angley < 0)
		data->angley += 360;
	if (data->anglez < 0)
		data->anglez += 360;
	scale_z(data, keycode);
	mlx_destroy_image(data->mlx, data->img);
	mlx_put_base(data);
}

void	rot_z(int keycode, t_data *data)
{
	data->is_printing = 1;
	if (keycode == 119)
	{
		data->anglex += 2;
		data->angley += 2;
	}
	else
	{
		data->anglex -= 2;
		data->angley -= 2;
	}
	if (data->angley > 360)
		data->angley -= 360;
	if (data->anglex > 360)
		data->anglex -= 360;
	if (data->angley < 0)
		data->angley += 360;
	if (data->anglex < 0)
		data->anglex += 360;
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
	mlx_put_base(data);
}

void	free_view(t_data *data)
{
	data->is_printing = 1;
	data->anglex = 30;
	data->angley = 330;
	data->first.x = 400;
	data->anglez = 330;
	data->scale = 900 / fmax(data->base.ligne, data->base.colonne);
	data->scalez = 0;
	data->first.y = 580;
	data->view.iso = 0;
	data->view.free = 1;
	mlx_destroy_image(data->mlx, data->img);
	mlx_put_base(data);
}
