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

int	ft_atoi_base(const char *str, const char *base)
{
	int		i;
	int		nb;
	int		base_len;

	i = 0;
	nb = 0;
	base_len = ft_strlen(base);
	if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))
		i += 2;
	while (str[i] && ft_strchr(base, ft_toupper(str[i])))
	{
		nb = nb * base_len;
		if (ft_isdigit(str[i]))
			nb += str[i] - '0';
		else
			nb += ft_toupper(str[i]) - 'A' + 10;
		i++;
	}
	return (nb);
}

void	handle_free(int n, t_data *data, char *next_line, char **split)
{
	if (n == 1)
	{
		free(data->map);
		free(data->map_color);
		handle_error("Error: Memory allocation failed.\n", data);
	}
	if (n == 2)
	{
		free(next_line);
		ft_free_int(data->map, data->base.ligne);
		ft_free_int(data->map_color, data->base.ligne);
		handle_error("Error: Memory allocation failed.\n", data);
	}
	if (n == 3)
	{
		free(next_line);
		ft_free(split, len_tab(split));
		handle_error("Error: Memory allocation failed.\n", data);
	}
}

char	**short_cut(char **split, char *next_line, t_data *data, int i)
{
	char	*j;

	split = ft_split(next_line, ' ');
	if (!split)
		handle_free(2, data, next_line, NULL);
	data->map[data->base.ligne] = ft_calloc((len_tab(split) + 1),
			sizeof(int));
	if (!data->map[data->base.ligne])
		handle_free(3, data, next_line, NULL);
	data->map_color[data->base.ligne] = ft_calloc((len_tab(split) + 1),
			sizeof(int));
	if (!data->map_color[data->base.ligne])
		handle_free(3, data, next_line, split);
	i = 0;
	while (split[i] != NULL)
	{
		j = ft_strchr(split[i], ',');
		if (j)
			data->map_color[data->base.ligne][i] = ft_atoi_base(j
					+ 1, "0123456789ABCDEF");
		else
			data->map_color[data->base.ligne][i] = 0xFFFFFF;
		i++;
	}
	return (split);
}

int	**parser(char *argv, t_data *data)
{
	int		fd;
	char	*next_line;
	char	**split;
	int		i;

	i = 0;
	data->map = ft_calloc(count_lines(argv), sizeof(int *));
	data->map_color = ft_calloc(count_lines(argv), sizeof(int *));
	if (!data->map)
		handle_error("Error: Memory allocation failed.\n", data);
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		handle_free(1, data, NULL, NULL);
	next_line = get_next_line(fd);
	while (next_line != NULL)
	{
		split = short_cut(split, next_line, data, i);
		data->base.colonne = a_to_i(split, data->map[data->base.ligne]);
		free(next_line);
		ft_free(split, len_tab(split));
		data->base.ligne++;
		next_line = get_next_line(fd);
	}
	close(fd);
	return (data->map);
}
