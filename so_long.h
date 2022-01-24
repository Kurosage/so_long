#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <mlx.h>
# include "libft.h"
# include "get_next_line.h"

typedef struct s_tex
{
	char	*backg;
	char	*wall;
	char	*exit;
	char	*collect;
	char	*hero;
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
}	t_posit;

typedef struct s_key
{
	int	up;
	int	down;
	int	left;
	int	right;
}	t_key;

typedef struct s_var
{
	char	*all_line;
	char	**mas_map;
	int		height;
	int		length;
	int		height_win;
	int		length_win;
	void	*mlx;
	void	*mlx_win;
	t_tex	tex;
	t_data	data;
	t_posit	posit;
	t_key	key;
}	t_var;
int	move(int keycode, t_var *vars);
void	map_drawing(t_var *vars);
void	define_textures(t_var *vars);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		reading_and_chking_map(char *file, t_var *vars);
int		exit_from_game();
void	check_format(char *file, t_var *vars);
void	check_upanddown(t_var *vars);
void	check_middle(t_var *vars);
void	for_free(t_var *vars);
void	check_elements_count(t_var *vars);
int	draw_only(t_var *vars);
#endif