/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toggle_projection_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 12:42:27 by igchurru          #+#    #+#             */
/*   Updated: 2024/10/29 16:06:25 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"
#include "../MLX42/include/MLX42/MLX42.h"

/*	toggle_projection - Switches between isometric and perspective
projection modes.
@map: Pointer to the t_map struct that holds the current projection mode.

This function toggles the projection mode of the map between isometric and 
perspective. After changing the projection mode, it calls apply_projection to 
update the matrix coordinates and redraw_scene to refresh the displayed
scene. */
void	toggle_projection(t_map *map)
{
	if (map->projection_mode == ISOMETRIC)
		map->projection_mode = PERSPECTIVE;
	else
		map->projection_mode = ISOMETRIC;
	apply_projection(map);
	redraw_scene(map);
}

/*	apply_projection - Applies the current projection transformation
to the matrix.
@map: Pointer to the t_map struct that contains the projection
mode and matrix.

This function checks the current projection mode and applies
the appropriate transformation to the matrix. If the mode is isometric,
it preprocesses the matrix for isometric coordinates.
If the mode is perspective, it calls preprocess_persp_matrix
to handle perspective coordinates. */
void	apply_projection(t_map *map)
{
	t_dot	**matrix;

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

/*	preprocess_persp_matrix - Calculates perspective coordinates
for the matrix.
@matrix: The 2D array of t_dot representing the map's points.
@map: Pointer to the t_map struct containing map data.

This function iterates through the matrix to compute perspective coordinates 
for each dot. After calculating the coordinates, it scales and offsets the 
matrix according to the window size. The initial scale is updated for future 
reference. */
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

/*	redraw_scene - Refreshes the window by rendering the updated
matrix and lines.
@map: Pointer to the t_map struct containing the current map data.

This function deletes the current image, creates a new one,
renders the updated matrix and lines onto the new image,
and displays it in the window. */
void	redraw_scene(t_map *map)
{
	mlx_delete_image(map->mlx, map->img);
	map->img = mlx_new_image(map->mlx, 1600, 1200);
	render_matrix(map->img, map->matrix, map);
	render_lines(map->img, map->matrix, map);
	mlx_image_to_window(map->mlx, map->img, 0, 0);
}
