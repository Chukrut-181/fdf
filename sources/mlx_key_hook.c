/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:05:37 by igchurru          #+#    #+#             */
/*   Updated: 2024/10/23 15:57:59 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../MLX42/include/MLX42/MLX42.h"

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
}
