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

SRC_DIR = src/
INC_DIR = inc/

SRC = $(SOURCES:%=src/%) 
OBJ = $(SOURCES:%.c=%.o)
INC = $(HEADERS:%=inc/%)

all: $(NAME) clean

lib:
	@make -C inc/$(LIBS)
	@mv inc/libft/libft.a ./
	@echo "Compiled libft"

comp: lib
	@$(CC) $(CFLAGS) -c $(SRC) -I $(INC)

$(NAME): comp
	@$(CC) $(OBJ) libft.a -o $(NAME)
	@echo "Compiled fillit"

debug: lib
	@$(CC) $(CFLAGS) -g $(SRC) libft.a -o $(NAME)
	@echo "Compiled fillit debug"

clean:
	@rm -rf $(OBJ)
	@echo "Removed all object files"

fclean: clean
	@rm -rf $(NAME)
	@rm -rf a.*
	@rm -rf $(LIBS:%=%.a)
	@echo "Removed all temp files"

re: fclean all
