CC = gcc

CFLAGS = -c -Wall -Wextra -Werror

NAME = test_printf

SRC = $(NAME).c

OBJ =  $(NAME).o

LIB = ../libprintf.a

all: comp $(NAME) clean

comp:
	$(CC) $(CFLAGS) $(SRC)
	$(CC) $(OBJ) $(LIB) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean
	make all
