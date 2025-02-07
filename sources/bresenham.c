/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 09:55:07 by igchurru          #+#    #+#             */
/*   Updated: 2024/10/29 15:43:30 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../MLX42/include/MLX42/MLX42.h"

/*	init_bresenham - Initializes the Bresenham algorithm parameters
for line drawing.
@b: Pointer to a t_bresenham struct that holds the line drawing parameters.
@origin: The starting point of the line.
@target: The ending point of the line.

This function extracts the coordinates from the origin and target points, 
calculates the differences in the x and y directions, and determines 
the step direction for each axis. It also initializes the error term 
used in the Bresenham algorithm. */
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

/*	determine_step_direction - Determines direction of steps for Bresenham's.
@step: Pointer to an integer that will hold the step direction (1 or -1).
@a: The starting coordinate.
@b: The target coordinate.

This function sets the step direction based on the comparison between 
the starting and target coordinates. A positive step indicates 
moving forward, while a negative step indicates moving backward. */
void	determine_step_direction(int *step, int a, int b)
{
	if (a < b)
	{
		*step = 1;
	}
	else
		*step = -1;
}

/*	extract_coordinates - Extracts the x and y coordinates from a point.
@x: Pointer to an integer where the x coordinate will be stored.
@y: Pointer to an integer where the y coordinate will be stored.
@dot: The point from which the coordinates are extracted.

This function converts the scaled isometric coordinates of the dot 
to integer values and assigns them to the provided pointers. */
void	extract_coordinates(int *x, int *y, t_dot dot)
{
	*x = (int)dot.scaled_iso_x;
	*y = (int)dot.scaled_iso_y;
}

/*	draw_step - Updates the Bresenham algorithm state for the next pixel.
@b: Pointer to a t_bresenham struct holding the current state of
the line drawing.

This function modifies the current pixel coordinates based on the 
error term and step direction, preparing for the next pixel in the 
Bresenham line drawing algorithm. */
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
