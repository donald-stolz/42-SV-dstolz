# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dstolz <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/11 08:08:33 by dstolz            #+#    #+#              #
#    Updated: 2018/09/20 10:44:23 by dstolz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -c -Wall -Wextra -Werror

NAME = libft

SRC =	ft_isdigit.c	\
		ft_memset.c		\
		ft_strchr.c		\
		ft_strcmp.c		\
		ft_strcpy.c		\
		ft_strdup.c		\
		ft_strlen.c		\
		ft_strncpy.c	\
		ft_tolower.c	\
		ft_toupper.c	\
		ft_bzero.c		\
		ft_memcpy.c		\
		ft_memccpy.c	\
		ft_memmove.c	\
		ft_memchr.c		\
		ft_memcmp.c		\
		ft_strcat.c		\
		ft_strncat.c	\
		ft_strlcat.c	\

OBJ =  $(SRC:%.c=%.o)

INC = libft.h

all: comp $(NAME) clean

comp:
	$(CC) $(CFLAGS) $(SRC) -I $(INC)

$(NAME): comp
	ar rcs $(NAME).a $(OBJ)
	ranlib $(NAME).a

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME).a

re: fclean
	make all
