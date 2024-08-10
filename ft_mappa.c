/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mappa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguidoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:35:28 by vguidoni          #+#    #+#             */
/*   Updated: 2022/11/28 15:36:10 by vguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_grandezza_mappa(t_programma *program, char **argv)
{
	int		fd;
	char	**line;
	char	n;

	program->finestra.size.x = 0;
	program->finestra.size.y = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error("riprova");
	line = ft_main_get(fd);
	program->map = line;
	close(fd);
	fd = open(argv[1], O_RDONLY);
	if (line == NULL)
		return (0);
	while (read(fd, &n, 1) != 0)
		if (n == '\n')
			program->finestra.size.y++;
	program->finestra.size.x = ft_strlen(line[0]);
	close(fd);
	return (0);
}

int	ft_ottenere_mappa(t_programma *program, char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error("RIPROVA");
	close(fd);
	check_mappa(program);
	return (0);
}

int ft_carica_mappa(t_programma *program, int k, int j)
{
    // Inizializza le coordinate della posizione
    if(program->sprite->reference){
        mlx_destroy_image(program->mlx, program->sprite->reference);
        program->sprite->reference = NULL;
    }
    program->sprite->pos.x = 0;
    program->sprite->pos.y = 0;
    void *tmp = NULL;
    if (program->map[k][j] == ' ' || program->map[k][j] == '\n' || program->map[k][j] == '\0') {
        return 0;
    }
    // Carica la nuova immagine in base al carattere
    if (program->map[k][j] == '1')
        tmp = mlx_xpm_file_to_image(program->mlx,"muro(1).xpm", &program->sprite->pos.x,  &program->sprite->pos.y);
    else if (program->map[k][j] == '0')
        tmp = mlx_xpm_file_to_image(program->mlx, "pavimento.xpm", &program->sprite->pos.x, &program->sprite->pos.y);
    else if (program->map[k][j] == 'E')
        tmp = mlx_xpm_file_to_image(program->mlx,"exit.xpm", &program->sprite->pos.x, &program->sprite->pos.y);
    else if (program->map[k][j] == 'C')
        tmp = mlx_xpm_file_to_image(program->mlx,"coll.xpm", &program->sprite->pos.x,&program->sprite->pos.y);
    else if (program->map[k][j] == 'P')
        tmp = mlx_xpm_file_to_image(program->mlx,program->pach, &program->sprite->pos.x, &program->sprite->pos.y);
    else if (program->map[k][j] == 'Y' && program->enemy > 0){
        ft_arnimazione_nemico(program);
        return 0;
    }
    if (tmp == NULL)
    {
        error("\033[31mTexture non caricata\033[37m");
        return -1;
    }
    program->sprite->reference = tmp;

    return 0;
}


int	ft_stampa_mappa(t_programma *program)
{
	int	k;
	int	l;

	k = 0;
	
	while (k < program->finestra.size.y)
	{
		l = 0;
		while (l < program->finestra.size.x)
		{ 
			ft_carica_mappa(program, k , l);
			if(program->sprite->reference != NULL)
				mlx_put_image_to_window(program->mlx, program->win,
					program->sprite->reference, SPRITE_W * l, SPRITE_H * k);
			l++;
		}
		k++;
	}
	return (0);
}
