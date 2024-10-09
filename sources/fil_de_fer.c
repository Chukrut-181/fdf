/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fil_de_fer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:22:08 by igchurru          #+#    #+#             */
/*   Updated: 2024/10/09 15:10:27 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../MLX42/include/MLX42/MLX42.h"


/* void	draw_rect(mlx_image_t *img, uint32_t x, uint32_t y, int width, int height, uint32_t color)
{
	int			i;
	int			j;
	uint32_t	*pixels;

	pixels = (uint32_t *)img->pixels;
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if ((x + j) < img->width && (y + i) < img->height)
				pixels[(y + i) * img->width + (x + j)] = color;
			j++;
		}
		i++;
	}
} */

void	fil_de_fer()
{
	mlx_t			*mlx;
	mlx_image_t		*img;

	mlx = mlx_init(1600, 1200, "test window", true);
	img = mlx_new_image(mlx, 1600, 1200);
	//draw_rect(img, 0, 0, 800, 600, 0xFF0000FF);
	mlx_put_pixel(img, 10, 10, 0xFFFFFFFF);
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_loop(mlx);
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
}
