# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dstolz <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/11 08:08:33 by dstolz            #+#    #+#              #
#    Updated: 2019/01/20 15:46:22 by dstolz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

CC = gcc
CFLAGS = -Wall -Wextra -Werror

FILES =	ft_ls.c				\
		ft_getinfo.c		\
		ft_sortdir.c		\
		ft_displaydir.c		\
		ft_freestructs.c	\
		ft_recursivedir.c	\
		ft_flags.c			\
		ft_helpers.c		\

HEADERS	= 	ft_ls.h		\
			libft.h		\
			b_printf.h	\

LIBS =	libft		\
		b_printf	\

SRC_DIR = src/
INC_DIR = inc/
LIB_DIR = assets/

SRC = $(FILES:%=$(SRC_DIR)%) 
OBJ = $(FILES:%.c=%.o)
INC = $(HEADERS:%=$(INC_DIR)%)

all: $(NAME)

$(NAME): libs
	@$(CC) $(CFLAGS) -c $(SRC)
	@$(CC) $(OBJ) $(LIBS:%=%.a) -o $(NAME)
	@echo "Compiled ft_ls"

debug: libs
	@$(CC) -g $(SRC) $(LIBS:%=%.a) -o a.out 
	@echo "Compiled ft_ls debug"
	@make clean

leaks: libs
	@$(CC) -g -fsanitize=address -fno-omit-frame-pointer $(SRC) $(LIBS:%=%.a) -o test.out 
	@echo "Compiled ft_ls debug leaks"
	@make clean
libs:
	@make -C assets/libft
	@make -C assets/b_printf
	@echo "Compiled assets"

comp:
	@$(CC) $(CFLAGS) -c  $(SRC) -I $(INC)
	@make -C $(LIBS:%=$(LIB_DIR)%)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME).a
	rm -rf $(NAME)
	rm -rf $(NAME).dSYM
	rm -rf $(LIBS:%=%.a)
	rm -rf a.out*

re: fclean all
