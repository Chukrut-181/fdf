/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:05:37 by igchurru          #+#    #+#             */
/*   Updated: 2024/10/29 15:53:32 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../MLX42/include/MLX42/MLX42.h"

/*	handle_key - Manages keyboard input for the window,
specifically for closing it.
@keydata: Struct containing data about the key event
(key pressed and action type).
@param: Pointer to the t_map struct, passed as a parameter to access map data.

This function checks if the Escape key is pressed. If so, it triggers 
the mlx_close_window function to close the window. Otherwise, it returns 
without performing any action. */
void	handle_key(mlx_key_data_t keydata, void *param)
{
	t_map			*map;

	map = (t_map *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(map->mlx);
	else
		return ;
}
