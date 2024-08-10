/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conteggio_raccolta.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguidoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:32:01 by vguidoni          #+#    #+#             */
/*   Updated: 2022/11/28 15:33:13 by vguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_conteggio_raccolta(t_programma *program)
{
	int	k;
	int	l;

	k = 0;
	program->game.count_collec = 0;
	while (k < program->finestra.size.y)
	{
		l = 0;
		while (l <= program->finestra.size.x)
		{
			if (program->map[k][l] == 'C')
				program->game.count_collec++;
			l++;
		}
		k++;
	}
	return (program->game.count_collec);
}

int	ft_check_collezionabili(t_programma *program)
{
	if (ft_conteggio_raccolta(program) == 0)
		ft_free_exit(program,
			"\e[34m\e[1mCOMPLIMENTI HAI RACCOLTO TUTTI GLI OGGETTI\e[0m\n");
	else
		printf("\e[35m\e[1mC'E' LA PUOI FARE!!!\e[0m\n");
	return (0);
}
