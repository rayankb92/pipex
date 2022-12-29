# *****************************************************************
CC = cc
CFLAGS = -Wall -Werror -Wextra

# *****************************************************************
RM = rm -f
AR = ar rcs
# *****************************************************************
HEADER = ./
# *****************************************************************
NAME = libftprintf.a

SRCS = 	ft_printf.c ft_putcharstr.c ft_putnbr.c ft_hexaptr.c

OBJS = $(SRCS:.c=.o) 

# *****************************************************************
all: $(NAME)

$(NAME):	$(OBJS)
	$(AR) $(NAME) $(OBJS)

.c.o:
	gcc -Wall -Wextra -Werror -I ${HEADER} -c $< -o ${<:.c=.o}

clean:
	$(RM) $(OBJS)
 
fclean:	clean
		$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re .c.o