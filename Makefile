NAME	= so_long
SRC		= so_long.c get_next_line.c get_next_line_utils.c
OBJS = ${SRC:.c=.o}
MLX		= 	-lmlx -framework OpenGL -framework AppKit
HEAD	=	-I includes -I libft -I mlx
LD		=	-L libft -lft
FLAGS 	= #-Wall -Werror -Wextra -g
.c.o 	:
		${CC} ${FLAGS} ${HEAD} -c $< -o ${<:.c=.o}
$(NAME)	:	${OBJS}
		make bonus -C libft
		${CC} ${FLAGS} ${LD} ${OBJS} -o ${NAME} ${MLX}
all				:	${NAME}

clean			:
					make clean -C libft
					@rm -rf ${OBJS}

fclean			:	clean
					@rm -rf ${NAME}

re				:	fclean all

.PHONY			:	all clean fclean re