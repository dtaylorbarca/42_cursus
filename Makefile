# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dtaylor- <dtaylor-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/12 16:14:09 by dtaylor-          #+#    #+#              #
#    Updated: 2026/03/12 16:14:13 by dtaylor-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc 

CFLAGS = -Wall -Wextra -Werror -g

INCLUDE = push_swap.h

SRC = arg_control.c  ft_adaptive.c  ft_medium.c     ft_printf.c  ft_split.c   p_mov.c      r_mov.c    s_mov.c     utils1.c  utils3.c \
	  benchmark.c    ft_complex.c   ft_printchrs.c  ft_simple.c  ft_switch.c  push_swap.c  rr_move.c  tinysort.c  utils2.c  utils4.c utils5.c

OBJ = $(SRC:.c=.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c $(INCLUDE) Makefile
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re
