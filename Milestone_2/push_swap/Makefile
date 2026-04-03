NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c push_swap.c utils.c utils_2.c utils_3.c \
	string_utils.c args_utils.c input_handler.c \
	operations.c operations_2.c operations_3.c \
	sort_utils.c chunks.c chunks_utils.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
