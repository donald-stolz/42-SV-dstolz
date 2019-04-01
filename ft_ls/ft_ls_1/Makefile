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
		ft_args.c			\
		ft_free.c			\
		ft_get.c			\
		ft_print.c			\
		ft_sort.c			\
		ft_dir_info.c		\
		ft_dir_utility.c	\
		ft_print_utility.c	\
		ft_sort_utility.c	\

LIBS =	assets/libft/libft.a		\
		assets/b_printf/b_printf.a	\

SRC_DIR = src/
INC_DIR = inc/

SRC = $(FILES:%=$(SRC_DIR)%) 
OBJ = $(FILES:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C assets/libft
	@make -C assets/b_printf
	@echo "Compiled libraries"
	@$(CC) $^ $(LIBS) -o $@
	@echo "Compiled ft_ls"

$(OBJ): $(SRC)
	@$(CC) $(CFLAGS) -c $^
	@echo "Compiled object files"

debug: libs
	@$(CC) -g -O0 -std=c11 -ggdb3 $(SRC) $(LIBS)
	@echo "Compiled ft_ls debug"
	@make clean

leaks: libs
	@$(CC) -g -fsanitize=address -fno-omit-frame-pointer $(SRC) $(LIBS)
	@echo "Compiled ft_ls debug leaks"
	@make clean

clean:
	@rm -rf $(OBJ)
	@make clean -C assets/libft
	@make clean -C assets/b_printf
	@echo "Cleaned object files"

fclean: clean
	@make fclean -C assets/libft
	@make fclean -C assets/b_printf
	@rm -rf *.a
	@rm -rf $(NAME)
	@rm -rf $(NAME).dSYM
	@rm -rf $(LIBS:%=%.a)
	@rm -rf a.out*
	@echo "Cleaned all files"

re: fclean all
