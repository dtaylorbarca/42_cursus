NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC = ft_character.c \
	ft_decimal.c \
	ft_hex.c \
	ft_pointer.c \
	ft_printf.c \
	ft_string.c \
	ft_unsigned_decimal.c 

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
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
