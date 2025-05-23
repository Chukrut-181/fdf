/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:07:32 by igchurru          #+#    #+#             */
/*   Updated: 2024/10/29 15:55:49 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"
#include "../MLX42/include/MLX42/MLX42.h"

/*	assign_color_based_on_z - Assigns a color to a t_dot based on its
z-coordinate.
@dot: Pointer to the t_dot struct for which the color is being assigned.

This function sets the color32 property of the dot based on its z value. 
Different ranges of z correspond to specific colors, allowing for a 
visual representation of height in the rendered output. */
void	assign_color_based_on_z(t_dot *dot)
{
	if (dot->z <= -10)
		dot->color32 = 0xFF8B0000;
	else if (-10 < dot->z && dot->z < -8)
		dot->color32 = 0xFFFF0000;
	else if (-8 <= dot->z && dot->z < -6)
		dot->color32 = 0xFFFFA500;
	else if (-6 <= dot->z && dot->z < -4)
		dot->color32 = 0xFFFFFF00;
	else if (-4 <= dot->z && dot->z < -2)
		dot->color32 = 0xFF006400;
	else if (-2 <= dot->z && dot->z < 0)
		dot->color32 = 0xFF008000;
	else if (0 <= dot->z && dot->z < 2)
		dot->color32 = 0xFF90EE90;
	else if (2 <= dot->z && dot->z < 4)
		dot->color32 = 0xFF00FFFF;
	else if (4 <= dot->z && dot->z < 6)
		dot->color32 = 0xFF0000FF;
	else if (6 <= dot->z && dot->z < 8)
		dot->color32 = 0xFF00008B;
	else if (8 <= dot->z && dot->z < 10)
		dot->color32 = 0xFF4B0082;
	else if (10 <= dot->z)
		dot->color32 = 0xFFEE82EE;
}
