/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:29:55 by hhecquet          #+#    #+#             */
/*   Updated: 2025/01/16 10:59:00 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** FR msg - FR msg - FR msg
**
** La MinilibX utilise 2 librairies supplementaires qu'il
**      est necessaire de rajouter a la compilation :
**   -lmlx -lXext -lX11
**
** La MinilibX permet le chargement des images de type Xpm.
** Notez que cette implementation est incomplete.
** Merci de communiquer tout probleme de chargement d'image
** de ce type.
*/

#ifndef FDF_H
# define FDF_H

# ifndef M_PI
#  define M_PI 3.1415
# endif

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_point
{
	float		x;
	float		y;
	int			color;
}	t_point;

typedef struct s_numpoint
{
	int		ligne;
	int		colonne;
	int		color;
}	t_numpoint;

typedef struct s_view
{
	int		iso;
	int		free;
}	t_view;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	void		*intro;
	char		*img2;
	int			intro_width;
	int			intro_height;
	int			bpp;
	int			line_length;
	int			endian;
	long		anglex;
	long		angley;
	long		anglez;
	int			anglefirst;
	int			is_printing;
	float		high;
	float		scalez;
	float		scalex;
	float		scaley;
	t_view		view;
	t_point		a;
	t_point		b;
	t_numpoint	base;
	t_point		first;
	int			**map;
	float		scale;
	int			win_width;
	int			win_height;
}	t_data;

void	mlx_put_line(t_data *data);
void	mlx_put_base(t_data *data);
int		key_handler(int keycode, t_data *data);
void	handle_error(const char *msg, t_data *data);
void	move_up_down(int keycode, t_data *data);
void	move_left_right(int keycode, t_data *data);
void	zoom_in_out(int keycode, t_data *data);
void	ft_free_int(int **tab, size_t i);
int		count_lines(char *argv);
void	print_map(int **map, int lines, int colones);
int		a_to_i(char **split, int *map);
int		len_tab(char **tab);
int		**parser(char *argv, t_data *data);
void	rot_x(int keycode, t_data *data);
void	rot_y(int keycode, t_data *data);
void	rot_z(int keycode, t_data *data);
void	isometric(t_data *data);
void	paralelle(t_data *data);
void	create_image(t_data *data, int win_width, int win_height);
void	high(int keycode, t_data *data);
void	free_view(t_data *data);

#endif