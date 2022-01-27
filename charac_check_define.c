/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charac_check_define.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaren <rmaren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 19:22:26 by rmaren            #+#    #+#             */
/*   Updated: 2022/01/27 20:35:04 by rmaren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_drawing(t_var *vars)
{
	int		i;

	vars->mlx = mlx_init();
	if (vars->mlx == NULL)
	{
		ft_putstr_fd("Can't to connect with X-Server\n", 1);
		exit(1);
	}
	i = -1;
	vars->mlx_win = mlx_new_window(vars->mlx,
			vars->length * SIZE, vars->height * SIZE, "so_long");
	define_textures(vars);
	draw_only(vars);
	mlx_loop_hook(vars->mlx, draw_anim, vars);
	mlx_hook(vars->mlx_win, 2, 1L << 0, move, vars);
	mlx_hook(vars->mlx_win, 17, 0, exit_from_game, NULL);
	mlx_loop(vars->mlx);
}

void	check_elements_count(t_var *vars)
{
	int	ccount;
	int	ecount;
	int	pcount;
	int	wcount;

	ccount = 0;
	ecount = 0;
	pcount = 0;
	wcount = 0;
	vars->length = -1;
	while (vars->all_line[++vars->length])
	{
		if (vars->all_line[vars->length] == 'C')
			ccount++;
		if (vars->all_line[vars->length] == 'E')
			ecount++;
		if (vars->all_line[vars->length] == 'P')
			pcount++;
		if (vars->all_line[vars->length] == 'W')
			wcount++;
	}
	vars->warrior_count = wcount;
	vars->posit.it = ccount;
	if (ccount < 1 || ecount < 1 || pcount != 1)
		exit_from_game(8, vars);
}

void	define_textures(t_var *vars)
{
	int	width;
	int	height;

	vars->tex.backg = mlx_xpm_file_to_image(vars->mlx,
			"./texture/backg.xpm", &width, &height);
	vars->tex.warrior = mlx_xpm_file_to_image(vars->mlx,
			"./texture/badup.xpm", &width, &height);
	vars->tex.collect = mlx_xpm_file_to_image(vars->mlx,
			"./texture/collect.xpm", &width, &height);
	vars->tex.collect2 = mlx_xpm_file_to_image(vars->mlx,
			"./texture/collect2.xpm", &width, &height);
	vars->tex.wallcor00 = mlx_xpm_file_to_image(vars->mlx,
			"./texture/corner00.xpm", &width, &height);
	vars->tex.wallcor01 = mlx_xpm_file_to_image(vars->mlx,
			"./texture/corner01.xpm", &width, &height);
	vars->tex.wallcor10 = mlx_xpm_file_to_image(vars->mlx,
			"./texture/corner10.xpm", &width, &height);
	vars->tex.wallcor11 = mlx_xpm_file_to_image(vars->mlx,
			"./texture/corner11.xpm", &width, &height);
	vars->tex.wallup = mlx_xpm_file_to_image(vars->mlx,
			"./texture/wallup.xpm", &width, &height);
	vars->tex.wallleft = mlx_xpm_file_to_image(vars->mlx,
			"./texture/wallleft.xpm", &width, &height);
	define_textures2(vars, width, height);
}

void	define_textures2(t_var *vars, int width, int height)
{
	vars->tex.hero = mlx_xpm_file_to_image(vars->mlx,
			"./texture/hero.xpm", &width, &height);
	vars->tex.herob = mlx_xpm_file_to_image(vars->mlx,
			"./texture/herob.xpm", &width, &height);
	vars->tex.heror = mlx_xpm_file_to_image(vars->mlx,
			"./texture/heror.xpm", &width, &height);
	vars->tex.herol = mlx_xpm_file_to_image(vars->mlx,
			"./texture/herol.xpm", &width, &height);
	vars->tex.heroup = mlx_xpm_file_to_image(vars->mlx,
			"./texture/hero.xpm", &width, &height);
	vars->tex.exit = mlx_xpm_file_to_image(vars->mlx,
			"./texture/door.xpm", &width, &height);
	vars->tex.exit2[5] = mlx_xpm_file_to_image(vars->mlx,
			"./texture/door5.xpm", &width, &height);
	vars->tex.exit2[4] = mlx_xpm_file_to_image(vars->mlx,
			"./texture/door4.xpm", &width, &height);
	vars->tex.exit2[3] = mlx_xpm_file_to_image(vars->mlx,
			"./texture/door3.xpm", &width, &height);
	vars->tex.exit2[2] = mlx_xpm_file_to_image(vars->mlx,
			"./texture/door2.xpm", &width, &height);
	vars->tex.exit2[1] = mlx_xpm_file_to_image(vars->mlx,
			"./texture/door1.xpm", &width, &height);
	vars->tex.exit2[0] = mlx_xpm_file_to_image(vars->mlx,
			"./texture/door0.xpm", &width, &height);
	define_textures3(vars, width, height);
}

void	define_textures3(t_var *vars, int width, int height)
{
	vars->tex.wallright = mlx_xpm_file_to_image(vars->mlx,
			"./texture/wallright.xpm", &width, &height);
	vars->tex.walldown = mlx_xpm_file_to_image(vars->mlx,
			"./texture/walldown.xpm", &width, &height);
	vars->tex.wallcenter = mlx_xpm_file_to_image(vars->mlx,
			"./texture/wallcen.xpm", &width, &height);
}
