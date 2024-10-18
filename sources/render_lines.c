/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_lines.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:29:32 by igchurru          #+#    #+#             */
/*   Updated: 2024/10/17 13:58:17 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../MLX42/include/MLX42/MLX42.h"

void	draw_line(mlx_image_t *img, t_dot origin, t_dot target, uint32_t color)
{
	int x0 = (int)((origin.iso_x * origin.map->scale) + origin.map->offset_x);
	int y0 = (int)((origin.iso_y * origin.map->scale) + origin.map->offset_y);
	int x1 = (int)((target.iso_x * target.map->scale) + target.map->offset_x);
	int y1 = (int)((target.iso_y * target.map->scale) + target.map->offset_y);

	int dx = x1 - x0;
	int dy = y1 - y0;
	int sx = (dx >= 0) ? 1 : -1;
	int sy = (dy >= 0) ? 1 : -1;
	dx = abs(dx);
	dy = abs(dy);

	if (dx > dy)
	{
		int err = dx / 2;
		while (x0 != x1)
		{
			mlx_put_pixel(img, x0, y0, color);
			err -= dy;
			if (err < 0)
			{
				y0 += sy;
				err += dx;
			}
			x0 += sx;
		}
	}
	else
	{
		int err = dy / 2;
		while (y0 != y1)
		{
			mlx_put_pixel(img, x0, y0, color);
			err -= dx;
			if (err < 0)
			{
				x0 += sx;
				err += dy;
			}
			y0 += sy;
		}
	}
	mlx_put_pixel(img, x0, y0, color);  // Ensure the last point is drawn
}

void	render_lines(mlx_image_t *img, t_dot **matrix, t_map *map)
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
				draw_line(img, matrix[i][j], matrix[i][j + 1], 0xFFFFFFFF);
			}
			if (i < map->map_rows - 1)
			{
				draw_line(img, matrix[i][j], matrix[i + 1][j], 0xFFFFFFFF);
			}
			j++;
		}
		i++;		
	}
}
