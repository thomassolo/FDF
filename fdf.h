/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoloher <tsoloher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:02:52 by tsoloher          #+#    #+#             */
/*   Updated: 2023/12/19 16:22:24 by tsoloher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#   define FDF_H

#include "Libft/libft.h"
#include "minilibx-linux/mlx.h"
#include <fcntl.h>

typedef struct 
{
    int width;
    int height;
    int **map;

      
}       t_struct;

void read_file1(char *file_name, t_struct *data);



#endif