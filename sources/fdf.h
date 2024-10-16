/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:22:58 by igchurru          #+#    #+#             */
/*   Updated: 2024/10/16 12:28:45 by igchurru         ###   ########.fr       */
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
#include "../MLX42/include/MLX42/MLX42.h"

//  DOT STRUCTURE
typedef struct s_dot
{
	int				x;
	int				y;
	int				z;
	struct s_dot	*next_col;
	struct s_dot	*next_row;
}	t_dot;

//	MAIN.C
int		main(int argc, char **argv);

//	ERROR.C
void	error_exit(const char *error_message);

//	FIL_DE_FER.C
void	fil_de_fer(t_dot **matrix);

//  PARSE_MAP.C
t_dot	**parse_map(char *argv1);
t_dot	**build_matrix(int n_of_rows, int n_of_cols);
void	populate_matrix(t_dot **matrix, char *route_to_map, int rows, int cols);

//	RENDERIZE.C
void	render_matrix(mlx_image_t *img, t_dot **matrix, int n_of_rows, int n_of_cols);

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