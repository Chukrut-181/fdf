/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocess_matrix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:39:12 by igchurru          #+#    #+#             */
/*   Updated: 2024/10/29 15:31:43 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../MLX42/include/MLX42/MLX42.h"

/*	preprocess_matrix - Prepares the 2D matrix of points for rendering
in isometric projection.

@matrix: 2D array of points representing the map structure.
@map: Struct containing map parameters, including scale and offset settings.

Iterate through each row of the matrix.
Calculate isometric coordinates for each point.
Apply initial scaling and offset based on window dimensions.
Iterate through the matrix again to scale the isometric coordinates. */
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
			calculate_iso_coords(&matrix[i][j++]);
		}
		i++;
	}
	scale_and_offset(matrix, map, 1600, 1200);
	map->initial_scale = map->scale;
	i = 0;
	while (i < map->map_rows)
	{
		j = 0;
		while (j < map->map_cols)
		{
			scale_iso_coords(&matrix[i][j++], map);
		}
		i++;
	}
}

/*	calculate_iso_coords - Computes the isometric coordinates
for a single point.
@dot: Pointer to a point struct containing x, y, and z coordinates. */
void	calculate_iso_coords(t_dot *dot)
{
	dot->iso_x = (dot->x - dot->y) * cos(ISO_ANGLE);
	dot->iso_y = (dot->x + dot->y) * sin(ISO_ANGLE) - dot->z;
}

/*	scale_iso_coords - Scales the isometric coordinates of a point
according to map settings.
@dot: Pointer to a point struct containing isometric coordinates.
@map: Struct containing scale and offset parameters for rendering. */
void	scale_iso_coords(t_dot *dot, t_map *map)
{
	dot->scaled_iso_x = (dot->iso_x * map->scale) + map->offset_x;
	dot->scaled_iso_y = (dot->iso_y * map->scale) + map->offset_y;
}
