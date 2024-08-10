/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguidoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:44:47 by vguidoni          #+#    #+#             */
/*   Updated: 2022/11/28 15:45:19 by vguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void clean_up(t_programma *program)
{
    if (program->sprite)
    {
        if (program->sprite->reference)
        {
            mlx_destroy_image(program->mlx, program->sprite->reference);
        }
        free(program->sprite);
    }

    if (program->win)
    {
        mlx_destroy_window(program->mlx, program->win);
    }

    if (program->mlx)
    {
        free(program->mlx);
    }
}

//valgrind --gen-suppressions=all --log-file=valgrind-suppressions.txt ./so_long map.ber

int	main(int argc, char **argv)
{
	t_programma	program;

	program.sprite = (t_immagine *)malloc(sizeof(t_immagine));
	if(!program.sprite)
		error("sprite, non allocata");
	program.sprite->reference = NULL;
	program.sprite->pos.x = 0;
    program.sprite->pos.y = 0;
	program.nemico.pos.x = 0;
    program.nemico.pos.y = 0;
	 program.mlx = NULL;
    program.win = NULL;
    program.enemy = 0;
	check_args(argc, argv);
	ft_grandezza_mappa(&program, argv);
	ft_init(&program);
	ft_ottenere_mappa(&program, argv);
	ft_controllo_nemico(&program);
	ft_conteggio_raccolta(&program);
	program.mlx = mlx_init();
	program.win = mlx_new_window(program.mlx,
			(program.finestra.size.x -1) * SPRITE_W,
			program.finestra.size.y * SPRITE_H,
			"IL GIARDINO DEI MOSTRI");
	ft_stampa_mappa(&program);
	mlx_hook(program.win, X_EVENT_KEY_PRESS, 1L << 0, ft_key_press, &program);
	mlx_hook(program.win, X_EVENT_KEY_EXIT, 1L << 0, mlx_close, &program);
	mlx_expose_hook(program.win, ft_esposizione, &program);
	if (program.enemy > 0)
		mlx_loop_hook(program.mlx, ft_pattuglia_nemica, &program);
	mlx_loop(program.mlx);
	clean_up(&program);
}
