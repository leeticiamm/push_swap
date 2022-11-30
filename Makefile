NAME = push_swap


SRCS = 


OBJS = ${SRCS:.c=.o}


CC		= cc


RM		= rm -f


CFLAGS = -Wall -Wextra -Werror


.c.o:
		${CC} ${CFLAGS} -g -c $< -o ${<:.c=.o} -I ./mlx


$(NAME): ${OBJS}
		make -C ./libft
		make -C ./mlx
		$(CC) -g $(OBJS) ./libft/libft.a -L ./mlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)


all:	${NAME}


clean:
		${RM} ${OBJS}
		make clean -C ./mlx
		make clean -C ./libft


fclean:	clean
		${RM} ${NAME}
		make fclean -C ./libft


re:		fclean all
		make re -C ./libft



.PHONY: all clean fclean re