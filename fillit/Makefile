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

CFLAGS = -c -Wall -Wextra -Werror

SOURCES	=	main.c	\

HEADERS = fillit.h	\

LIBS =	libft	\

SRC_DIR = src/
INC_DIR = inc/

SRC = $(SOURCES:%=src/%) 
OBJ = $(SOURCES:%.c=%.o)
INC = $(HEADERS:%=inc/%)

all: comp $(NAME) clean

comp:
	$(CC) $(CFLAGS) $(SRC) -I $(INC)

# $(NAME)

debug:
	@cd inc/libft && make && mv libft.a ../../ && cd ../../
	@echo "Compiled libft"
	@$(CC) $(CFLAGS) -g $(SRC) $(LIBS:%=%.a) -o a.out
	@echo "Compiled fillit debug"

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
	rm -rf a.*
	rm -rf $(LIBS:%=%.a)

re: fclean all
