# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vguidoni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/13 12:18:20 by vguidoni          #+#    #+#              #
#    Updated: 2022/12/13 12:19:31 by vguidoni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := so_long
CC := gcc
FLAGS := -Wall -Wextra -Werror

RM := rm -f

SRCS := get_next_line.c ft_pattuglia_nemica.c ft_controllo_sprite.c \
        ft_inizio_posizione.c ft_init.c ft_mappa.c ft_muri.c \
        get_next_line_utils.c ft_conteggio_raccolta.c ft_main_get.c \
        ft_stampa_passaggi.c ft_free.c ft_nemico.c ft_esposizione.c \
        ft_mlx_close.c ft_controlli_rett_caratte_mappa.c ft_utils2.c \
        ft_movimento.c ft_check_args.c so_long.c ft_error.c \
        ft_movimento_nemico.c ft_key_press.c ft_movimento_pleyer.c ft_utils.c

OBJS := $(SRCS:.c=.o)

.c.o:
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@chmod 777 mlx_linux/configure
	$(MAKE) -C mlx_linux all
	$(CC) $(FLAGS) -g3 -o $(NAME) $(OBJS) -Imlx_linux -Lmlx_linux -lmlx -L/usr/lib -lXext -lX11 -lm

all: $(NAME)

clean:
	@$(RM) $(OBJS)
	@rm -rf $(NAME).dSYM >/dev/null 2>&1

fclean: clean
	@$(RM) $(NAME)
	$(MAKE) -C mlx_linux clean

re: fclean all

.PHONY: all clean fclean re