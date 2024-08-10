/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stampa_passaggi.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguidoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:19:48 by vguidoni          #+#    #+#             */
/*   Updated: 2022/11/28 15:21:21 by vguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_stampa_passaggi(t_programma *program)
{
	char	*str;

	str = ft_itoa(program->game.count_steps);
	mlx_string_put(program->mlx, program->win, (program->sprite->pos.x) + 5,
		(program->sprite->pos.y) + 10, 0x83300, str);
	free(str);
	return (0);
}
