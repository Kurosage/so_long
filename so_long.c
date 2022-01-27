/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaren <rmaren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 18:55:06 by rmaren            #+#    #+#             */
/*   Updated: 2022/01/27 20:38:31 by rmaren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_from_game(int i, t_var *vars)
{
	if (i == 1)
		ft_putstr_fd("Error.Invalid file\n", 1);
	if (i == 2)
		ft_putstr_fd("Mapfile is empty\n", 1);
	if (i == 3)
		ft_putstr_fd("Mapfile invalid\n", 1);
	if (i == 4)
		ft_putstr_fd("Invalid map: empty lines and text after\n", 1);
	if (i == 5)
		ft_putstr_fd("Invalid map: short height\n", 1);
	if (i == 6)
		ft_putstr_fd("Invalid map: short length\n", 1);
	if (i == 7)
		ft_putstr_fd("Invalid map: Lines has different length\n", 1);
	if (i == 8)
		ft_putstr_fd("Map has invalid count of special elements\n", 1);
	for_free(vars);
	exit(1);
}

int	exit_lose_win(int i, t_var *vars)
{
	if (i == 1)
		ft_putstr_fd("You win!!!\n", 1);
	if (i == 2)
		ft_putstr_fd("You lose!\n", 1);
	if (i == 3)
		ft_putstr_fd("You close game!\n", 1);
	for_free(vars);
	exit(0);
}

void	for_free(t_var *vars)
{
	int	j;

	j = 0;
	while (j < vars->height)
		free(vars->mas_map[j++]);
	free(vars->mas_map);
}

void	warrior_move(t_var *vars, int i, int j)
{
	if (vars->mas_map[i][j - 1] != '1' && vars->mas_map[i][j - 1] != 'E'
		&& vars->mas_map[i][j - 1] != 'C' && vars->mas_map[i][j - 1] != 'W'
			&& vars->flag.right % 2 == 0)
	{
		if (vars->mas_map[i][j - 1] == 'P')
			exit_lose_win(2, vars);
		vars->mas_map[i][j - 1] = 'W';
		vars->mas_map[i][j] = '0';
		vars->flag.right++;
	}
	else if (vars->mas_map[i][j + 1] != '1' && vars->mas_map[i][j + 1] != 'E'
		&& vars->mas_map[i][j + 1] != 'C' && vars->mas_map[i][j + 1] != 'W'
			&& vars->flag.right % 2 == 1)
	{
		if (vars->mas_map[i][j + 1] == 'P')
			exit_lose_win(2, vars);
		vars->mas_map[i][j + 1] = 'W';
		vars->mas_map[i][j] = '0';
		vars->flag.right++;
	}
	else
		vars->flag.right++;
}

int	main(int argc, char **argv)
{
	t_var	vars;

	vars.flag.left = 0;
	vars.flag.right = 0;
	vars.posit.item = 0;
	vars.steps = 0;
	if (argc == 2)
	{
		reading_and_chking_map(argv[1], &vars);
		map_drawing(&vars);
		for_free(&vars);
	}
	else
	{
		ft_putstr_fd("Invalid number of argument.\n \
			Correct: ./so_long [map_name]\n", 1);
		exit (1);
	}
	return (0);
}
