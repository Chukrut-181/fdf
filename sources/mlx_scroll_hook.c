/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_scroll_hook.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:58:10 by igchurru          #+#    #+#             */
/*   Updated: 2024/10/23 12:06:16 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../MLX42/include/MLX42/MLX42.h"

void	scroll_zoom(double xdelta, double ydelta, void *param)
{
	t_map	*map;

	map = (t_map *)param;
	(void)xdelta;

	if (ydelta > 0)
	{
		zoom_matrix(map, 1.1);
	}
	else if (ydelta < 0)
	{
		zoom_matrix(map, 0.9);
	}

	mlx_delete_image(map->mlx, map->img);
	map->img = mlx_new_image(map->mlx, 1600, 1200);
	render_matrix(map->img, map->matrix, map);
	render_lines(map->img, map->matrix, map);
	mlx_image_to_window(map->mlx, map->img, 0, 0);
}

void zoom_matrix(t_map *map, double zoom_factor)
{
	int i;
	int j;
 	if (zoom_factor < 1 && map->scale < map->initial_scale)
	{
		return ;
	}
	map->scale *= zoom_factor;
	i = 0;
	while (i < map->map_rows)
	{
		j = 0;
		while (j < map->map_cols)
		{
			scale_iso_coords(&map->matrix[i][j], map);
			j++;
		}
		i++;
	}
}
