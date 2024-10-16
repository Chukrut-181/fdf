/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 08:55:34 by igchurru          #+#    #+#             */
/*   Updated: 2024/10/16 13:17:56 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../MLX42/include/MLX42/MLX42.h"

int	main(int argc, char **argv)
{
	t_dot	**matrix;
	t_map	map;
	
	if (argc != 2)
		error_exit("Incorrect number of arguments: Must be exactly 2.\n");
	matrix = parse_map(argv[1], &map);
	fil_de_fer(matrix);
	return (EXIT_SUCCESS);
}
