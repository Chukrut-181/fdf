/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:32:54 by igchurru          #+#    #+#             */
/*   Updated: 2024/10/09 15:58:32 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../MLX42/include/MLX42/MLX42.h"

void	parse_map(char *argv1)
{
	int 	fd;
	char	*route_to_map;
	int i;
	
	route_to_map = ft_strjoin("./maps/", argv1);	
	fd = open(route_to_map);
	if (fd < 0)
	{
		free(route_to_map);
		error_exit("Failed to open map\n");
	}
	i = 0;
	while (get_next_line(fd))
	{
		
	}
}

