# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dstolz <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/12 08:08:44 by dstolz            #+#    #+#              #
#    Updated: 2018/09/24 13:36:12 by dstolz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -c -Wall -Wextra -Werror

NAME = libftprintf

SRC_DIR = sources/
INC_DIR = includes/
TEST_DIR = tests/

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

INC = $(INC_DIR)$(NAME).h

TEST = b_printftest

LIB = $(NAME).a

all: comp $(NAME) clean

comp:
	$(CC) $(CFLAGS) $(SRC) -I $(INC)

$(NAME): comp
	ar rcs $(LIB) $(OBJ)
	ranlib $(LIB)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(LIB)

re: fclean
	make all

test: comp
	$(CC) $(CFLAGS) $(TEST_DIR)$(TEST).c -I $(INC)
	$(CC) $(OBJ) $(TEST).o  -o $(TEST)
