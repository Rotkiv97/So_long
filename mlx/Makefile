# Nome della libreria finale
NOM = libmlx.a

# Elenco dei file sorgente
SRC = mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
SRC += mlx_png.c mlx_mouse.m

# Conversione dei file sorgente in oggetti
OBJ1 = $(SRC:.c=.o)
OBJ = $(OBJ1:.m=.o)

# Opzioni di compilazione
CFLAGS = -O2 -DSTRINGPUTX11

# Target principale
all: $(NOM)

# Regola per creare la libreria statica
$(NOM): $(OBJ)
	ar -r $(NOM) $(OBJ)
	ranlib $(NOM)

# Regola per la compilazione dei file .m e .c
%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

%.o: %.m
	gcc $(CFLAGS) -c $< -o $@

# Pulizia dei file compilati
clean:
	rm -f $(NOM) $(OBJ) *~
	rm -f mlx_app

# Pulizia e ricompilazione
re: clean all
