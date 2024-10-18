/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_lines.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:29:32 by igchurru          #+#    #+#             */
/*   Updated: 2024/10/18 12:05:57 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../MLX42/include/MLX42/MLX42.h"

void	determine_step_direction(int *step, int a, int b)
{
	if (a < b)
	{
		*step = 1;
	}
	else
		*step = -1;
}

void	extract_coordinates(int *x, int *y, t_dot dot)
{
	*x = (int)dot.scaled_iso_x;
	*y = (int)dot.scaled_iso_y;
}

void	draw_line(mlx_image_t *img, t_dot origin, t_dot target, uint32_t color)
{
	int x0;
	int y0;
	int x1;
	int y1;
	int delta_x;
	int delta_y;
	int step_x;
	int step_y;
	int error;
	extract_coordinates(&x0, &y0, origin);
	extract_coordinates(&x1, &y1, target);
	delta_x = abs(x1 - x0);
	delta_y = abs(y1 - y0);
	determine_step_direction(&step_x, x0, x1);
	determine_step_direction(&step_y, y0, y1);
	error = delta_x - delta_y;

	while (true)
	{
		mlx_put_pixel(img, x0, y0, color); // Plot the pixel at (x0, y0)

		if (x0 == x1 || y0 == y1)
		{
			break; // Exit if we've reached the target point
		}
		if ((error * 2) > -delta_y) // Check if we need to move in the x direction
		{
			error -= delta_y; // Update the error
			x0 += step_x; // Move in the x direction
		}
		if ((error * 2) < delta_x) // Check if we need to move in the y direction
		{
			error += delta_x; // Update the error
			y0 += step_y; // Move in the y direction
		}
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
