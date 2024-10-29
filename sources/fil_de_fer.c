/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fil_de_fer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:22:08 by igchurru          #+#    #+#             */
/*   Updated: 2024/10/29 15:26:12 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../MLX42/include/MLX42/MLX42.h"

/* fil_de_fer - Initializes and renders the 3D wireframe map
using the MLX42 library.

@matrix: 2D array of points representing the 3D map structure.
@map: Struct containing map information, including matrix data, image,
and rendering settings.

Initialize graphics window and image.
Preprocess matrix data for rendering.
Store references in the map structure.
Render points and lines connecting them.
Display image in the window.
Set up key event handling.
Start the event loop for MLX42.
Clean up resources when finished. */
void	fil_de_fer(t_dot **matrix, t_map *map)
{
	mlx_t			*mlx;
	mlx_image_t		*img;

	mlx = mlx_init(1600, 1200, "Fil de Fer", true);
	img = mlx_new_image(mlx, 1600, 1200);
	preprocess_matrix(matrix, map);
	map->matrix = matrix;
	map->img = img;
	map->mlx = mlx;
	map->current_angle = 0;
	render_matrix(img, matrix, map);
	render_lines(img, matrix, map);
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_key_hook(mlx, handle_key, map);
	mlx_loop(mlx);
	free_matrix(matrix, map->map_rows);
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
}
