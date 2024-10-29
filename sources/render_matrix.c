/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:03:31 by igchurru          #+#    #+#             */
/*   Updated: 2024/10/29 15:36:18 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../MLX42/include/MLX42/MLX42.h"

/*	is_out_of_bounds - Checks if a point is outside the rendering window bounds.
@dot: Pointer to a point struct containing scaled isometric coordinates.

This function returns 1 if the point's scaled coordinates are outside the 
defined window dimensions (1600x1200), and 0 otherwise. */
int	is_out_of_bounds(t_dot *dot)
{
	if (dot->scaled_iso_x < 0 || dot->scaled_iso_x >= 1600
		|| dot->scaled_iso_y < 0 || dot->scaled_iso_y >= 1200)
	{
		return (1);
	}
	return (0);
}

/*	calculate_iso_bounds - Computes the min and max isometric bounds
for the matrix.
@matrix: 2D array of points representing the map structure.
@map: Struct containing bounds information for isometric coordinates.

This function iterates through the matrix of points to determine the minimum 
and maximum isometric x and y coordinates, updating the corresponding fields
in the map structure for later scaling and rendering. */
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

/*	scale_and_offset - Calculates the scaling factor and offset
for rendering the matrix.
@matrix: 2D array of points representing the map structure.
@map: Struct containing scale and offset parameters for rendering.
@w_width: Width of the rendering window.
@w_height: Height of the rendering window.

This function computes the bounds of the isometric coordinates
and determines the appropriate scaling to fit the map within
the specified window dimensions. It also calculates the necessary
offsets to center the map in the window. */
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

/*	render_matrix - Renders the isometric points onto the image.
@img: Pointer to the image struct where pixels are drawn.
@matrix: 2D array of points representing the map structure.
@map: Struct containing rendering parameters.

This function iterates through the matrix of points, checks if
each point is within the bounds of the rendering window,
and draws the corresponding pixel on the image if it is valid. */
void	render_matrix(mlx_image_t *img, t_dot **matrix, t_map *map)
{
	int		i;
	int		j;
	double	x2d;
	double	y2d;

	i = 0;
	while (i < map->map_rows)
	{
		j = 0;
		while (j < map->map_cols)
		{
			x2d = matrix[i][j].scaled_iso_x;
			y2d = matrix[i][j].scaled_iso_y;
			if (!is_out_of_bounds(&matrix[i][j]))
			{
				mlx_put_pixel(img, (uint32_t)x2d, (uint32_t)y2d, 0xFFFFFFFF);
			}
			j++;
		}
		i++;
	}
}
