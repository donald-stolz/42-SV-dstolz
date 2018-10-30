NAME = next_line

CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -fno-omit-frame-pointer -fsanitize=undefined -v

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

all: comp clean

comp:
	$(CC) $(CFLAGS) $(SRC) -I $(INC)
	make -C $(LIBS:%=$(LIB_DIR)%)
	$(CC) $(OBJ) $(LIBS:%=%.a) -o $(NAME)

debug:
	$(CC) $(CFLAGS) -g $(SRC) $(LIBS:%=%.a) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME).a
	rm -rf $(NAME)
	rm -rf $(NAME).dSYM
	rm -rf $(LIBS:%=%.a)

re: fclean all