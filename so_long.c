#include "so_long.h"

int	exit_from_game()
{
	ft_putstr_fd("You closed game\n",1);
	exit(1);
}	
void	check_elements_count(t_var *vars)
{
	int	ccount;
	int	ecount;
	int	pcount;

	ccount = 0;
	ecount = 0;
	pcount = 0;
	vars->length = -1;
	while (vars->all_line[++vars->length])
	{
		if (vars->all_line[vars->length] == 'C')
			ccount++;
		if (vars->all_line[vars->length] == 'E')
			ecount++;
		if (vars->all_line[vars->length] == 'P')
			pcount++;
	}
	vars->posit.item = ccount;
	if (ccount < 1 || ecount < 1 || pcount != 1)
	{
		ft_putstr_fd("Map has invalid count of special elements", 1);
		exit(1);
	}
}

void	check_format(char *file, t_var *vars)
{
	char	*last;
	int		fd;
	int		i;

	fd = open(file, O_RDWR);
	if (fd == 0)
	{
		write(1, "Error.Invalid file", 1);
		exit (1);
	}
	last = ft_strrchr(file, '.');
	if (ft_strcmp(last, ".ber"))
	{
		write(1, "Uncorrect file format\n", 22);
		exit(1);
	}
	last = NULL;
	vars->all_line = malloc(1);
	if (vars->all_line == NULL)
		exit(1);
	vars->all_line[0] = '\0';
	last = get_next_line(fd);
	if (last == NULL)
	{
		write(1, "Mapfile is empty\n", 17);
		exit(1);
	}
	while (last)
	{
		vars->all_line = ft_strjoin(vars->all_line, last);
		free(last);
		last = get_next_line(fd);
	}
	//printf("%s", vars->all_line);
	free(last);
	close(fd);
	if (ft_strstr(vars->all_line, "\n\n1"))
	{
		printf("Invalid map: empty lines and text after\n");
		exit(1);
	}
	check_elements_count(vars);
	vars->mas_map = ft_split(vars->all_line, '\n');
	//vars->height= -1;
	// while (vars->mas_map[++vars->height])
	// 	printf("%s\n",vars->mas_map[vars->height]);
	vars->height = 0;
	while (vars->mas_map[vars->height])
		vars->height++;
	if (vars->height < 3)
	{
		printf("Invalid map: short height\n");
		exit(1);
	}
	//printf("%i",vars->length);
	free(vars->all_line);
	vars->length = ft_strlen(vars->mas_map[0]);
	if (vars->length < 3)
	{
		printf("Invalid map: short length\n");
		exit(1);
	}
	i = 0;
	while (vars->mas_map[++i])
	{
		if (vars->length != ft_strlen(vars->mas_map[i]))
		{
			printf("Invalid map: Length\n");
			exit(1);
		}
		//printf("ok\n");
	}
}

void	check_upanddown(t_var *vars)
{
	int	i;

	i = -1;
	while (vars->mas_map[0][++i])
	{
		if (vars->mas_map[0][i] != '1')
		{
			ft_putstr_fd("Invalid map character\n", 1);
			exit(1);
		}
	}
	i = -1;
	while (vars->mas_map[vars->height - 1][++i])
	{
		if (vars->mas_map[vars->height - 1][i] != '1')
		{
			ft_putstr_fd("Invalid map character\n", 1);
			exit(1);
		}
	}
}

void	check_middle(t_var *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->mas_map[++i])
	{
		if (vars->mas_map[i][0] != '1'
			|| vars->mas_map[i][vars->length - 1] != '1')
		{
			ft_putstr_fd("Invalid map character\n", 1);
			exit(1);
		}
		j = 0;
		while (vars->mas_map[i][++j])
		{
			if (vars->mas_map[i][j] != '1' && vars->mas_map[i][j] != '0'
				&& vars->mas_map[i][j] != 'C' && vars->mas_map[i][j] != 'E'
					&& vars->mas_map[i][j] != 'P')
			{
				ft_putstr_fd("Invalid map character\n", 1);
				exit(1);
			}
		}
	}

}

void	reading_and_chking_map(char *file, t_var *vars)
{
	//int		i;
	//int		gnl;
	//char	**mas_map;

	check_format(file, vars);
	check_upanddown(vars);
	check_middle(vars);
	// while ()
	// {
	//     mas_map[i++] = get_next_line(fd);
	// }
}

void	for_free(t_var *vars)
{
	int	j;

	j = 0;
	while (j < vars->height)
		free(vars->mas_map[j++]);
	free(vars->mas_map);
}
void	define_textures(t_var *vars)
{
	int	width;
	int	height;

	vars->tex.backg = mlx_xpm_file_to_image(vars->mlx,"./texture/backg.xpm", &width, &height);
	vars->tex.collect = mlx_xpm_file_to_image(vars->mlx,"./texture/collect.xpm", &width, &height);
	vars->tex.wall = mlx_xpm_file_to_image(vars->mlx,"./texture/wall.xpm", &width, &height);
	vars->tex.hero = mlx_xpm_file_to_image(vars->mlx,"./texture/hero.xpm", &width, &height);
	vars->tex.exit = mlx_xpm_file_to_image(vars->mlx,"./texture/door.xpm", &width, &height);
	//printf("%i::%i\n", width, height);
}

int	draw_only(t_var *vars)
{
	int	i;
	int	j;

	i = -1;
	vars->posit.item = 0;
	while (vars->mas_map[++i])
	{
		j = -1;
		while (vars->mas_map[i][++j])
		{
			if (vars->mas_map[i][j] == '1')
				mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->tex.wall, 64 * j, 64 * i);
			else if (vars->mas_map[i][j] == 'P')
			{
				vars->posit.x = j;
				vars->posit.y = i;
				mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->tex.backg, 64 * j, 64 * i);
				mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->tex.hero, 64 * j, 64 * i);
			}
			else if (vars->mas_map[i][j] == '0')
				mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->tex.backg, 64 * j, 64 * i);
			else if (vars->mas_map[i][j] == 'C')
			{
				vars->posit.item++;
				mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->tex.backg, 64 * j, 64 * i);
				mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->tex.collect, 64 * j, 64 * i);
			}
			else if (vars->mas_map[i][j] == 'E')
				mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->tex.exit, 64 * j, 64 * i);
		}
	}
	return (0);
}
int	move(int keycode, t_var *vars)
{
	printf("%i\n",vars->posit.item);
	if (keycode == 13 || keycode == 126)
	{
		if (vars->mas_map[vars->posit.y - 1][vars->posit.x] != '1' && vars->mas_map[vars->posit.y - 1][vars->posit.x] != 'E')
		{
			vars->mas_map[vars->posit.y - 1][vars->posit.x] = 'P';
			vars->mas_map[vars->posit.y][vars->posit.x] = '0';
		}
		else if (vars->mas_map[vars->posit.y - 1][vars->posit.x] == 'E' && vars->posit.item == 0)
			exit(1);
		else if (vars->mas_map[vars->posit.y - 1][vars->posit.x] == 'C')
		{
			vars->mas_map[vars->posit.y - 1][vars->posit.x] = 'P';
			vars->mas_map[vars->posit.y][vars->posit.x] = '0';
			vars->posit.item--;
		}
	}
	if (keycode == 0 || keycode == 123)
	{
		if (vars->mas_map[vars->posit.y][vars->posit.x - 1] != '1' && vars->mas_map[vars->posit.y][vars->posit.x - 1] != 'E')
		{
			vars->mas_map[vars->posit.y][vars->posit.x - 1] = 'P';
			vars->mas_map[vars->posit.y][vars->posit.x] = '0';
		}
		else if (vars->mas_map[vars->posit.y][vars->posit.x - 1] == 'E' && vars->posit.item == 0)
			exit(1);
		else if (vars->mas_map[vars->posit.y][vars->posit.x - 1] == 'C')
		{
			vars->mas_map[vars->posit.y][vars->posit.x - 1] = 'P';
			vars->mas_map[vars->posit.y][vars->posit.x] = '0';
			vars->posit.item--;
		}
	}
	if (keycode == 1 || keycode == 125)
	{
		if (vars->mas_map[vars->posit.y + 1][vars->posit.x] != '1' && vars->mas_map[vars->posit.y + 1][vars->posit.x] != 'E')
		{
			vars->mas_map[vars->posit.y + 1][vars->posit.x] = 'P';
			vars->mas_map[vars->posit.y][vars->posit.x] = '0';
		}
		else if (vars->mas_map[vars->posit.y + 1][vars->posit.x] == 'E' && vars->posit.item == 0)
			exit(1);
		else if (vars->mas_map[vars->posit.y+ 1][vars->posit.x] == 'C')
		{
			vars->mas_map[vars->posit.y + 1][vars->posit.x] = 'P';
			vars->mas_map[vars->posit.y][vars->posit.x] = '0';
			vars->posit.item--;
		}
	}
	if (keycode == 2 || keycode == 124)
	{
		if (vars->mas_map[vars->posit.y][vars->posit.x + 1] != '1' && vars->mas_map[vars->posit.y][vars->posit.x + 1] != 'E')
		{
			vars->mas_map[vars->posit.y][vars->posit.x + 1] = 'P';
			vars->mas_map[vars->posit.y][vars->posit.x] = '0';
		}
		else if (vars->mas_map[vars->posit.y][vars->posit.x + 1] == 'E' && vars->posit.item == 0)
			exit(1);
		else if (vars->mas_map[vars->posit.y][vars->posit.x + 1] == 'C')
		{
			vars->mas_map[vars->posit.y][vars->posit.x + 1] = 'P';
			vars->mas_map[vars->posit.y][vars->posit.x] = '0';
		}
	}
	if (keycode == 53)
		exit(1);
	return (0);
}
void	map_drawing(t_var *vars)
{
	t_data	img;
	int		i;
	int		j;

	vars->mlx = mlx_init();
	if (vars->mlx == NULL)
	{
		ft_putstr_fd("Can't to connect with X-Server\n", 1);
		exit(1);
	}
	vars->mlx_win = mlx_new_window(vars->mlx, vars->length * 64, vars->height * 64, "so_long");
	define_textures(vars);
	//img.img = mlx_new_image(vars->mlx, 1920, 1080);
	//img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			//&img.line_length, &img.endian);
	//i = -1;
	//my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_loop_hook(vars->mlx, draw_only, vars);
	//mlx_key_hook(vars->mlx_win, move, vars);
	mlx_hook(vars->mlx_win, 2, 1L<<0, move, vars);
	//move(vars);
	//mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->tex.backg, 64, 64);
	//mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->tex.backg, 0, 0);
	mlx_hook(vars->mlx_win, 17, 0, exit_from_game, NULL);
	mlx_loop(vars->mlx);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
int	main(int argc, char **argv)
{
	t_var	vars;

	vars.posit.item = 0;
	if (argc == 2)
	{
		reading_and_chking_map(argv[1], &vars);
		map_drawing(&vars);
		for_free(&vars);
	}
	else
		exit_from_game();
	return (0);
}
