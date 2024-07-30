SRCDIR = ./srcs/
SRC = ft_char.c ft_grid.c ft_largest.c ft_misc.c ft_print_map.c ft_readmap.c ft_split.c ft_valid.c main.c
SRCS = ${addprefix ${SRCDIR}, ${SRC}}
OBJS = ${SRCS:.c=.o}
HDIR = ./includes/
NAME = bsq
CC = cc
CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -I ${HDIR} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS}

all: ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
