/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inizio_posizione.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguidoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:37:26 by vguidoni          #+#    #+#             */
/*   Updated: 2022/11/28 15:37:58 by vguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_inizio_posizione(t_programma *program)
{
	int	k;
	int	y;

	k = 0;
	while (program->map[k])
	{
		y = 0;
		while (program->map[k][y])
		{
			if (program->map[k][y] == 'P')
			{
				program->sprite->pos.x = y;
				program->sprite->pos.y = k;
			}
			y++;
		}
		k++;
	}
	return (0);
}
