NAME = push_swap

SRCS = 	 main.c push_utils.c split.c errors.c free.c parsing.c sort.c \

OBJS = ${SRCS:.c=.o}

CC		= gcc -g -fsanitize=address
RM		= rm -f

CFLAGS = -Wall -Wextra -Werror
#CFLAGS = -g

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

$(NAMES): $(OBJS)
	$(CC) $(OBJS) -I /usr/local/include -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit -o $(NAMES)

all:	${NAME}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all
