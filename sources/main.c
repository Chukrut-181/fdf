/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 08:55:34 by igchurru          #+#    #+#             */
/*   Updated: 2024/10/29 15:52:52 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../MLX42/include/MLX42/MLX42.h"

/*	main - Entry point of the program that initializes
and renders the 3D wireframe.
@argc: Argument count.
@argv: Argument vector containing the map file name.

This function checks if the correct number of arguments is provided. 
It then parses the map file to create a matrix of points, initializes 
the t_map struct, and calls fil_de_fer to render the wireframe. 
If the argument count is incorrect, it exits with an error.

Return: EXIT_SUCCESS on successful execution. */
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
