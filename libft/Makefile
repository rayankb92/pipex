SRCS	= ft_bzero.c ft_isalpha.c ft_isdigit.c ft_memchr.c ft_memcpy.c ft_memset.c \
			ft_atoi.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_memcmp.c ft_memmove.c ft_strlen.c \
			ft_strdup.c ft_strncmp.c ft_toupper.c ft_tolower.c ft_calloc.c ft_strnstr.c \
			ft_strchr.c ft_strrchr.c ft_strlcpy.c ft_strlcat.c ft_substr.c ft_strjoin.c \
			ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
			ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strcmp.c ft_strlendouble.c ft_displaystrstr.c \
			$(addprefix ft_printf/, ft_hexaptr.c ft_printf.c ft_putcharstr.c ft_putnbr.c) \
			$(addprefix get_next_line/, get_next_line.c get_next_line_utils.c)

BONUS	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
			ft_lstclear.c ft_lstiter.c ft_lstmap.c

NAME	= libft.a

OBJS	= ${SRCS:.c=.o}

OBJS_BONUS = ${BONUS:.c=.o}

HEADERS	= ./

CFLAGS = -Wall -Wextra -Werror

.c.o	:
		gcc -Wall -Wextra -Werror -I ${HEADERS} -c $< -o ${<:.c=.o}

${NAME} : ${OBJS}
		ar rcs ${NAME} ${OBJS}

all : ${NAME}

so:
	gcc -nostartfiles -shared -o libft.so ${CFLAGS} ${SRCS} ${BONUS}

bonus : $(OBJS) $(OBJS_BONUS)
		ar rcs $(NAME) $(OBJS) $(OBJS_BONUS)

clean :
		rm -rf ${OBJS} ${OBJS_BONUS}

fclean : clean
		rm -rf ${NAME}

re : fclean all