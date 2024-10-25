/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toggle_projection_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 12:42:27 by igchurru          #+#    #+#             */
/*   Updated: 2024/10/25 13:00:46 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"
#include "../MLX42/include/MLX42/MLX42.h"

void	toggle_projection(t_map *map)
{
	if (map->projection_mode == ISOMETRIC)
		map->projection_mode = PERSPECTIVE;
	else
		map->projection_mode = ISOMETRIC;
	apply_projection(map);
	redraw_scene(map);
}

void	apply_projection(t_map *map)
{
	t_dot **matrix;
	
	matrix = map->matrix;
	if (map->projection_mode == ISOMETRIC)
	{
		preprocess_matrix(matrix, map);
	}
	if (map->projection_mode == PERSPECTIVE)
	{
		preprocess_persp_matrix(matrix, map);
	}
}

void	preprocess_persp_matrix(t_dot **matrix, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->map_rows)
	{
		j = 0;
		while (j < map->map_cols)
		{
			calculate_perspective_coords(&matrix[i][j++]);
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

void	redraw_scene(t_map *map)
{
	mlx_delete_image(map->mlx, map->img);
	map->img = mlx_new_image(map->mlx, 1600, 1200);
	render_matrix(map->img, map->matrix, map);
	render_lines(map->img, map->matrix, map);
	mlx_image_to_window(map->mlx, map->img, 0, 0);
}
