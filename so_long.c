#include "so_long.h"

void	exit_from_game()
{

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
int	main(int argc, char **argv)
{
	t_var	vars;
	//void	*mlx;
	//void	*mlx_win;
	// mlx = mlx_init();
	// mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	// mlx_loop(mlx);
	if (argc == 2)
	{
		reading_and_chking_map(argv[1], &vars);
	}
	else
		exit_from_game();
	return (0);
}
