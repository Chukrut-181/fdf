/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocess_matrix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:39:12 by igchurru          #+#    #+#             */
/*   Updated: 2024/10/21 15:36:58 by igchurru         ###   ########.fr       */
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
	//set_neighbors_scaled_coords(matrix, map);
}

/* void	set_neighbors_scaled_coords(t_dot **matrix, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->map_rows)
	{
		j = 0;
		while (j < map->map_cols)
		{
			if (j < map->map_cols - 1)
			{
				matrix[i][j].right_scaled_iso_x = matrix[i][j + 1].scaled_iso_x;
				matrix[i][j].right_scaled_iso_y = matrix[i][j + 1].scaled_iso_y;
			}
			if (i < map->map_rows - 1)
			{
				matrix[i][j].bottom_scaled_iso_x
					= matrix[i + 1][j].scaled_iso_x;
				matrix[i][j].bottom_scaled_iso_y
					= matrix[i + 1][j].scaled_iso_y;
			}
			j++;
		}
		i++;
	}
} */

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
