/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nemico.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguidoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:15:21 by vguidoni          #+#    #+#             */
/*   Updated: 2022/11/28 15:17:03 by vguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_arnimazione_nemico(t_programma *program)
{
    void *tmp = NULL;
    if (!program || program->nemico.pos.x < 0) {
        error("Posizione del nemico non inizializzata correttamente");
        return -1;
    }

    program->sprite->size.x = 0;
    program->sprite->size.y = 0;

    if (program->sprite->reference != NULL) {
        mlx_destroy_image(program->mlx, program->sprite->reference);
    }

    if (program->nemico.pos.x % 2 == 0) {
        tmp = mlx_xpm_file_to_image(program->mlx,
                "./xpm/npc1.xpm", &program->sprite->size.x,
                &program->sprite->size.y);
    } else {
        tmp = mlx_xpm_file_to_image(program->mlx,
                "./xpm/npc2.xpm", &program->sprite->size.x,
                &program->sprite->size.y);
    }

    if (tmp == NULL) {
        error("npc non ha la texture");
        return -1;
    }

    program->sprite->reference = tmp;
    return 0;
}



int	ft_nemico_ottenuto_posizione(t_programma *program)
{
	int	k;
	int	l;

	k = 0;
	while (k < program->finestra.size.y)
	{
		l = 0;
		while (l <= program->finestra.size.x)
		{
			if (program->map[k][l] == 'Y')
			{
				program->nemico.pos.x = l;
				program->nemico.pos.y = k;
			}
			l++;
		}
		k++;
	}
	return (0);
}

int	ft_passaggi_del_nemico(int k, t_programma *program)
{
	int	w;
	int	l;

	w = program->sprite->pos.y;
	l = program->sprite->pos.x;
	if ((k == A_KEY) && (program->map[w][l - 1] == 'Y'))
		ft_free_exit(program, "\e[31m\e[1mGAME OVER\e[0m\n");
	if ((k == D_KEY) && (program->map[w][l + 1] == 'Y'))
		ft_free_exit(program, "\e[31m\e[1mGAME OVER\e[0m\n");
	if ((k == S_KEY) && (program->map[w + 1][l] == 'Y'))
		ft_free_exit(program, "\e[31m\e[1mGAME OVER\e[0m\n");
	if ((k == W_KEY) && (program->map[w - 1][l] == 'Y'))
		ft_free_exit(program, "\e[31m\e[1mGAME OVER\e[0m\n");
	return (0);
}

int	ft_controllo_nemico(t_programma *program)
{
	int	k;
	int	y;

	k = 0;
	while (k < program->finestra.size.y)
	{
		y = 0;
		while (program->map[k][y])
		{
			if (program->map[k][y])
				program->enemy++;
			y++;
		}
		k++;
	}
	return (0);
}
