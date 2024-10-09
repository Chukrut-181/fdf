/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:22:58 by igchurru          #+#    #+#             */
/*   Updated: 2024/10/09 11:57:54 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "math.h"

//	MAIN.C
int		main(int argc, char **argv);

//	ERROR.C
void    error_exit(const char *error_message);

//	FIL_DE_FER.C
void	fil_de_fer();
//void	draw_rect(mlx_image_t *img, uint32_t x, uint32_t y, int width, int height, uint32_t color);

#endif