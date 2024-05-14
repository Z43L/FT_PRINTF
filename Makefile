NAME = libftprintf.a

CC = gcc
CFLAGS = -g3 -Wall -Werror -Wextra
INCLUDES = -I libft -I src

SRC = src/*.c
OBJ = $(SRC:.c=.o)
LIBFT = libft/libft.a
LIBFT_H = libft/libft.h
FT_PRINTF_H = src/ft_printf.h

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	ar rcs $@ $^

$(OBJ): $(SRC) $(LIBFT_H) $(FT_PRINTF_H)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	make -C libft

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re