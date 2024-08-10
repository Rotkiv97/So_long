/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movimento.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguidoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:20:55 by vguidoni          #+#    #+#             */
/*   Updated: 2022/12/06 16:21:16 by vguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_movimento_s_d(int k, t_programma *program)
{
	int	l;
	int	w;

	l = program->sprite->pos.x;
	w = program->sprite->pos.y;
	if ((k == A_KEY) && (program->map[w][l -1] == 'E'))
		ft_check_collezionabili(program);
	else if ((k == A_KEY) && (program->map[w][l -1] != '1'))
		ft_movimento_sinista(program);
	if ((k == D_KEY) && (program->map[w][l +1] == 'E'))
		ft_check_collezionabili(program);
	else if ((k == D_KEY) && (program->map[w][l +1] != '1'))
		ft_movimento_destra(program);
	return (0);
}

int	ft_movimento_s_g(int k, t_programma *program)
{
	int	w;
	int	l;

	l = program->sprite->pos.x;
	w = program->sprite->pos.y;
	if ((k == S_KEY) && (program->map[w +1][l] == 'E'))
		ft_check_collezionabili(program);
	else if ((k == S_KEY) && (program->map[w + 1][l] != '1'))
		ft_movimento_giu(program);
	if ((k == W_KEY) && (program->map[w -1][l] == 'E'))
		ft_check_collezionabili(program);
	else if ((k == W_KEY) && (program->map[w -1][l] != '1'))
		ft_movimento_su(program);
	return (0);
}
