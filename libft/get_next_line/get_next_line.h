/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:23:34 by hhecquet          #+#    #+#             */
/*   Updated: 2025/01/10 09:03:14 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 69
# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../libft.h"

char	*get_next_line(int fd);
void	ft_free(char **tab, size_t i);
char	*join_buffer(char *basin_buffer, char *read_buffer);
char	*read_from_file(char *basin_buffer, int fd);
char	*extract_line(char *basin_buffer);
char	*ft_strrjoin(char const *s1, char const *s2);

#endif