/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:22:39 by igchurru          #+#    #+#             */
/*   Updated: 2024/10/25 11:39:20 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"
#include "../MLX42/include/MLX42/MLX42.h"

void	free_matrix(t_dot **matrix, int i)
{
	while (i > 0)
	{
		i--;
		free(matrix[i]);
	}
	free(matrix);
}

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

void	error_exit(const char *error_message)
{
	write(1, error_message, ft_strlen(error_message));
	exit (-1);
}
