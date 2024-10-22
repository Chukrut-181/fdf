/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 09:55:07 by igchurru          #+#    #+#             */
/*   Updated: 2024/10/21 10:18:11 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../MLX42/include/MLX42/MLX42.h"

void	init_bresenham(t_bresenham *b, t_dot origin, t_dot target)
{
	extract_coordinates(&b->x0, &b->y0, origin);
	extract_coordinates(&b->x1, &b->y1, target);
	b->delta_x = abs(b->x1 - b->x0);
	b->delta_y = abs(b->y1 - b->y0);
	determine_step_direction(&b->step_x, b->x0, b->x1);
	determine_step_direction(&b->step_y, b->y0, b->y1);
	b->error = b->delta_x - b->delta_y;
}

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

void	draw_step(t_bresenham *b)
{
	int	error2;

	error2 = b->error * 2;
	if (error2 > -b->delta_y)
	{
		b->error -= b->delta_y;
		b->x0 += b->step_x;
	}
	if (error2 < b->delta_x)
	{
		b->error += b->delta_x;
		b->y0 += b->step_y;
	}
}
