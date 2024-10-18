/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:03:31 by igchurru          #+#    #+#             */
/*   Updated: 2024/10/18 10:05:50 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../MLX42/include/MLX42/MLX42.h"

void	scale_iso_coords(t_dot *dot, t_map *map)
{
	dot->scaled_iso_x = dot->iso_x * map->scale + map->offset_x;
	dot->scaled_iso_y = dot->iso_y * map->scale + map->offset_y;
}

void	calculate_iso_coords(t_dot *dot)
{
	dot->iso_x = (dot->x - dot->y) * cos(ISO_ANGLE);
	dot->iso_y = (dot->x + dot->y) * sin(ISO_ANGLE) - dot->z;
}

void	calculate_iso_bounds(t_dot **matrix, t_map *map)
{
	int	i;
	int	j;

	map->min_x = matrix[0][0].iso_x;
	map->max_x = matrix[0][0].iso_x;
	map->min_y = matrix[0][0].iso_y;
	map->max_y = matrix[0][0].iso_y;
	i = 0;
	while (i < map->map_rows)
	{
		j = 0;
		while (j < map->map_cols)
		{
			if (matrix[i][j].iso_x < map->min_x)
				map->min_x = matrix[i][j].iso_x;
			if (matrix[i][j].iso_x > map->max_x)
				map->max_x = matrix[i][j].iso_x;
			if (matrix[i][j].iso_y < map->min_y)
				map->min_y = matrix[i][j].iso_y;
			if (matrix[i][j].iso_y > map->max_y)
				map->max_y = matrix[i][j].iso_y;
			j++;
		}
		i++;
	}
}

void	scale_and_offset(t_dot **matrix, t_map *map, int w_width, int w_height)
{
	double	iso_width;
	double	iso_height;

	calculate_iso_bounds(matrix, map);
	iso_width = map->max_x - map->min_x;
	iso_height = map->max_y - map->min_y;
	if (w_width / iso_width < w_height / iso_height)
		map->scale = w_width / iso_width;
	else
	{
		map->scale = w_height / iso_height;
	}
	map->offset_x = (w_width - iso_width * map->scale)
		/ 2 - (map->min_x * map->scale);
	map->offset_y = (w_height - iso_height * map->scale)
		/ 2 - (map->min_y * map->scale);
}

void	preprocess_matrix(t_dot **matrix, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->map_rows)
	{
		j = 0;
		while (j < map->map_cols)
		{
			calculate_iso_coords(&matrix[i][j]);
			scale_iso_coords(&matrix[i][j], map);
			j++;
		}
		i++;
	}
}

void	render_matrix(mlx_image_t *img, t_dot **matrix, t_map *map)
{
	int			i;
	int			j;
	uint32_t	x2d;
	uint32_t	y2d;

	i = 0;
	while (i < map->map_rows)
	{
		j = 0;
		while (j < map->map_cols)
		{
			x2d = matrix[i][j].iso_x * map->scale + map->offset_x;
			y2d = matrix[i][j].iso_y * map->scale + map->offset_y;
			mlx_put_pixel(img, x2d, y2d, 0xFFFFFFFF);
			j++;
		}
		i++;
	}
}
