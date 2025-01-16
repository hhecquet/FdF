/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:56:27 by marvin            #+#    #+#             */
/*   Updated: 2025/01/16 14:52:13 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	**parser(char *argv, t_data *data)
{
	int		fd;
	char	*next_line;
	char	**split;

	data->map = malloc(sizeof(int *) * count_lines(argv));
	if (!data->map)
		handle_error("Error: Memory allocation failed.\n", data);
	fd = open(argv, O_RDONLY);
	if (fd < 0)
	{
		free(data->map);
		handle_error("Error: Memory allocation failed.\n", data);
	}
	next_line = get_next_line(fd);
	while (next_line != NULL)
	{
		split = ft_split(next_line, ' ');
		if (!split)
		{
			free(next_line);
			ft_free_int(data->map, data->base.ligne);
			handle_error("Error: Memory allocation failed.\n", data);
		}
		data->map[data->base.ligne] = malloc(sizeof(int) * (len_tab(split)
					+ 1));
		if (!data->map[data->base.ligne])
		{
			free(next_line);
			ft_free(split, len_tab(split));
			handle_error("Error: Memory allocation failed.\n", data);
		}
		data->base.colonne = a_to_i(split, data->map[data->base.ligne]);
		free(next_line);
		ft_free(split, len_tab(split));
		data->base.ligne++;
		next_line = get_next_line(fd);
	}
	close(fd);
	print_map(data->map, data->base.ligne, data->base.colonne);
	return (data->map);
}
