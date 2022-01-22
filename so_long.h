#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <mlx.h>
# include "libft.h"
# include "get_next_line.h"

typedef struct s_var
{
	char	*all_line;
	char	**mas_map;
	int		height;
	int		length;

}	t_var;

void		reading_and_chking_map(char *file, t_var *vars);
void	exit_from_game();
void	check_format(char *file, t_var *vars);
void	check_upanddown(t_var *vars);
void	check_middle(t_var *vars);
#endif