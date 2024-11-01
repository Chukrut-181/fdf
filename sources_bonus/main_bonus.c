/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 08:55:34 by igchurru          #+#    #+#             */
/*   Updated: 2024/10/25 11:38:29 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"
#include "../MLX42/include/MLX42/MLX42.h"

int	main(int argc, char **argv)
{
	t_dot	**matrix;
	t_map	map;

	if (argc != 2)
		error_exit("Incorrect number of arguments: Must be exactly 2.\n");
	matrix = parse_map(argv[1], &map);
	fil_de_fer(matrix, &map);
	return (EXIT_SUCCESS);
}
