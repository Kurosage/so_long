/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaren <rmaren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 19:53:49 by rmaren            #+#    #+#             */
/*   Updated: 2022/01/27 20:53:50 by rmaren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	left(t_var *vars)
{
	vars->tex.hero = vars->tex.herol;
	if (vars->mas_map[vars->posit.y][vars->posit.x - 1] != '1'
		&& vars->mas_map[vars->posit.y][vars->posit.x - 1] != 'E'
			&& vars->mas_map[vars->posit.y][vars->posit.x - 1] != 'W')
	{
		vars->steps++;
		vars->mas_map[vars->posit.y][vars->posit.x - 1] = 'P';
		vars->mas_map[vars->posit.y][vars->posit.x] = '0';
	}
	else if (vars->mas_map[vars->posit.y][vars->posit.x - 1] == 'C')
	{
		vars->steps++;
		vars->mas_map[vars->posit.y][vars->posit.x - 1] = 'P';
		vars->mas_map[vars->posit.y][vars->posit.x] = '0';
	}
	else if (vars->mas_map[vars->posit.y][vars->posit.x - 1] == 'E'
		&& vars->posit.it == 0)
		exit_lose_win(1, vars);
	else if (vars->mas_map[vars->posit.y][vars->posit.x - 1] == 'W')
		exit_lose_win(2, vars);
}

void	right(t_var *vars)
{
	vars->tex.hero = vars->tex.heror;
	if (vars->mas_map[vars->posit.y][vars->posit.x + 1] != '1'
		&& vars->mas_map[vars->posit.y][vars->posit.x + 1] != 'E'
			&& vars->mas_map[vars->posit.y][vars->posit.x + 1] != 'W')
	{
		vars->steps++;
		vars->mas_map[vars->posit.y][vars->posit.x + 1] = 'P';
		vars->mas_map[vars->posit.y][vars->posit.x] = '0';
	}
	else if (vars->mas_map[vars->posit.y][vars->posit.x + 1] == 'C')
	{
		vars->steps++;
		vars->mas_map[vars->posit.y][vars->posit.x + 1] = 'P';
		vars->mas_map[vars->posit.y][vars->posit.x] = '0';
	}
	else if (vars->mas_map[vars->posit.y][vars->posit.x + 1] == 'E'
		&& vars->posit.it == 0)
		exit_lose_win(1, vars);
	else if (vars->mas_map[vars->posit.y][vars->posit.x + 1] == 'W')
		exit_lose_win(2, vars);
}

void	down(t_var *vars)
{
	vars->tex.hero = vars->tex.heroup;
	if (vars->mas_map[vars->posit.y + 1][vars->posit.x] != '1'
		&& vars->mas_map[vars->posit.y + 1][vars->posit.x] != 'E'
			&& vars->mas_map[vars->posit.y + 1][vars->posit.x] != 'W')
	{
		vars->steps++;
		vars->mas_map[vars->posit.y + 1][vars->posit.x] = 'P';
		vars->mas_map[vars->posit.y][vars->posit.x] = '0';
	}
	else if (vars->mas_map[vars->posit.y + 1][vars->posit.x] == 'C')
	{
		vars->steps++;
		vars->mas_map[vars->posit.y + 1][vars->posit.x] = 'P';
		vars->mas_map[vars->posit.y][vars->posit.x] = '0';
	}
	else if (vars->mas_map[vars->posit.y + 1][vars->posit.x] == 'E'
		&& vars->posit.it == 0)
		exit_lose_win(1, vars);
	else if (vars->mas_map[vars->posit.y + 1][vars->posit.x] == 'W')
		exit_lose_win(2, vars);
}

void	up(t_var *vars)
{
	vars->tex.hero = vars->tex.herob;
	if (vars->mas_map[vars->posit.y - 1][vars->posit.x] != '1'
		&& vars->mas_map[vars->posit.y - 1][vars->posit.x] != 'E'
			&& vars->mas_map[vars->posit.y - 1][vars->posit.x] != 'W')
	{
		vars->steps++;
		vars->mas_map[vars->posit.y - 1][vars->posit.x] = 'P';
		vars->mas_map[vars->posit.y][vars->posit.x] = '0';
	}
	else if (vars->mas_map[vars->posit.y - 1][vars->posit.x] == 'C')
	{
		vars->steps++;
		vars->mas_map[vars->posit.y - 1][vars->posit.x] = 'P';
		vars->mas_map[vars->posit.y][vars->posit.x] = '0';
	}
	else if (vars->mas_map[vars->posit.y - 1][vars->posit.x] == 'E'
		&& vars->posit.it == 0)
		exit_lose_win(1, vars);
	else if (vars->mas_map[vars->posit.y - 1][vars->posit.x] == 'W')
		exit_lose_win(2, vars);
}

int	move(int keycode, t_var *vars)
{
	if (keycode == 13 || keycode == 126)
		up(vars);
	else if (keycode == 0 || keycode == 123)
		left(vars);
	else if (keycode == 1 || keycode == 125)
		down(vars);
	else if (keycode == 2 || keycode == 124)
		right(vars);
	draw_only(vars);
	if (keycode == 53)
		exit_lose_win(3, vars);
	return (0);
}
