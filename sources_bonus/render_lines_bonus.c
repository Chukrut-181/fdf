/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_lines_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:29:32 by igchurru          #+#    #+#             */
/*   Updated: 2024/10/25 12:00:13 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"
#include "../MLX42/include/MLX42/MLX42.h"

void	draw_line(mlx_image_t *img, t_dot origin, t_dot target, uint32_t color)
{
	t_bresenham	b;

	ft_bzero(&b, sizeof(t_bresenham));
	init_bresenham(&b, origin, target);
	while (true)
	{
		mlx_put_pixel(img, b.x0, b.y0, color);
		if (b.x0 == b.x1 && b.y0 == b.y1)
		{
			break ;
		}
		draw_step(&b);
	}
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
				if (!bounds(&matrix[i][j]) && !bounds(&matrix[i][j + 1]))
					draw_line(img, matrix[i][j], matrix[i][j + 1],
						matrix[i][j].color32);
			}
			if (i < map->map_rows - 1)
			{
				if (!bounds(&matrix[i][j]) && !bounds(&matrix[i + 1][j]))
					draw_line(img, matrix[i][j], matrix[i + 1][j],
						matrix[i][j].color32);
			}
			j++;
		}
		i++;
	}
}
