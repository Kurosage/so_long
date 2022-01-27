/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_anim_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaren <rmaren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 20:16:30 by rmaren            #+#    #+#             */
/*   Updated: 2022/01/27 20:29:13 by rmaren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_anim2(t_var *vars, int i, int j)
{
	if (vars->mas_map[i][j] == 'P')
	{
		vars->posit.x = j;
		vars->posit.y = i;
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->tex.backg, SIZE * j, SIZE * i);
	}
	if (vars->mas_map[i][j] == 'C')
	{
		vars->posit.item++;
		if (vars->flag.down % 50 == 0)
		{
			mlx_put_image_to_window(vars->mlx, vars->mlx_win,
				vars->tex.backg, SIZE * j, SIZE * i);
			mlx_put_image_to_window(vars->mlx, vars->mlx_win,
				vars->tex.collect, SIZE * j, SIZE * i);
		}
		else if (vars->flag.down % 50 == 25)
		{
			mlx_put_image_to_window(vars->mlx, vars->mlx_win,
				vars->tex.backg, SIZE * j, SIZE * i);
			mlx_put_image_to_window(vars->mlx, vars->mlx_win,
				vars->tex.collect2, SIZE * j, SIZE * i);
		}
	}
}

void	draw_anim3(t_var *vars, int i, int j)
{
	if (vars->mas_map[i][j] == 'E')
	{
		if (vars->posit.it == 0)
			mas_door(vars, i, j);
		else
			mlx_put_image_to_window(vars->mlx, vars->mlx_win,
				vars->tex.exit, SIZE * j, SIZE * i);
	}
	if (vars->mas_map[i][j] == 'W')
	{
		timer2(vars);
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->tex.backg, SIZE * j, SIZE * i);
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->tex.warrior, SIZE * j, SIZE * i);
		if (vars->flag.left % 150 == 0)
			warrior_move(vars, i, j);
		else
			vars->flag.right++;
		if (vars->flag.right > 10000 || vars->flag.right < 1)
			vars->flag.right = 100;
	}
}

int	draw_anim(t_var *vars)
{
	int	i;
	int	j;

	timer(vars);
	i = -1;
	vars->posit.item = 0;
	while (vars->mas_map[++i])
	{
		j = -1;
		while (vars->mas_map[i][++j])
		{
			if (vars->mas_map[i][j] == '0')
				mlx_put_image_to_window(vars->mlx, vars->mlx_win,
					vars->tex.backg, SIZE * j, SIZE * i);
			else
			{
				draw_anim2(vars, i, j);
				draw_anim3(vars, i, j);
			}
		}
	}
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->tex.hero,
		SIZE * vars->posit.x, SIZE * vars->posit.y);
	vars->posit.it = vars->posit.item;
	return (0);
}

void	timer(t_var *vars)
{
	vars->flag.down++;
	if ((vars->flag.down % 50 == 0 || vars->flag.down % 50 == 25)
		&& vars->flag.down != 1001)
	{
		return ;
	}
	else if (vars->flag.down > 1001)
	{
		vars->flag.down = 0;
		return ;
	}
	else
	{
		vars->flag.down++;
	}
}

void	timer2(t_var *vars)
{
	vars->flag.left++;
	if ((vars->flag.left % 50 == 0 || vars->flag.down % 50 == 25)
		&& vars->flag.left != 1001)
	{
		return ;
	}
	else if (vars->flag.left == 1001)
	{
		vars->flag.left = 0;
		return ;
	}
	else
	{
		vars->flag.left++;
	}
}
