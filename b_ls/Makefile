# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dstolz <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/11 08:08:33 by dstolz            #+#    #+#              #
#    Updated: 2018/09/20 11:26:30 by dstolz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = b_ls

CC = gcc
CFLAGS = -Wall -Wextra
#  -Werror

FILES =	b_ls.c			\
		ft_getinfo.c	\
		ft_sortdir.c	\

HEADERS	= 	b_ls.h	\
			libft.h	\

LIBS =	libft	\
		# b_printf/	

SRC_DIR = src/
INC_DIR = inc/
LIB_DIR = assets/

SRC = $(FILES:%=$(SRC_DIR)%) 
OBJ = $(FILES:%.c=%.o)
INC = $(HEADERS:%=$(INC_DIR)%)

all: comp clean

comp:
	$(CC) $(CFLAGS) -c  $(SRC) -I $(INC)
	make -C $(LIBS:%=$(LIB_DIR)%)
	$(CC) $(OBJ) $(LIBS:%=%.a)

debug:
	make -C $(LIBS:%=$(LIB_DIR)%)
	$(CC) $(CFLAGS) -g $(SRC) $(LIBS:%=%.a) -o a.out

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME).a
	rm -rf a.out
	rm -rf a.out.dSYM
	rm -rf $(LIBS:%=%.a)

re: fclean all
