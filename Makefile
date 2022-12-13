NAME = push_swap


SRCS = push_swap.c check_errors.c operations.c operations2.c push_a.c push_b.c sort.c


OBJS = ${SRCS:.c=.o}


CC		= cc


RM		= rm -f


CFLAGS = -Wall -Wextra -Werror


.c.o:
		${CC} ${CFLAGS} -g -c $< -o ${<:.c=.o}


$(NAME): ${OBJS}
		make -C ./libft
		$(CC) -g $(OBJS) ./libft/libft.a -o $(NAME)


all:	${NAME}


clean:
		${RM} ${OBJS}
		make clean -C ./libft


fclean:	clean
		${RM} ${NAME}
		make fclean -C ./libft


re:		fclean all
		make re -C ./libft



.PHONY: all clean fclean re