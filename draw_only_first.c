/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_only_first.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaren <rmaren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 19:46:51 by rmaren            #+#    #+#             */
/*   Updated: 2022/01/27 20:39:26 by rmaren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_wall(t_var *vars, int i, int j)
{
	if (i == 0 && j == 0)
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->tex.wallcor00, SIZE * j, SIZE * i);
	else if (i == vars->height - 1 && j == 0)
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->tex.wallcor01, SIZE * j, SIZE * i);
	else if (i == 0 && j == vars->length - 1)
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->tex.wallcor10, SIZE * j, SIZE * i);
	else if (i == vars->height - 1 && j == vars->length - 1)
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->tex.wallcor11, SIZE * j, SIZE * i);
	else if (i > 0 && i < vars->length - 1 && j == 0)
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->tex.wallleft, SIZE * j, SIZE * i);
	else if (j > 0 && j < vars->length - 1 && i == 0)
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->tex.wallup, SIZE * j, SIZE * i);
	else
		draw_wall2(vars, i, j);
}

void	draw_wall2(t_var *vars, int i, int j)
{
	if (i > 0 && i < vars->height - 1 && j == vars->length - 1)
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->tex.wallright, SIZE * j, SIZE * i);
	else if (j > 0 && j < vars->length - 1 && i == vars->height - 1)
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->tex.walldown, SIZE * j, SIZE * i);
	else
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->tex.wallcenter, SIZE * j, SIZE * i);
}

void	draw_another_characters(t_var *vars, int i, int j)
{
	if (vars->mas_map[i][j] == 'P')
	{
		vars->posit.x = j;
		vars->posit.y = i;
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->tex.backg, SIZE * j, SIZE * i);
	}
	else if (vars->mas_map[i][j] == '0')
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->tex.backg, SIZE * j, SIZE * i);
	else if (vars->mas_map[i][j] == 'C')
		vars->posit.item++;
	else if (vars->mas_map[i][j] == 'E')
	{
		if (vars->posit.it == 0)
			mlx_put_image_to_window(vars->mlx, vars->mlx_win,
				vars->tex.exit2[5], SIZE * j, SIZE * i);
		else
			mlx_put_image_to_window(vars->mlx, vars->mlx_win,
				vars->tex.exit, SIZE * j, SIZE * i);
	}
}

int	draw_only(t_var *vars)
{
	int		i;
	int		j;
	char	*step;

	i = -1;
	vars->posit.item = 0;
	while (vars->mas_map[++i])
	{
		j = -1;
		while (vars->mas_map[i][++j])
		{
			if (vars->mas_map[i][j] == '1')
				draw_wall(vars, i, j);
			else
				draw_another_characters(vars, i, j);
		}
	}
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->tex.hero,
		SIZE * vars->posit.x, SIZE * vars->posit.y);
	step = ft_itoa(vars->steps);
	mlx_string_put(vars->mlx, vars->mlx_win, 10, 10, 0, step);
	free(step);
	return (0);
}

void	mas_door(t_var *vars, int i, int j)
{
	static int	count;

	if (count == 5)
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->tex.exit2[5], SIZE * j, SIZE * i);
	while (count < 5)
	{
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->tex.exit2[count], SIZE * j, SIZE * i);
		count++;
	}
}
