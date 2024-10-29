/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:32:54 by igchurru          #+#    #+#             */
/*   Updated: 2024/10/29 15:47:06 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../MLX42/include/MLX42/MLX42.h"

/*	populate_matrix - Fills the matrix with points based on the map file.
@matrix: 2D array of points to populate.
@route_to_map: Path to the map file.
@map: Struct containing map information and parameters.

This function reads the map file line by line, splits each line into 
individual values, and assigns each value as the z-coordinate of 
a point in the matrix. Each point’s x and y coordinates are set 
according to their position in the matrix. */
void	populate_matrix(t_dot **matrix, char *route_to_map, t_map *map)
{
	int		fd;
	char	*line;
	char	**split_line;
	int		i;
	int		j;

	fd = open(route_to_map, O_RDONLY);
	i = 0;
	while (i < map->map_rows)
	{
		line = get_next_line(fd);
		split_line = ft_split(line, ' ');
		j = 0;
		while (j < map->map_cols)
		{
			matrix[i][j].x = j;
			matrix[i][j].y = i;
			matrix[i][j].z = ft_atoi(split_line[j]);
			j++;
		}
		free(line);
		free_array(split_line);
		i++;
	}
	close(fd);
}

/*	build_matrix - Allocates memory for the 2D matrix based on map dimensions.
@map: Struct containing map dimensions.

This function allocates memory for the 2D matrix of points based on 
the number of rows and columns specified in the map struct. It initializes 
each element in the matrix to zero and returns a pointer to the matrix.
If allocation fails at any row, the function frees allocated memory and 
exits with an error. */
t_dot	**build_matrix(t_map *map)
{
	t_dot	**matrix;
	int		i;

	i = 0;
	matrix = (t_dot **)malloc(map->map_rows * sizeof(t_dot *));
	if (matrix == NULL)
		return (NULL);
	while (i < map->map_rows)
	{
		matrix[i] = (t_dot *)malloc(map->map_cols * sizeof(t_dot));
		if (!matrix[i])
		{
			free_matrix(matrix, i);
			error_exit("Error while building matrix\n");
		}
		ft_bzero(matrix[i], (map->map_cols * sizeof(t_dot)));
		i++;
	}
	return (matrix);
}

/*	measure_map - Calculates the number of rows and columns in the map file.
@fd: File descriptor for the open map file.
@map: Struct to store the calculated dimensions.

This function reads each line of the map file to count the total number 
of rows. For the first row, it splits the line by spaces to determine 
the number of columns. These dimensions are then saved in the map struct. */
void	measure_map(int fd, t_map *map)
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
			free_array(split_line);
		}
		free(line);
		i++;
	}
	map->map_rows = i;
	map->map_cols = j;
	close(fd);
}

/*	parse_map - Main function to parse the map file and initialize matrix.
@argv1: Map file name provided as a command-line argument.
@map: Struct to hold map parameters and generated matrix.

This function builds the full path to the map file, opens it, and 
calculates the map dimensions using measure_map. It then allocates 
and populates the matrix. Finally, it calculates the total number 
of dots and initializes the center coordinates. */
t_dot	**parse_map(char *argv1, t_map *map)
{
	int		fd;
	char	*route_to_map;
	t_dot	**matrix;

	route_to_map = ft_strjoin("./maps/", argv1);
	fd = open(route_to_map, O_RDONLY);
	if (fd < 0)
	{
		free(route_to_map);
		error_exit("Cannot open map.\n");
	}
	measure_map(fd, map);
	matrix = build_matrix(map);
	close(fd);
	populate_matrix(matrix, route_to_map, map);
	free(route_to_map);
	map->total_dots = map->map_rows * map->map_cols;
	map->center_x = 0;
	map->center_y = 0;
	map->matrix = matrix;
	return (matrix);
}
