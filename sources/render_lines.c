/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_lines.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:29:32 by igchurru          #+#    #+#             */
/*   Updated: 2024/10/29 15:39:19 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../MLX42/include/MLX42/MLX42.h"

/*	draw_line - Draws a line between two points using the Bresenham algorithm.
@img: Pointer to the image struct where the line is drawn.
@origin: The starting point of the line.
@target: The ending point of the line.
@color: The color of the line in ARGB format.

This function initializes the Bresenham algorithm for line drawing and 
continuously places pixels on the image from the origin to the target 
until the line is completely rendered. */
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

/*	render_lines - Renders lines connecting the points in the matrix.
@img: Pointer to the image struct where lines are drawn.
@matrix: 2D array of points representing the map structure.
@map: Struct containing rendering parameters.

This function iterates through the matrix of points, drawing horizontal 
and vertical lines between adjacent points. It checks for out-of-bounds 
conditions before attempting to draw each line. */
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
				if (!is_out_of_bounds(&matrix[i][j])
					&& !is_out_of_bounds(&matrix[i][j + 1]))
					draw_line(img, matrix[i][j], matrix[i][j + 1], 0xFFFFFFFF);
			}
			if (i < map->map_rows - 1)
			{
				if (!is_out_of_bounds(&matrix[i][j])
					&& !is_out_of_bounds(&matrix[i + 1][j]))
					draw_line(img, matrix[i][j], matrix[i + 1][j], 0xFFFFFFFF);
			}
			j++;
		}
		i++;
	}
}
