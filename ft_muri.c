/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_muri.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguidoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:11:00 by vguidoni          #+#    #+#             */
/*   Updated: 2022/11/28 15:11:40 by vguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	muri(t_programma *program)
{
	int	k;
	int	l;

	k = 0;
	while (k < program->finestra.size.y)
	{
		l = 0;
		if (k == 0 || k == (program->finestra.size.y -1))
		{
			while (program->map[k][l] != '\n' &&
				program->map[k][l] != '\0')
			{
				if (program->map[k][l] != '1')
					error("la mappa non e valida");
				l++;
			}
		}
		if (program->map[k][0] != '1' ||
			program->map[k][program->finestra.size.x -2] != '1')
			error("il muro laterale non a norma");
		k++;
	}
	return (0);
}
