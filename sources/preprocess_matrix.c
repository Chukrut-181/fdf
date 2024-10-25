/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocess_matrix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:39:12 by igchurru          #+#    #+#             */
/*   Updated: 2024/10/25 11:44:22 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../MLX42/include/MLX42/MLX42.h"

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

void	calculate_iso_coords(t_dot *dot)
{
	dot->iso_x = (dot->x - dot->y) * cos(ISO_ANGLE);
	dot->iso_y = (dot->x + dot->y) * sin(ISO_ANGLE) - dot->z;
}

void	scale_iso_coords(t_dot *dot, t_map *map)
{
	dot->scaled_iso_x = (dot->iso_x * map->scale) + map->offset_x;
	dot->scaled_iso_y = (dot->iso_y * map->scale) + map->offset_y;
}
