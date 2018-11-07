# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dstolz <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/04 11:15:21 by dstolz            #+#    #+#              #
#    Updated: 2018/11/04 11:15:27 by dstolz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -c -Wall -Wextra -Werror

NAME = fillit

SOURCES	=	main.c	\

SRC =	$(SOURCES:%=src/%)		\

OBJ =	$(CHECK:%.c=%.o)	\
		$(LST:%.c=%.o)		\
		$(MEM:%.c=%.o)		\
		$(NUM:%.c=%.o)		\
		$(PRINT:%.c=%.o)	\
		$(STR:%.c=%.o)		\

INC = libft.h

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRC) -I $(INC)
	ar rcs $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
	rm -rf a.out.dSYM/
	rm -f a.out

re: fclean all
