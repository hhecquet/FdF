/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:42:48 by marvin            #+#    #+#             */
/*   Updated: 2025/01/13 09:37:43 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	rot_x(int keycode, t_data *data)
{
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
	if (data->anglex == 360)
		data->anglex = 0;
	if (data->anglez == 360)
		data->anglez = 0;
	//mlx_clear_window(data->mlx, data->win);
	mlx_destroy_image(data->mlx, data->img);
	mlx_put_base(data);
}

void	rot_y(int keycode, t_data *data)
{
	if (keycode == 115)
	{
		data->angley += 2;
		data->anglez += 2;
	}
	else
	{
		data->angley -= 2;
		data->anglez -= 2;
	}
	if (data->angley == 360)
		data->angley = 0;
	if (data->anglez == 360)
		data->anglez = 0;
	//mlx_clear_window(data->mlx, data->win);
	mlx_destroy_image(data->mlx, data->img);
	mlx_put_base(data);
}

void	rot_z(int keycode, t_data *data)
{
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
	if (data->anglex == 360)
		data->anglex = 0;
	if (data->angley == 360)
		data->angley = 0;
	//mlx_clear_window(data->mlx, data->win);
	mlx_destroy_image(data->mlx, data->img);
	mlx_put_base(data);
}
