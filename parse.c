/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoloher <tsoloher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:58:27 by tsoloher          #+#    #+#             */
/*   Updated: 2023/12/21 14:09:02 by tsoloher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	count_words(const char *s, char c)
{
	int	i;
	int	n_words;

	i = 0;
	n_words = 0;
	while (s[i] != 0)
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == 0))
			n_words++;
		i++;
	}
	return (n_words);
}
int get_height(char *file_name)
{
    char *line;
    int fd;
    int height;
    
    fd = open(file_name, O_RDONLY);
    while(get_next_line(fd))
    {
        height++;
        free(line);
    }
    close(fd);
    return(height);
}

int get_width(char *file_name)
{
    char *line;
    int fd;
    int width;
    
    fd = open(file_name, O_RDONLY);
    if (get_next_line(fd))
    {
        width = count_words(file_name, ' ');     
    }
    else
        width = 0;
    free(line);
    close(fd);
    return(width);
}

void fill_map(int *z_line,char * line)
{
    char **nums;
    int i;

    nums = ft_split(line, ' ');
    i = 0;
    while (nums[i])
    {
        z_line[i] = ft_atoi(nums[i]);
        free(nums[i]);
        i++;   
    }
    free(nums);
}
void read_file1(char *file_name, t_struct *data)
{
    int fd;
    char *line;
    int i;
    
    data -> height = get_height(file_name);
    data -> width = get_width(file_name);

    data -> map = malloc(sizeof(int *) * data -> height + 1);
    i = 0;
    fd = open(file_name, O_RDONLY);
    while (i < data -> height && (line = get_next_line(fd)))
    {
        data->map[i] = malloc(sizeof(int) * data->width);
        fill_map(data -> map[i], line);
        free(line);
        i++;
    }
    data -> map[i] = NULL;
    close(fd);
}