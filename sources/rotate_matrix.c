/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:56:32 by igchurru          #+#    #+#             */
/*   Updated: 2024/10/23 16:00:14 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../MLX42/include/MLX42/MLX42.h"

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

void	manage_rotation(t_map *map, double angle)
{
	rotate_matrix(map, angle);
	mlx_delete_image(map->mlx, map->img);
	map->img = mlx_new_image(map->mlx, 1600, 1200);
	render_matrix(map->img, map->matrix, map);
	render_lines(map->img, map->matrix, map);
	mlx_image_to_window(map->mlx, map->img, 0, 0);
}

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
