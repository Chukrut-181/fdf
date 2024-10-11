/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:32:54 by igchurru          #+#    #+#             */
/*   Updated: 2024/10/11 08:57:18 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../MLX42/include/MLX42/MLX42.h"

/* bool is_rectangular(t_dot *array)
{
	return(true);
} */

void	create_dot(t_dot **array, char *string, int x, int y)
{
	array[x][y].Xcoord = x;
	array[x][y].Ycoord = y;
	array[x][y].Zcoord = ft_atoi(string);
}

void	compose_matrix(int fd, t_dot **array)
{
	char	*line;
	char	**element;
	int		x;
	int		y;
	
	x = 0;
	while(true)
	{
		line = get_next_line(fd);
		if(!line)
			break;
		element = ft_split(line, ' ');
		free(line);
		y = 0;
		while (*element)
		{
			create_dot(array, *element, x, y);
			y++;
			element++;
		}
		x++;		
	}
}

void	parse_map(char *argv1, t_dot **array)
{
	int 	fd;
	char	*route_to_map;
	
	route_to_map = ft_strjoin("./maps/", argv1);	
	fd = open(route_to_map);
	if (fd < 0)
	{
		free(route_to_map);
		error_exit("Failed to open map\n");
	}
	free(route_to_map);
	compose_matrix(fd, array);

}
