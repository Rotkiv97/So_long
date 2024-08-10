/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguidoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:08:38 by vguidoni          #+#    #+#             */
/*   Updated: 2022/11/28 15:08:42 by vguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_free_map(t_programma *program)
{
	int	k;

	k = 0;
	mlx_destroy_window(program->mlx, program->win);
	free(program->mlx);
	while (k < program->finestra.size.y)
	{
		free(program->map[k]);
		k++;
	}
	free(program->map);
	return (0);
}

int	ft_free_exit(t_programma *program, char *messaggio)
{
	printf("%s", messaggio);
	ft_free_map(program);
	exit (0);
}
