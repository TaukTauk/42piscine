# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: talin <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/25 11:02:33 by talin             #+#    #+#              #
#    Updated: 2024/07/25 12:49:05 by talin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = $(wildcard srcs/*.c)
OBJS = ${SRCS:.c=.o}
HDIR = includes/
DELETE = $(wildcard *.o srcs/*.o)
NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

libft.a: $(OBJS)
	$(CC) $(CFLAGS) -c $(SRCS)
	ar rcs $(NAME) *.o
	mv *.o srcs/

all: libft.a

clean:
	rm -f $(DELETE)

fclean: clean
	rm -f $(NAME)

re: fclean all
