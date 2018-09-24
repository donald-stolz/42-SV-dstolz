# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dstolz <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/12 08:08:44 by dstolz            #+#    #+#              #
#    Updated: 2018/09/24 11:24:38 by dstolz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -c -Wall -Wextra -Werror

NAME = libprintf

SRC_DIR = sources/

FILES = b_printf.c		\
		ft_putchar.c	\
		ft_puts.c		\
		ft_putptr.c		\
		ft_putnbr.c		\
		ft_printitoa.c	\
		ft_printuitoa.c	\
		ft_printltoa.c	\
		ft_numdigits.c	\

SRC = $(FILES:%=$(SRC_DIR)%)

OBJ = $(FILES:%.c=%.o)

TEST = test_printf

INC = $(NAME).h

LIB = $(NAME).a

all: comp $(NAME) clean

comp:
	$(CC) $(CFLAGS) $(SRC) -I $(INC)

$(NAME):
	ar rcs $(LIB) $(OBJ)
	ranlib $(LIB)

test: comp
	$(CC) $(CFLAGS) $(SRC_DIR)$(TEST).c -I $(INC)
	$(CC) $(OBJ) $(TEST).o  -o runtest

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(LIB)

re: fclean
	make all
