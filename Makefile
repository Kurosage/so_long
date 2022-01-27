NAME	= so_long
SRC		= so_long.c get_next_line.c get_next_line_utils.c chek_map_valid1.c charac_check_define.c draw_only_first.c \
			moving.c
HEADER	= so_long.h
SRC_BONUS = draw_anim_bonus.c
OBJS = ${SRC:.c=.o}
OBJS_BONUS = ${SRC_BONUS:.c=.o}
MLX		= 	-lmlx -framework OpenGL -framework AppKit
HEAD	=	-I includes -I libft -I mlx
LD		=	-L libft -lft
FLAGS 	= -Wall -Werror -Wextra -g
.c.o 	:
		${CC} ${FLAGS} ${HEAD} -c $< -o ${<:.c=.o}
$(NAME)	:	${OBJS}  ${OBJS_BONUS} ${HEADER}
		make bonus -C libft
		${CC} ${FLAGS} ${LD} ${OBJS} ${OBJS_BONUS} -o ${NAME} ${MLX}
all				:	${NAME}

clean			:
					make clean -C libft
					@rm -rf ${OBJS} ${OBJS_BONUS}

fclean			:	clean
					@rm -rf ${NAME}

re				:	fclean all

bonus			:   ${OBJS}  ${OBJS_BONUS} ${HEADER}
					make bonus -C libft
					${CC} ${FLAGS} ${LD} ${OBJS} ${OBJS_BONUS} -o ${NAME} ${MLX}
.PHONY			:	all clean fclean bonus re