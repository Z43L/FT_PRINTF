
NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Werror -Wextra
INCLUDES = -I libft -I src

SRC = src/ft_putnbrd_base.c src/ft_printf.c 
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
