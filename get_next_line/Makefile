NAME = next_line

CC = gcc
CFLAGS = -Wall -Wextra -Werror

FILES =	get_next_line.c \
		main.c

HEADERS	= 	get_next_line.h

LIBS =	libft	\

SRC_DIR = src/
INC_DIR = inc/
LIB_DIR = assets/

SRC = $(FILES:%=%) 
OBJ = $(FILES:%.c=%.o)
INC = $(HEADERS:%=%)


debug:
	cd libft && make && mv libft.a ../ && cd ../
	$(CC) $(CFLAGS) -g $(SRC) $(LIBS:%=%.a) -o a.out

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf a.*
	rm -rf $(LIBS:%=%.a)

re: fclean all
