/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:56:27 by marvin            #+#    #+#             */
/*   Updated: 2025/01/12 14:56:27 by marvin           ###   ########.fr       */
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
		exit(EXIT_FAILURE);
	fd = open(argv, O_RDONLY);
	if (fd < 0)
	{
		free(data->map);
		exit(EXIT_FAILURE);
	}
	next_line = get_next_line(fd);
	while (next_line != NULL)
	{
		split = ft_split(next_line, ' ');
		if (!split)
		{
			free(next_line);
			ft_free_int(data->map, data->base.ligne);
			exit(EXIT_FAILURE);
		}
		data->map[data->base.ligne] = malloc(sizeof(int) * (len_tab(split)
					+ 1));
		if (!data->map[data->base.ligne])
		{
			free(next_line);
			ft_free(split, len_tab(split));
			exit(EXIT_FAILURE);
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
