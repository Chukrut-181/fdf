/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:32:54 by igchurru          #+#    #+#             */
/*   Updated: 2024/10/17 11:54:14 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../MLX42/include/MLX42/MLX42.h"

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
		i++;
	}
	return (matrix);
}

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
	return (matrix);
}
