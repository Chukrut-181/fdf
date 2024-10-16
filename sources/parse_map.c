/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:32:54 by igchurru          #+#    #+#             */
/*   Updated: 2024/10/16 12:05:56 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../MLX42/include/MLX42/MLX42.h"

void	populate_matrix(t_dot **matrix, char *route_to_map, int rows, int cols)
{
	int		fd;
	char	*line;
	char	**split_line;
	int		i;
	int		j;

	fd = open(route_to_map, O_RDONLY);
	i = 0;
	while (i < rows)
	{
		line = get_next_line(fd);
		split_line = ft_split(line, ' ');
		j = 0;
		while (j < cols)
		{
			matrix[i][j].x = j;
			write(1, "coucou\n", 7);
			matrix[i][j].y = i;
			matrix[i][j].z = ft_atoi(split_line[j]);
			printf("X = %i, Y = %i, Z = %i\n", matrix[i][j].x, matrix[i][j].y, matrix[i][j].z);
			j++;
		}
		free(line);
		i++;
	}
	close(fd);
}

t_dot	**build_matrix(int n_of_rows, int n_of_cols)
{
	t_dot	**matrix;
	int		i;

	i = 0;
	matrix = (t_dot **)malloc(n_of_rows * sizeof(t_dot *));
	if (matrix == NULL)
		return (NULL);
	while (i < n_of_rows)
	{
		matrix[i] = (t_dot *)malloc(n_of_cols * sizeof(t_dot));
		if (!matrix[i])
		{
			while (0 < i)
			{
				free(matrix[i]);
				i--;
			}
			free(matrix);
			return (NULL);
		}
		i++;
	}
	return (matrix);
}

void	measure_map(int fd, int	*n_of_rows, int *n_of_cols)
{
	int		i;
	int		j;
	char	*line;
	char	**split_line;

	i = 0;
	j = 0;
	while (true)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (j == 0)
		{
			split_line = ft_split(line, ' ');
			while (split_line[j])
				j++;
		}
		free(line);
		i++;
	}
	*n_of_rows = i;
	*n_of_cols = j;
	close(fd);
}

t_dot	**parse_map(char *argv1)
{
	int		fd;
	char	*route_to_map;
	int		n_of_rows;
	int		n_of_cols;
	t_dot	**matrix;

	route_to_map = ft_strjoin("./maps/", argv1);
	fd = open(route_to_map, O_RDONLY);
	if (fd < 0)
	{
		free(route_to_map);
		error_exit("Cannot open map.\n");
	}
	measure_map(fd, &n_of_rows, &n_of_cols);
	printf("%i, %i\n", n_of_rows, n_of_cols);
	matrix = build_matrix(n_of_rows, n_of_cols);
	close(fd);
	populate_matrix(matrix, route_to_map, n_of_rows, n_of_cols);
	free(route_to_map);
	return (matrix);
}
