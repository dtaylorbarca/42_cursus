NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC = ft_character.c \
	ft_decimal.c \
	ft_lower_hex.c \
	ft_pointer.c \
	ft_printf.c \
	ft_string.c \
	ft_unsigned_decimal.c \
	ft_upper_hex.c

OBJ = $(SRC:.c=.o)

HEADERS = ft_printf.h $(LIBFT_DIR)/libft.h

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT_DIR)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJ)

%.o: %.c $(HEADERS) Makefile
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
