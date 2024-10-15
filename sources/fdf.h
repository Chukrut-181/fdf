/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:22:58 by igchurru          #+#    #+#             */
/*   Updated: 2024/10/15 13:48:20 by igchurru         ###   ########.fr       */
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
	int 	X;
	int 	Y;
    char	*Zcoord;
	int		Z;
	struct s_dot	*next_col;
	struct s_dot	*next_row;
}	t_dot;

//	MAIN.C
int		main(int argc, char **argv);

//	ERROR.C
void    error_exit(const char *error_message);

//	FIL_DE_FER.C
void	fil_de_fer();
//void	draw_rect(mlx_image_t *img, uint32_t x, uint32_t y, int width, int height, uint32_t color);

//  PARSE_MAP.C
void	parse_map(char *argv1, t_dot **matrix);
void	build_matrix(int fd, t_dot **matrix);
void	populate_matrix(t_dot **matrix, char *line);

//  GET_NEXT_LINE.C
char	*get_next_line(int fd);
char	*ft_send_to_print(char *storage);
char	*ft_trim_storage(char *storage);

//	GET_NEXT_LINE_UTILS.C
void	*ft_gnl_calloc(size_t count, size_t size);
size_t	ft_gnl_strlen(const char *s);
char	*ft_gnl_strchr(const char *s, int c);
char	*ft_gnl_strjoin(char *storage, char *buffer);

#endif