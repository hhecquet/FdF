/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:13:55 by marvin            #+#    #+#             */
/*   Updated: 2025/01/16 14:51:04 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	handle_error(const char *msg, t_data *data)
{
	if (msg)
		write(2, msg, ft_strlen(msg));
	if (data)
	{
		if (data->intro)
			mlx_destroy_image(data->mlx, data->intro);
		mlx_destroy_image(data->mlx, data->img);
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		ft_free_int(data->map, data->base.ligne);
		ft_free_int(data->map_color, data->base.ligne);
		free(data->mlx);
		free(data);
	}
	exit(EXIT_FAILURE);
}

void	create_image(t_data *data, int win_width, int win_height)
{
	data->img = mlx_new_image(data->mlx, win_width, win_height);
	if (!data->img)
		handle_error("Error: Image creation failed.\n", data);
	data->addr = mlx_get_data_addr(data->img, &data->bpp, &data->line_length,
			&data->endian);
	if (!data->addr)
		handle_error("Error: Failed to get image data address.\n", data);
}

int	close_window(t_data *data)
{
	handle_error("Window close event triggered. Exiting the application...\n",
		data);
	return (0);
}

void	data_init(t_data *data, char **argv)
{
	data->win_width = 1920;
	data->win_height = 1080;
	data->intro_width = 300;
	data->intro_height = 1080;
	data->mlx = mlx_init();
	if (!data->mlx)
		handle_error("Error: MiniLibX initialization failed->\n", data);
	data->base.ligne = 0;
	parser(argv[1], data);
	data->anglefirst = 180;
	data->scale = 900 / fmax(data->base.ligne, data->base.colonne);
	data->first.x = 400;
	data->first.y = 540;
	data->anglex = 30;
	data->angley = 330;
	data->anglez = 270;
	data->intro = 0;
	data->is_printing = 1;
	data->high = 10;
	data->scalez = 1;
	data->view.iso = 1;
	data->view.free = 0;
}
//data->first.x = 960 + (720 * cos((data->anglefirst * M_PI) / 180));
//data->first.y = 540 + (405 * sin((data->anglefirst * M_PI) / 180));

int	main(int argc, char **argv)
{
	int		fd;
	t_data	*data;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (ft_putstr_fd("File not found\n", 2), 1);
	else
		close(fd);
	data = (t_data *)ft_calloc(1, sizeof(t_data));
	if (!data)
		handle_error("Error: Memory allocation failed->\n", NULL);
	ft_putstr_fd("Loading please wait ... ⌛\n", 1);
	ft_putstr_fd("Larger maps may take longer to load 💭​\n\n", 1);
	data_init(data, argv);
	data->win = mlx_new_window(data->mlx, data->win_width, data->win_height,
			"FdF - 42 Project");
	if (!data->win)
		handle_error("Error: Window creation failed->\n", data);
	mlx_put_base(data);
	mlx_hook(data->win, 2, 1L << 0, key_handler, data);
	mlx_hook(data->win, 17, 0, close_window, data);
	mlx_loop(data->mlx);
	return (0);
}
