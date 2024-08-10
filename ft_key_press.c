/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_press.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguidoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:41:45 by vguidoni          #+#    #+#             */
/*   Updated: 2022/11/28 15:42:08 by vguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_key_press(int k, t_programma *program)
{
	int	iniziopass;

	iniziopass = program->game.count_steps;
	if (k == ESC)
	{
		ft_free_exit(program, "\e[33m\e[1msei uscito(ESC)\e[0m\n");
	}
	else
	{
		ft_movimenti(k, program);
		if (program->enemy > 0)
			ft_passaggi_del_nemico(k, program);
	}
	if (iniziopass != program->game.count_steps)
		printf("MOSSE: %d\n", program->game.count_steps);
	ft_stampa_mappa(program);
	ft_stampa_passaggi(program);
	return (0);
}
