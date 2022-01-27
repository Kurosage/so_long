/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chek_map_valid1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaren <rmaren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 18:55:01 by rmaren            #+#    #+#             */
/*   Updated: 2022/01/27 20:34:07 by rmaren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	reading_and_chking_map(char *file, t_var *vars)
{
	readin(file, vars);
	check_format(vars);
	check_upanddown(vars);
	check_middle(vars);
}

void	readin(char *file, t_var *vars)
{
	vars->fd = open(file, O_RDWR);
	if (vars->fd == 0)
		exit_from_game(1, vars);
	vars->last = ft_strrchr(file, '.');
	if (vars->last == 0 || ft_strcmp(vars->last, ".ber"))
		exit_from_game(1, vars);
	vars->last = NULL;
	vars->all_line = malloc(1);
	if (vars->all_line == NULL)
		exit(1);
	vars->all_line[0] = '\0';
	vars->last = get_next_line(vars->fd);
	if (vars->last == NULL)
		exit_from_game(2, vars);
	if (!ft_strncmp(vars->last, "\n", 1))
		exit_from_game(3, vars);
	while (vars->last)
	{
		vars->all_line = ft_strjoin(vars->all_line, vars->last);
		free(vars->last);
		vars->last = get_next_line(vars->fd);
	}
	free(vars->last);
	close(vars->fd);
}

void	check_format(t_var *vars)
{
	int		i;

	if (ft_strstr(vars->all_line, "\n\n1"))
		exit_from_game(4, vars);
	check_elements_count(vars);
	vars->mas_map = ft_split(vars->all_line, '\n');
	vars->height = 0;
	while (vars->mas_map[vars->height])
		vars->height++;
	if (vars->height < 3)
		exit_from_game(5, vars);
	free(vars->all_line);
	vars->length = ft_strlen(vars->mas_map[0]);
	if (vars->length < 3)
		exit_from_game(6, vars);
	i = 0;
	while (vars->mas_map[++i])
		if (vars->length != ft_strlen(vars->mas_map[i]))
			exit_from_game(7, vars);
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
					&& vars->mas_map[i][j] != 'P' && vars->mas_map[i][j] != 'W')
			{
				ft_putstr_fd("Invalid map character\n", 1);
				exit(1);
			}
		}
	}
}
