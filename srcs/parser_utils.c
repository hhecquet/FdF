/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:48:44 by marvin            #+#    #+#             */
/*   Updated: 2025/01/12 20:35:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int	len_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	return (i);
}

int	a_to_i(char **split, int *map)
{
	int	i;

	i = 0;
	while (split[i] != NULL)
	{
		map[i] = atoi(split[i]);
		i++;
	}
	map[i] = 0;
	return (i);
}

void	print_map(int **map, int lines, int colones)
{
	int	i;
	int	j;

	i = 0;
	while (i < lines)
	{
		j = 0;
		while (j < colones)
		{
			ft_printf("%d ", map[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

int	count_lines(char *argv)
{
	int		fd;
	char	*ret;
	int		nb_lines;

	nb_lines = 0;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		exit(EXIT_FAILURE);
	ret = get_next_line(fd);
	while (ret != NULL)
	{
		nb_lines++;
		free(ret);
		ret = get_next_line(fd);
	}
	close(fd);
	return (nb_lines);
}

void	ft_free_int(int **tab, size_t i)
{
	size_t	j;

	j = 0;
	while (j < i)
	{
		free(tab[j]);
		tab[j] = NULL;
		j++;
	}
	if (tab != NULL)
	{
		free(tab);
		tab = NULL;
	}
}
