/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fil_de_fer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:22:08 by igchurru          #+#    #+#             */
/*   Updated: 2024/10/16 12:24:35 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../MLX42/include/MLX42/MLX42.h"

void	fil_de_fer(t_dot **matrix)
{
	mlx_t			*mlx;
	mlx_image_t		*img;

	mlx = mlx_init(1600, 1200, "test window", true);
	img = mlx_new_image(mlx, 1600, 1200);
	render_matrix(img, matrix, 9, 11);
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_loop(mlx);
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
}
