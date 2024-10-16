/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:03:31 by igchurru          #+#    #+#             */
/*   Updated: 2024/10/16 15:59:31 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../MLX42/include/MLX42/MLX42.h"

void	calculate_scale_and_offset(t_map *map, int window_width, int window_height)
{

	int scale_x;
	int scale_y;

	scale_x = window_width / (map->map_cols + 1);
	scale_y = window_height / (map->map_rows + 1);

	if (scale_x < scale_y)
		map->scale = scale_x;
	else
		map->scale = scale_y;
	map->offset_x = (window_width - (map->map_cols * map->scale)) / 2;
	map->offset_y = (window_height - (map->map_rows * map->scale)) / 2;
}

void	render_matrix(mlx_image_t *img, t_dot **matrix, t_map *map)
{
	int			i;
	int			j;
	uint32_t	x2d;
	uint32_t	y2d;

	i = 0;
	while (i < map->map_rows)
	{
		j = 0;
		while (j < map->map_cols)
		{
			x2d = (uint32_t)matrix[i][j].x * map->scale + map->offset_x;
			y2d = (uint32_t)matrix[i][j].y * map->scale + map->offset_y;
			mlx_put_pixel(img, x2d, y2d, 0xFFFFFFFF);
			j++;
		}
		i++;
	}
}

