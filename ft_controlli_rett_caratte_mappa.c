/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_controlli_rett_caratte_mappa.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguidoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:14:05 by vguidoni          #+#    #+#             */
/*   Updated: 2022/11/28 15:14:48 by vguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	controllo_rettangolo(t_programma *program)
{
	int	k;

	k = 0;
	while (k < program->finestra.size.y)
	{
		if (program->finestra.size.x != (int)ft_strlen(program->map[k]))
			error("il subjet richiede un rettamgolo");
		k++;
	}
	return (0);
}

int	controllo_caratteri(t_programma *program)
{
	int	k;
	int	l;

	k = 0;
	while (program->map[k] != 0)
	{
		l = 0;
		while (program->map[k][l] != '\n')
		{
			if (program->map[k][l] != '0' && program->map[k][l] != '1'
			&& program->map[k][l] != 'P' && program->map[k][l] != 'E'
			&& program->map[k][l] != 'C' && program->map[k][l] != 'Y')
				error("carattere sconosciuto");
			l++;
		}
		k++;
	}
	return (0);
}

int	check_mappa(t_programma *program)
{
	muri(program);
	controllo_sprite(program);
	controllo_rettangolo(program);
	controllo_caratteri(program);
	return (0);
}
