/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoloher <tsoloher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:07:39 by tsoloher          #+#    #+#             */
/*   Updated: 2023/12/19 16:22:00 by tsoloher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>


int main(int ac, char **av)
{
    t_struct *data;
    
    data = malloc(sizeof(t_struct));
    read_file1(av[1], data);
    
    int i;
    int j;
    
    i = 0;
    while (i < data ->height)
    {
        j = 0;
        while (j < data -> width)
        {
            printf("%d", data ->map[i][j]);
            i++;
        }
        printf("\n");
        j++;
    }
     return 0;
}