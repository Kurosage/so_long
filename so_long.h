/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaren <rmaren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 20:39:33 by rmaren            #+#    #+#             */
/*   Updated: 2022/01/27 20:39:35 by rmaren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <mlx.h>
# include "libft.h"
# include "get_next_line.h"
# define SIZE 64

typedef struct s_tex
{
	char	*backg;
	char	*wallcor00;
	char	*wallcor01;
	char	*wallcor10;
	char	*wallcor11;
	char	*wallup;
	char	*warrior;
	char	*wallleft;
	char	*walldown;
	char	*wallright;
	char	*wallcenter;
	char	*exit;
	char	*exit2[7];
	char	*collect;
	char	*collect2;
	char	*hero;
	char	*herob;
	char	*herol;
	char	*heror;
	char	*heroup;
}	t_tex;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

}	t_data;

typedef struct s_posit
{
	int	x;
	int	y;
	int	item;
	int	it;
}	t_posit;

typedef struct s_key
{
	int	up;
	int	down;
	int	left;
	int	right;
}	t_key;

typedef struct s_flags
{
	int	up;
	int	down;
	int	left;
	int	right;
}	t_flags;

typedef struct s_var
{
	char	*last;
	char	fd;
	char	*all_line;
	char	**mas_map;
	int		warrior_count;
	int		height;
	int		length;
	int		height_win;
	int		length_win;
	int		steps;
	void	*mlx;
	void	*mlx_win;
	t_flags	flag;
	t_tex	tex;
	t_data	data;
	t_posit	posit;
	t_key	key;
}	t_var;
void	readin(char *file, t_var *vars);
void	warrior_move(t_var *vars, int i, int j);
void	mas_door(t_var *vars, int i, int j);
void	timer(t_var *vars);
void	timer2(t_var *vars);
int		draw_anim(t_var *vars);
int		move(int keycode, t_var *vars);
void	map_drawing(t_var *vars);
void	define_textures(t_var *vars);
void	define_textures2(t_var *vars, int width, int heigth);
void	define_textures3(t_var *vars, int width, int heigth);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	reading_and_chking_map(char *file, t_var *vars);
int		exit_from_game(int i, t_var *vars);
int		exit_lose_win(int i, t_var *vars);
void	check_format(t_var *vars);
void	check_upanddown(t_var *vars);
void	check_middle(t_var *vars);
void	for_free(t_var *vars);
void	check_elements_count(t_var *vars);
int		draw_only(t_var *vars);
void	draw_wall(t_var *vars, int i, int j);
void	draw_wall2(t_var *vars, int i, int j);
void	draw_another_characters(t_var *vars, int i, int j);
void	up(t_var *vars);
void	down(t_var *vars);
void	left(t_var *vars);
void	right(t_var *vars);
void	draw_anim2(t_var *vars, int i, int j);
void	draw_anim3(t_var *vars, int i, int j);
#endif