/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:22:39 by igchurru          #+#    #+#             */
/*   Updated: 2024/10/29 15:52:09 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../MLX42/include/MLX42/MLX42.h"

/*	free_matrix - Frees allocated memory for a 2D array of t_dot structs.
@matrix: The 2D array of t_dot structs to be freed.
@i: The number of rows to free.

This function iterates over each row in the matrix, freeing memory for 
each row. It then frees the top-level pointer for the matrix itself. */
void	free_matrix(t_dot **matrix, int i)
{
	while (i > 0)
	{
		i--;
		free(matrix[i]);
	}
	free(matrix);
}

/*	free_array - Frees memory allocated for an array of strings.
@array: The array of strings to be freed.

This function iterates over each string in the array, freeing each one, 
and then frees the top-level pointer for the array itself. */
void	free_array(char **array)
{
	char	**aux;

	aux = array;
	while (*aux)
	{
		free(*aux);
		aux++;
	}
	free(array);
}

/*	error_exit - Prints an error message to the stdout and exits the program.
@error_message: The error message to be displayed.

This function writes the error message to the standard output and exits the 
program with a failure status. It is used for handling fatal errors. */
void	error_exit(const char *error_message)
{
	write(1, error_message, ft_strlen(error_message));
	exit (-1);
}
