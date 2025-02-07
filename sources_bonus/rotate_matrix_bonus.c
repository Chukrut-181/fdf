/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_matrix_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:56:32 by igchurru          #+#    #+#             */
/*   Updated: 2024/10/29 16:01:08 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"
#include "../MLX42/include/MLX42/MLX42.h"

/*	calculate_map_center - Calculates the geometric center
of the map based on the matrix of dots.
@map: Pointer to the t_map struct containing the matrix of dots and their
properties.

This function iterates through all dots in the map matrix,
summing their iso_x, iso_y, and z coordinates.
It then averages these sums to determine the center coordinates of the map. */
void	calculate_map_center(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->map_rows)
	{
		j = 0;
		while (j < map->map_cols)
		{
			map->center_x += map->matrix[i][j].iso_x;
			map->center_y += map->matrix[i][j].iso_y;
			map->center_z += map->matrix[i][j].z;
			j++;
		}
		i++;
	}
	map->center_x /= map->total_dots;
	map->center_y /= map->total_dots;
}

/*	manage_rotation - Updates the map display after a rotation.
@map: Pointer to the t_map struct containing the current map data.
@angle: The angle by which the map should be rotated.

This function rotates the map's matrix based on the specified angle, deletes the 
previous image, creates a new image, renders the updated matrix and lines, 
and displays the new image in the window. */
void	manage_rotation(t_map *map, double angle)
{
	rotate_matrix(map, angle);
	mlx_delete_image(map->mlx, map->img);
	map->img = mlx_new_image(map->mlx, 1600, 1200);
	render_matrix(map->img, map->matrix, map);
	render_lines(map->img, map->matrix, map);
	mlx_image_to_window(map->mlx, map->img, 0, 0);
}

/*	rotate_matrix - Rotates all dots in the map's matrix
around the center point.
@map: Pointer to the t_map struct containing the matrix and center coordinates.
@angle: The angle in radians for the rotation.

This function first calculates the center of the map, then iterates through 
each dot in the matrix, applying the rotation to each dot based on
the given angle and recalculating their iso coordinates. */
void	rotate_matrix(t_map *map, double angle)
{
	int	i;
	int	j;

	calculate_map_center(map);
	i = 0;
	while (i < map->map_rows)
	{
		j = 0;
		while (j < map->map_cols)
		{
			rotate_dot(&map->matrix[i][j], angle, map->center_x, map->center_y);
			scale_iso_coords(&map->matrix[i][j], map);
			j++;
		}
		i++;
	}
}

/*	rotate_dot - Rotates a single dot around a specified center point.
@dot: Pointer to the t_dot struct to be rotated.
@angle: The angle in radians for the rotation.
@center_x: The x-coordinate of the center point around which to rotate.
@center_y: The y-coordinate of the center point around which to rotate.

This function translates the dot's coordinates to the origin,
applies the rotation transformation, and then translates the dot
back to its original position relative to the center point. */
void	rotate_dot(t_dot *dot, double angle, double center_x, double center_y)
{
	double	translated_x;
	double	translated_y;
	double	rotated_x;
	double	rotated_y;

	translated_x = dot->iso_x - center_x;
	translated_y = dot->iso_y - center_y;
	rotated_x = translated_x * cos(angle) - translated_y * sin(angle);
	rotated_y = translated_x * sin(angle) + translated_y * cos(angle);
	dot->iso_x = rotated_x + center_x;
	dot->iso_y = rotated_y + center_y;
}
