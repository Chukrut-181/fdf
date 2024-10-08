/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 08:55:34 by igchurru          #+#    #+#             */
/*   Updated: 2024/10/08 15:07:36 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "../MLX42/include/MLX42/MLX42.h"
#include "../libft/libft.h"

int	main(void)
{
	mlx_t			*mlx;
	mlx_image_t		*img;

	mlx = mlx_init(1600, 1200, "test window", true);
	if (mlx)
		write(1, "mlx_ptr OK\n", 11);
	img = mlx_new_image(mlx, 800, 600);
	if (img)
		write(1, "img_ptr OK\n", 11);
	ft_memset(img->pixels, 255, img->width * img->height * sizeof(int32_t));
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_loop(mlx);
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
	return (0);
}
