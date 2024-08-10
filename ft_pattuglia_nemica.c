/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pattuglia_nemica.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguidoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:43:51 by vguidoni          #+#    #+#             */
/*   Updated: 2022/11/28 15:44:13 by vguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_pattuglia(t_programma *program)
{
	int	k;
	int	w;
	int	q;
	int	t;

	k = program->nemico.pos.y;
	w = program->nemico.pos.x;
	q = program->finestra.size.x;
	t = program->finestra.size.y;
	if ((program->map[k][w +1] == '0' || program->map[k][w +1] == 'P') &&
			program->game.count_enemy < q)
		ft_nemico_destra(program);
	else if ((program->map[k +1][w] == '0' || program->map[k +1][w] == 'P') &&
			program->game.count_enemy < (q + t))
		ft_nemico_sotto(program);
	else if ((program->map[k][w -1] == '0' || program->map[k][w -1] == 'P') &&
			program->game.count_enemy < ((2 * q) + t))
		ft_nemico_sinistra(program);
	else if ((program->map[k -1][w] == '0' || program->map[k -1][w] == 'P') &&
			program->game.count_enemy < (2 * (q + t)))
		ft_nemico_su(program);
	else
		program->game.count_enemy = 0;
	return (0);
}

int	ft_pattuglia_nemica(t_programma *program)
{
	usleep(200000);
	ft_nemico_ottenuto_posizione(program);
	ft_pattuglia(program);
	ft_stampa_mappa(program);
	ft_stampa_passaggi(program);
	return (0);
}
