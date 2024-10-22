/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fil_de_fer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:22:08 by igchurru          #+#    #+#             */
/*   Updated: 2024/10/22 16:14:59 by igchurru         ###   ########.fr       */
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
	map->matrix = matrix;
	map->img = img;
	map->mlx = mlx;
	map->current_angle = 0;
	render_matrix(img, matrix, map);
	render_lines(img, matrix, map);
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_key_hook(mlx, handle_key, map);
	mlx_scroll_hook(mlx, scroll_zoom, map);
	mlx_loop(mlx);
	free_matrix(matrix, map->map_rows);
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
}
