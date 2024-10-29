/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key_hook_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:05:37 by igchurru          #+#    #+#             */
/*   Updated: 2024/10/29 15:57:49 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"
#include "../MLX42/include/MLX42/MLX42.h"

/*	handle_key - Manages keyboard input for window interactions,
including rotation and translation.
@keydata: Struct containing data about the key event
(key pressed and action type).
@param: Pointer to the t_map struct, passed as a parameter to access map data.

This function handles various key inputs to control the behavior of
the rendering. It allows the user to close the window, rotate the view,
and adjust the offset of the map in both the x and y directions.
Additionally, it manages the projection mode toggle when the 'P' key is pressed.
The rotation angle is maintained as a static variable. */
void	handle_key(mlx_key_data_t keydata, void *param)
{
	t_map			*map;
	static double	rotation_angle;

	rotation_angle = 0;
	map = (t_map *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(map->mlx);
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		rotation_angle -= ROTATE_ANGLE;
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		rotation_angle += ROTATE_ANGLE;
	else if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		map->offset_y -= 15;
	else if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		map->offset_y += 15;
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		map->offset_x -= 15;
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		map->offset_x += 15;
	manage_rotation(map, rotation_angle);
	if (keydata.key == MLX_KEY_P && keydata.action == MLX_PRESS)
		toggle_projection(map);
}
