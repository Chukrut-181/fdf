/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fil_de_fer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:22:08 by igchurru          #+#    #+#             */
/*   Updated: 2024/10/17 13:28:12 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../MLX42/include/MLX42/MLX42.h"

void	fil_de_fer(t_dot **matrix, t_map *map)
{
	mlx_t			*mlx;
	mlx_image_t		*img;

	mlx = mlx_init(1600, 1200, "Fil de Fer", true);
	img = mlx_new_image(mlx, 1600, 1200);
	preprocess_matrix(matrix, map);
	scale_and_offset(matrix, map, 1600, 1200);
	render_matrix(img, matrix, map);
	//DRAW LINES if (j < map->map_cols - 1) // Draw line to the right dot
	//DRAW LINES if (j < map->map_rows - 1) // Draw line to the bottom dot
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_loop(mlx);
	free_matrix(matrix, map->map_rows);
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
}
