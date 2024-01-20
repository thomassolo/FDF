/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoloher <tsoloher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:02:52 by tsoloher          #+#    #+#             */
/*   Updated: 2024/01/20 17:16:40 by tsoloher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#   define FDF_H

#include "Libft/libft.h"
#include "minilibx-linux/mlx.h"
#include <fcntl.h>
#include <math.h>
#include <stdio.h>

/*typedef struct 
{
    int width;
    int height;
    int **matrix;
    
}       t_struct;*/

/*typedef struct 
{
    int x;
    int y;
    int z;
}       map3D;*/

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
    void	*mlx;
	void	*mlx_win;
    int     zoom;
    int     color;

    int width;
    int height;
    int **matrix;
}				mlx_data;



void read_file1(char *file_name, mlx_data *data);
int get_height(char *file_name);
int get_width(char *file_name);
//void print_error(char *message);
void isometric(int *x, int *y, int z);
void my_mlx_pixel_put(mlx_data *data, int x, int y, int color);
void link_dots(mlx_data *img, int x, int y, int x1, int y1);
void ft_draw(mlx_data *img);



#endif