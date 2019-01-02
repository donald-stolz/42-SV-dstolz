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

NAME = ft_ls

CC = gcc
CFLAGS = -Wall -Wextra -Werror

FILES =	ft_ls.c				\
		ft_getinfo.c		\
		ft_sortdir.c		\
		ft_displaydir.c		\
		ft_freestructs.c	\
		ft_recursivedir.c	\

HEADERS	= 	ft_ls.h	\
			libft.h	\

LIBS =	libft	\

SRC_DIR = src/
INC_DIR = inc/
LIB_DIR = assets/

SRC = $(FILES:%=$(SRC_DIR)%) 
OBJ = $(FILES:%.c=%.o)
INC = $(HEADERS:%=$(INC_DIR)%)

all: $(NAME)

$(NAME): $(LIB)
	@make -C $(LIBS:%=$(LIB_DIR)%)
	@echo "Compiled libft"
	@$(CC) $(CFLAGS) -c $(SRC)
	@$(CC) $(OBJ) $(LIBS:%=%.a) -o $(NAME)
	@echo "Compiled ft_ls"

debug:
	@make -C $(LIBS:%=$(LIB_DIR)%)
	@$(CC) -g $(SRC) $(LIBS:%=%.a) -o a.out
	@echo "Compiled ft_ls debug"

$(LIB):
	@make -C $(LIBS:%=$(LIB_DIR)%)
	@echo "Compiled assets"

comp:
	$(CC) $(CFLAGS) -c  $(SRC) -I $(INC)
	make -C $(LIBS:%=$(LIB_DIR)%)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME).a
	rm -rf $(NAME)
	rm -rf $(NAME).dSYM
	rm -rf $(LIBS:%=%.a)

re: fclean all
