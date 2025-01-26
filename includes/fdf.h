/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:29:55 by hhecquet          #+#    #+#             */
/*   Updated: 2025/01/16 13:43:15 by hhecquet         ###   ########.fr       */
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
	float		z;
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
	int		paralelle;
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
	float		aglx;
	float		agly;
	float		aglz;
	float		angle;
	int			is_printing;
	float		high;
	t_view		view;
	t_numpoint	base;
	t_point		first;
	t_point		a;
	t_point		b;
	float		z_scale;
	int			**map;
	int			**map_color;
	float		scale;
	int			win_width;
	int			win_height;
	t_point		p_current;
	t_point		p_next_col;
	t_point		p_next_row;
	t_point		p_screen_current;
	t_point		p_screen_next;
	int			k;
	float		x_offset;
	float		y_offset;
}	t_data;

typedef struct s_rotate
{
	float		radx;
	float		rady;
	float		radz;
	float		x;
	float		y;
	float		z;
	float		x1;
	float		y1;
	float		z1;
}	t_rotate;

typedef struct s_putbase
{
	t_point	tmp;
	t_point	preva;
	t_point	firstraw;
}	t_putbase;

void	mlx_put_line(t_data *data);
void	mlx_put_base(t_data *data);
int		key_handler(int keycode, t_data *data);
void	handle_error(const char *msg, t_data *data);
void	move_up_down(int keycode, t_data *data);
void	move_left_right(int keycode, t_data *data);
void	zoom_in_out(int keycode, t_data *data);
void	ft_free_int(int **tab, size_t i);
int		count_lines(char *argv);
int		a_to_i(char **split, int *map);
int		len_tab(char **tab);
int		**parser(char *argv, t_data *data);
void	rot_x(int keycode, t_data *data);
void	rot_y(int keycode, t_data *data);
void	rot_z(int keycode, t_data *data);
void	isometric(t_data *data, int keycode);
void	paralelle(t_data *data);
void	create_image(t_data *data, int win_width, int win_height);
void	high(int keycode, t_data *data);
void	free_view(t_data *data);
void	rotate_point(t_point *p, float anglex, float angley, float anglez);
int		ft_chrcolor(int **map_color, t_data *data);
void	pixel_put(t_data *data);
int		mlx_put_para(t_data *data);
void	color_n_draw(t_data *data, int i, int j, int k);

#endif