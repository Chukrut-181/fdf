/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:03:31 by igchurru          #+#    #+#             */
/*   Updated: 2024/10/16 12:37:30 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../MLX42/include/MLX42/MLX42.h"

void	render_matrix(mlx_image_t *img, t_dot **matrix, int n_of_rows, int n_of_cols)
{
	int			i;
	int			j;
	uint32_t	x2d;
	uint32_t	y2d;

	i = 0;
	while (i < n_of_rows)
	{
		j = 0;
		while (j < n_of_cols)
		{
			x2d = (uint32_t)matrix[i][j].x * 20 + 20;
			y2d = (uint32_t)matrix[i][j].y * 20 + 20;
			mlx_put_pixel(img, x2d, y2d, 0xFFFFFFFF);
			j++;
		}
		i++;
	}
}
