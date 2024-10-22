/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:22:58 by igchurru          #+#    #+#             */
/*   Updated: 2024/10/22 14:53:40 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# define ISO_ANGLE 0.523599
# define ROTATE_ANGLE 0.087266463

# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "../MLX42/include/MLX42/MLX42.h"
# include "../MLX42/include/MLX42/MLX42_Int.h"

//  DOT STRUCTURE to store all dot coordinates, raw and processed.
typedef struct s_dot
{
	int				x;
	int				y;
	int				z;
	double			iso_x;
	double			iso_y;
	double			scaled_iso_x;
	double			scaled_iso_y;
	struct s_map	*map;
}	t_dot;

//	MAP STRUCTURE to store map general data. Also links with
//	the matrix, mlx, and img data structs.
typedef struct s_map
{
	int				map_rows;
	int				map_cols;
	double			min_x;
	double			max_x;
	double			min_y;
	double			max_y;
	int				scale;
	int				offset_x;
	int				offset_y;
	double			current_angle;
	double			center_x;
	double			center_y;
	int				total_dots;
	t_dot			**matrix;
	mlx_image_t		*img;
	mlx_t			*mlx;
}	t_map;

// LINE STRUCTURE to implement Bresenham's algorythm
typedef struct s_bresenham
{
	int				x0;
	int				y0;
	int				x1;
	int				y1;
	int				delta_x;
	int				delta_y;
	int				step_x;
	int				step_y;
	int				error;
}	t_bresenham;

//	MAIN.C
int		main(int argc, char **argv);

//	ERROR.C
void	error_exit(const char *error_message);
void	free_array(char **array);
void	free_matrix(t_dot **matrix, int i);

//	FIL_DE_FER.C
void	fil_de_fer(t_dot **matrix, t_map *map);
void	mlx_key_hook(mlx_t *mlx, mlx_keyfunc func, void *param);

//  PARSE_MAP.C
t_dot	**parse_map(char *argv1, t_map *map);
t_dot	**build_matrix(t_map *map);
void	populate_matrix(t_dot **matrix, char *route_to_map, t_map *map);

//	PREPROCESS_MATRIX.C
void	preprocess_matrix(t_dot **matrix, t_map *map);
void	scale_iso_coords(t_dot *dot, t_map *map);
void	calculate_iso_coords(t_dot *dot);

//	RENDER_MATRIX.C
void	render_matrix(mlx_image_t *img, t_dot **matrix, t_map *map);
void	scale_and_offset(t_dot **matrix, t_map *map, int w_width, int w_height);
void	preprocess_matrix(t_dot **matrix, t_map *map);
void	calculate_iso_coords(t_dot *dot);

//	RENDER_LINES.C
void	render_lines(mlx_image_t *img, t_dot **matrix, t_map *map);
void	draw_line(mlx_image_t *img, t_dot origin, t_dot target, uint32_t color);

//	BRESENHAM.C
void	init_bresenham(t_bresenham *b, t_dot origin, t_dot target);
void	determine_step_direction(int *step, int a, int b);
void	extract_coordinates(int *x, int *y, t_dot dot);
void	draw_step(t_bresenham *b);

//	MLX_KEY_HOOK.C
void	handle_key(mlx_key_data_t keydata, void *param);

//	ROTATE_MATRIX.C
void	manage_rotation(t_map *map, double angle);
void	rotate_matrix(t_map *map, double angle);
void	rotate_dot(t_dot *dot, double angle, double center_x, double center_y);

//  GET_NEXT_LINE.C
char	*get_next_line(int fd);
char	*ft_send_to_print(char *storage);
char	*ft_trim_storage(char *storage);

//	GET_NEXT_LINE_UTILS.C
void	*ft_gnl_calloc(size_t count, size_t size);
size_t	ft_gnl_strlen(const char *s);
char	*ft_gnl_strchr(const char *s, int c);
char	*ft_gnl_strjoin(char *storage, char *buffer);

#endif