/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_controllo_sprite.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguidoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:12:16 by vguidoni          #+#    #+#             */
/*   Updated: 2022/11/28 15:13:07 by vguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	controllo_sprite(t_programma *program)
{
	int	line[3];
	int	k;
	int	l;

	k = 0;
	while (k < program->finestra.size.y)
	{
		l = 0;
		while (l <= program->finestra.size.x)
		{
			if (program->map[k][l] == 'P')
				line[0] = 1;
			if (program->map[k][l] == 'E')
				line[1] = 1;
			if (program->map[k][l] == 'C')
				line[2] = 1;
			l++;
		}
		k++;
	}
	if (line[0] != 1 || line[1] != 1 || line[2] != 1)
		error("la smetti di sbagliare");
	return (0);
}
