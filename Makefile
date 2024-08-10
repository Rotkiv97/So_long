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

NAME        := so_long
CC          := gcc
FLAGS       := -Wall -Wextra -Werror 

CLR_RMV     := \033[0m
RED         := \033[1;31m
GREEN       := \033[1;32m
YELLOW      := \033[1;33m
BLUE        := \033[1;34m
CYAN        := \033[1;36m
RM          := rm -f

UNAME       := $(shell uname)

SRCS        := get_next_line.c \
               ft_pattuglia_nemica.c \
               ft_controllo_sprite.c \
               ft_inizio_posizione.c \
               ft_init.c \
               ft_mappa.c \
               ft_muri.c \
               get_next_line_utils.c \
               ft_conteggio_raccolta.c \
               ft_main_get.c \
               ft_stampa_passaggi.c \
               ft_free.c \
               ft_nemico.c \
               ft_esposizione.c \
               ft_mlx_close.c \
               ft_controlli_rett_caratte_mappa.c \
               ft_utils2.c \
               ft_movimento.c \
               ft_check_args.c \
               so_long.c \
               ft_error.c \
               ft_movimento_nemico.c \
               ft_key_press.c \
               ft_movimento_pleyer.c \
               ft_utils.c \
                          
OBJS        := $(SRCS:.c=.o)

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}


ifeq ($(UNAME), Darwin)
$(NAME): ${OBJS}
		@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
		@ $(MAKE) -C mlx all >/dev/null 2>&1
		@ cp ./mlx/libmlx.a .
		$(CC) $(FLAGS) -g3 -Ofast -o $(NAME) -Imlx $(OBJS) -Lmlx -lmlx -lm -framework OpenGL -framework AppKit
		@echo "$(GREEN)$(NAME) created${CLR_RMV} ✔️"
endif

ifeq ($(UNAME), Linux)
$(NAME): ${OBJS}
		@echo "$(GREEN)Linux compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
		@chmod 777 mlx_linux/configure
		@ $(MAKE) -C mlx_linux all
		$(CC) $(FLAGS) -g3 -o $(NAME) $(OBJS) -Imlx_linux -Lmlx_linux -lmlx -L/usr/lib -lXext -lX11 -lm
		@echo "$(GREEN)$(NAME) created${CLR_RMV} ✔️"
endif

all:		${NAME}

ifeq ($(UNAME), Darwin)
clean:
		@ ${RM} *.o */*.o */*/*.o
		@ rm -rf $(NAME).dSYM >/dev/null 2>&1
		@ echo "$(RED)Deleting $(CYAN)$(NAME) ${CLR_RMV}objs ✔️"
endif

ifeq ($(UNAME), Linux)
clean:
		@ ${RM} *.o */*.o */*/*.o
		@ rm -rf $(NAME).dSYM >/dev/null 2>&1
		@ echo "$(RED)Deleting $(CYAN)$(NAME) ${CLR_RMV}objs ✔️"
endif

ifeq ($(UNAME), Linux)
fclean:		clean
		@ ${RM} ${NAME}
		@ $(MAKE) -C mlx_linux clean 
		@ echo "$(RED)Deleting $(CYAN)$(NAME) ${CLR_RMV}binary ✔️"
endif

ifeq ($(UNAME), Darwin)
fclean:		clean
		@ ${RM} ${NAME}
		@ rm libmlx.a
		@ echo "$(RED)Deleting $(CYAN)$(NAME) ${CLR_RMV}binary ✔️"
endif

re:			fclean all

.PHONY:		all clean fclean re

