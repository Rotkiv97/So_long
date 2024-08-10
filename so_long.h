/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguidoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:20:16 by vguidoni          #+#    #+#             */
/*   Updated: 2022/12/06 18:20:18 by vguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "mlx.h"
# include "get_next_line.h"

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_EXIT		17

# if defined(__APPLE__) && defined(__MACH__)
#  define LEFT_KEY			123	
#  define RIGHT_KEY			124	
#  define UP_KEY				126
#  define DOWN_KEY			125	
#  define A_KEY				0
#  define S_KEY				1
#  define D_KEY				2
#  define W_KEY				13
#  define ESC 				53

# else
#  define LEFT_KEY			65361
#  define RIGHT_KEY			65363
#  define UP_KEY				65362
#  define DOWN_KEY			65364
#  define A_KEY				97
#  define W_KEY				119
#  define S_KEY				115
#  define D_KEY				100
#  define ESC				65307

#  define SPRITE_H			34
#  define SPRITE_W			34

# endif

typedef struct s_vettori
{
	int	x;
	int	y;
}	t_vettori;

typedef struct s_finestra
{
	void		*reference;
	t_vettori	size;
}	t_finestra;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int	a;
}	t_color;

typedef struct s_immagine
{
	void		*reference;
	t_vettori	pos;
	t_vettori	size;
}	t_immagine;

typedef struct s_game
{
	int			count_collec;
	int			count_steps;
	int			count_enemy;
}	t_game;

typedef struct s_programma
{
	void		*mlx;
	void		*win;
	char		**map;
	char		*pach;
	int			enemy;
	char		*pach1;
	char		*pach2;
	t_immagine	nemico;
	t_finestra	finestra;
	t_immagine	*sprite;
	t_vettori	sprite_position;
	t_game		game;
}	t_programma;

char	**ft_main_get(int fd);
char	*ft_itoa(int n);
char	*ft_strstr(char *haystack, char *needle);
int		error(char *msg);
int		ft_free_map(t_programma *program);
int		ft_free_exit(t_programma *program, char *messaggio);
int		muri(t_programma *program);
int		controllo_sprite(t_programma *program);
int		controllo_rettangolo(t_programma *program);
int		controllo_caratteri(t_programma *program);
int		check_mappa(t_programma *program);
int		ft_arnimazione_nemico(t_programma *program);
int		ft_carica_mappa(t_programma *program, int k, int j);
int		ft_stampa_passaggi(t_programma *program);
int		ft_nemico_ottenuto_posizione(t_programma *program);
int		ft_nemico_destra(t_programma *program);
int		ft_nemico_sotto(t_programma *program);
int		ft_nemico_sinistra(t_programma *program);
int		ft_nemico_su(t_programma *program);
int		ft_movimento_sinista(t_programma *program);
int		ft_movimento_destra(t_programma *program);
int		ft_movimento_giu(t_programma *program);
int		ft_movimento_su(t_programma *program);
int		ft_passaggi_del_nemico(int k, t_programma *program);
int		ft_conteggio_raccolta(t_programma *program);
int		ft_check_collezionabili(t_programma *program);
int		check_args(int argc, char **argv);
int		ft_grandezza_mappa(t_programma *program, char **argv);
int		ft_init(t_programma *program);
int		ft_ottenere_mappa(t_programma *program, char **argv);
int		ft_inizio_posizione(t_programma *program);
int		ft_controllo_nemico(t_programma *program);
int		ft_stampa_mappa(t_programma *program);
int		mlx_close(t_programma *program);
int		ft_key_press(int k, t_programma *program);
int		ft_esposizione(t_programma *program);
int		ft_pattuglia_nemica(t_programma *program);
int		ft_movimenti(int k, t_programma *program);
int		ft_movimento_s_d(int k, t_programma *program);
int		ft_movimento_s_g(int k, t_programma *program);
int		ft_pattuglia(t_programma *program);

#endif
