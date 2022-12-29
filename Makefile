SRCS = $(addprefix src/, main2.c exec.c fork.c parse.c utils.c)

SRCS_BONUS = $(addprefix src_bonus/, main2.c exec.c fork.c parse.c utils.c)

NAME = pipex

NAME_BONUS = pipex_bonus


INC = -I ./

FLAGS = -g3 -Wall -Werror -Wextra

OBJS = ${SRCS:.c=.o}

OBJS_BONUS = ${SRCS_BONUS:.c=.o}

LIBFT = libft.a

${NAME} : ${OBJS} ${LIBFT}
			make -C libft/ all
			mv libft/libft.a ./
			gcc ${FLAGS} ${INC} $(OBJS) -o $(NAME) libft.a

${LIBFT}:
	make -C libft/ all
	mv libft/libft.a ./

all : ${NAME}

%.o:%.c
		gcc ${FLAGS} -c $< -o $@

bonus: ${NAME_BONUS}

${NAME_BONUS}: ${OBJS_BONUS} ${LIBFT}
		gcc ${FLAGS} ${INC} ${OBJS_BONUS} -o ${NAME_BONUS} ${LIBFT}
clean :
		make -C ./libft/ clean
		rm -rf ${OBJS} ${OBJS_BONUS}

fclean : clean
		rm -rf ${NAME} ${NAME_BONUS} ${LIBFT}
		make -C ./libft/ fclean

re : fclean all

.PHONY : all bonus clean fclean re bonus INC libft NAME NAME_BONUS