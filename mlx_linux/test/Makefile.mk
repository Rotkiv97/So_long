# Directory delle intestazioni e librerie
INC=%%%%
INCLIB=$(INC)/../lib

# Compilatore e flags
CC=gcc
CFLAGS=-I$(INC) -O3 -I..

# Nome dell'eseguibile e dei file sorgenti
NAME=mlx-test
SRC=main.c
OBJ=$(SRC:.c=.o)

# Regola principale
all: $(NAME)

# Regola per creare l'eseguibile
$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) -L.. -lmlx -L$(INCLIB) -lXext -lX11 -lm -lbsd

# Regola per compilare i file .c in file .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regole di pulizia
clean:
	rm -f $(NAME) $(OBJ) *~ core *.core

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
