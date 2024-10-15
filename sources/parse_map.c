/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:32:54 by igchurru          #+#    #+#             */
/*   Updated: 2024/10/15 13:51:33 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../MLX42/include/MLX42/MLX42.h"

void	populate_matrix(t_dot **matrix, char *line)
{
	char	**split_line;
	int		i;
	int		j;
	int		k;
	
	i = 0;
	split_line = ft_split(line, ' ');
	k = 0;
	while (split_line[k++])
	j = 0;
	matrix[i] = ft_calloc(k, sizeof(t_dot));
	while (split_line[j])
	{
		matrix[i][j].X = j;
		matrix[i][j].Y = i;
		matrix[i][j].Z = ft_atoi(split_line[j]);
		printf("X = %i, Y = %i, Z = %i\n", matrix[i][j].X, matrix[i][j].Y, matrix[i][j].Z);
		j++;
	}
	i++;
}

void	build_matrix(int fd, t_dot **matrix)
{
	char	*line;

	matrix = ft_calloc(1, sizeof(t_dot *));
	while (true)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		populate_matrix(matrix, line);
		free(line);
	}
}

void	parse_map(char *argv1, t_dot **matrix)
{
	int 			fd;
	char			*route_to_map;
	//char 			*line;
	
	route_to_map = ft_strjoin("./maps/", argv1);
	fd = open(route_to_map, O_RDONLY);
	if (fd < 0)
	{
		free(route_to_map);
		error_exit("Cannot open map.\n");
	}
	free(route_to_map);
	build_matrix(fd, matrix);
	close(fd);
}
