# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dstolz <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/12 08:08:44 by dstolz            #+#    #+#              #
#    Updated: 2018/10/05 08:13:47 by dstolz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -c -Wall -Wextra -Werror

NAME = b_printf

SRC_DIR  = sources/
INC_DIR  = includes/

FILES = b_printf.c		\
		b_putchar.c	\
		b_puts.c		\
		b_putptr.c		\
		b_strrev.c		\
		b_numlen.c		\
		b_strlen.c		\
		b_itoa.c		\
		

SRC = $(FILES:%=$(SRC_DIR)%)

OBJ = $(FILES:%.c=%.o)

INC = $(INC_DIR)$(NAME).h

LIB = $(NAME).a

all: comp $(NAME) clean

comp:
	@$(CC) $(CFLAGS) $(SRC) -I $(INC)

$(NAME): comp
	@ar rcs $(LIB) $(OBJ)
	@ranlib $(LIB)

clean:
	@rm -rf $(OBJ)
	@rm -rf $(TEST).o
	@mv $(NAME).a ../../

fclean: clean
	rm -rf $(LIB)
	rm -rf $(TEST)

re: fclean
	make all

