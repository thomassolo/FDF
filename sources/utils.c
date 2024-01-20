#include "../fdf.h"

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

int get_width(char *file_name)
{
    char *line;
    int fd;
    int width;
    
    fd = open(file_name, O_RDONLY);
    if (fd < 0)
    return 0;
    while((line = get_next_line(fd)))
        width = count_words(line, ' ');     
    free(line);
    close(fd);
    return(width);
}

int get_height(char *file_name)
{
    char *line;
    int fd;
    int height;
    
    fd = open(file_name, O_RDONLY);
    if(fd < 0)
        return 0;
    height = 0;
    while ((line = get_next_line(fd)))
    {
        
        if (!line)
            break;
        height++;
        free(line);
    }
    close(fd);
    return(height);
}

void fill_map(int *z_line, char *line)
{
    char **nums;
    int i;

    i = 0;
    nums = ft_split(line, ' ');
    if (nums == NULL)
        return ;
    while (nums[i])
    {
        z_line[i] = ft_atoi(nums[i]);
        free(nums[i]);
        i++;   
    }
    
    free(nums);
}

void read_file1(char *file_name, mlx_data *data)
{
    int fd;
    char *line;
    int i;
    
    data->height = get_height(file_name);
    data->width = get_width(file_name);
   
    data->matrix = (int**)malloc(sizeof(int *) * (data->height + 1));
    if (!data->matrix)
        return ;
    i = 0; 
    while (i < data->height)
    {
        data->matrix[i] = (int *)malloc(sizeof(int) * (data->width + 1));
        if (!data->matrix[i])
            return ;
        i++;
    }
    i = 0;
    fd = open(file_name, O_RDONLY);
    if(fd < 0)
        return ;
    while((line = get_next_line(fd)))
    {
        if (!line)
            break;
        fill_map(data->matrix[i], line);  
        free(line);
        i++;
    }
    close(fd);
    data->matrix[i] = NULL;
    
}



/*void print_error(char *message)
{
    printf(message);
    exit(EXIT_FAILURE);
}*/

void	my_mlx_pixel_put(mlx_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void isometric(int *x, int *y, int z)
{
    int temp_x;
    int temp_y;

    temp_x = *x;
    temp_y = *y;
   *x = (temp_x - temp_y) * cos(0.5);
    *y = (temp_x + temp_y) * sin(0.5) - z;
}

void link_dots(mlx_data *ptr, int x, int y, int x1, int y1)
{
    int dx;
    int dy;
    int p;
    int x_incr;
    int y_incr;
    int z;
    int z1;

    z = ptr->matrix[y][x];
    z1 = ptr->matrix[y1][x1];
    x *= ptr->zoom;
    y *= ptr->zoom;
    x1 *= ptr->zoom;
    y1 *= ptr->zoom;
    if (z > 0 || z1 > 0)
        ptr->color = 0x10D9F1;
    else
        ptr->color = 0xffffff;
    isometric(&x, &y, z);
    isometric(&x1, &y1, z1);
    x += 300;
    y += 300;
    x1 += 300;
    y1 += 300;
    dx = x1 - x;
    dy = y1 - y;
    x_incr = x;
    y_incr = y;
    p = 2 * dy - dx;

    if (dx == 0) 
    {
        while (y_incr < y1) 
        {
            my_mlx_pixel_put(ptr, x_incr, y_incr, ptr->color);
            y_incr++;
        }
    } 
    else
     {
        while (x_incr < x1)
         {
            my_mlx_pixel_put(ptr, x_incr, y_incr, ptr->color);
            if (p >= 0)
            {
                p = p + 2 * dy - 2 * dx;
                y_incr++;
            } 
            else 
                p = p + 2 * dy;
            x_incr++;
        }
    }
}


void ft_draw(mlx_data *ptr)
{
    int x;
    int y;

    y = 0;
    while (y < ptr->height)
    {
        x = 0;
        while (x < ptr->width)
        {
            if(x < ptr->width - 1)
                link_dots(ptr, x, y, x + 1, y);
            if(y < ptr->height - 1)
                link_dots(ptr, x, y, x, y + 1);
             x++;
        }
            y++;   
    }
}