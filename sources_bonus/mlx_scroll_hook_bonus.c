/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_scroll_hook_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:58:10 by igchurru          #+#    #+#             */
/*   Updated: 2024/10/29 16:02:38 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"
#include "../MLX42/include/MLX42/MLX42.h"

/*	scroll_zoom - Adjusts the zoom level of the map based on scroll input.
@xdelta: The change in the x-direction (unused).
@ydelta: The change in the y-direction, determines zoom direction.
@param: Pointer to the t_map struct for accessing map data.

This function modifies the zoom level of the map based on the vertical scroll 
input (ydelta). A positive ydelta zooms in, while a negative ydelta zooms out. 
After adjusting the zoom level, it deletes the previous image, creates a new 
image, renders the updated matrix and lines, and displays the new image
in the window. */
void	scroll_zoom(double xdelta, double ydelta, void *param)
{
	t_map	*map;

	map = (t_map *)param;
	(void)xdelta;
	if (ydelta > 0)
		zoom_matrix(map, 1.1);
	else if (ydelta < 0)
		zoom_matrix(map, 0.9);
	mlx_delete_image(map->mlx, map->img);
	map->img = mlx_new_image(map->mlx, 1600, 1200);
	render_matrix(map->img, map->matrix, map);
	render_lines(map->img, map->matrix, map);
	mlx_image_to_window(map->mlx, map->img, 0, 0);
}

/*	zoom_matrix - Scales the coordinates of all dots in the map's matrix.
@map: Pointer to the t_map struct containing the matrix and scale information.
@zoom_factor: The factor by which to scale the coordinates.

This function adjusts the scale of the map based on the provided zoom factor. 
If the zoom factor is less than 1 and the current scale is less than or equal 
to the initial scale, no zooming occurs. Otherwise, it scales each dot's iso 
coordinates accordingly. */
void	zoom_matrix(t_map *map, double zoom_factor)
{
	int	i;
	int	j;

	if (zoom_factor < 1 && map->scale <= map->initial_scale)
		return ;
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
