/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 08:55:34 by igchurru          #+#    #+#             */
/*   Updated: 2024/10/15 12:40:11 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../MLX42/include/MLX42/MLX42.h"

int	main(int argc, char **argv)
{
	t_dot	**matrix;
	
	if (argc != 2)
		error_exit("Incorrect number of arguments: Must be exactly 2.\n");
	matrix = NULL;
	parse_map(argv[1], matrix);
	fil_de_fer();
	return (EXIT_SUCCESS);
}
