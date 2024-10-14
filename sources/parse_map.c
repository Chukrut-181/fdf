/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:32:54 by igchurru          #+#    #+#             */
/*   Updated: 2024/10/14 11:21:21 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../MLX42/include/MLX42/MLX42.h"


void	parse_map(char *argv1)
{
	int 			fd;
	char			*route_to_map;
	//static size_t	determined_length;
	char 			*line;
	//char			**line_parts;
	
	route_to_map = ft_strjoin("./maps/", argv1);
	fd = open(route_to_map, O_RDONLY);
	if (fd < 0)
	{
		free(route_to_map);
		error_exit("Failed to open map.\n");
	}
	printf("fd = %i\n", fd);
	free(route_to_map);
	//determined_length = 0;
	line = malloc(sizeof(char *));
	line = get_next_line(fd);
	printf("read: yeyeye %s\n", line);
	//free(line);
	close(fd);
}
