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

NAME = fillit

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SOURCES	=	main.c	\
			read.c	\
			solve.c	

HEADERS = fillit.h	\

LIBS =	libft	\

SRC_DIR = source/

SRC = $(SOURCES:%=source/%) 
OBJ = $(SOURCES:%.c=%.o)

all: $(NAME)

lib:
	@make -C $(LIBS)
	@echo "Compiled libft"

comp: lib
	@$(CC) $(CFLAGS) -c $(SRC)

$(NAME): comp
	@$(CC) $(OBJ) libft/libft.a -o $(NAME)
	@echo "Compiled fillit"

debug: lib
	@$(CC) $(CFLAGS) -g $(SRC) libft/libft.a -o a.out
	@echo "Compiled fillit debug"

clean:
	@rm -rf $(OBJ)
	@make fclean -C $(LIBS)
	@echo "Removed all object files"

fclean: clean
	@rm -rf a.*
	@rm -rf $(LIBS:%=%.a)
	@echo "Removed all temp files"
	@rm -rf $(NAME)
	@echo "Removed executable"

re: fclean all
