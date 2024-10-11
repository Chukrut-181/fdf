/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:22:58 by igchurru          #+#    #+#             */
/*   Updated: 2024/10/11 09:50:05 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <math.h>

//  DOT STRUCTURE
typedef struct s_dot
{
	int Xcoord;
	int Ycoord;
    int Zcoord;
}	t_dot;

//	MAIN.C
int		main(int argc, char **argv);

//	ERROR.C
void    error_exit(const char *error_message);

//	FIL_DE_FER.C
void	fil_de_fer();
//void	draw_rect(mlx_image_t *img, uint32_t x, uint32_t y, int width, int height, uint32_t color);

//  PARSE_MAP.C
void	parse_map(char *argv1);

//  GET_NEXT_LINE.C
char	*get_next_line(int fd);
char	*ft_send_to_print(char *storage);
char	*ft_trim_storage(char *storage);

#endif