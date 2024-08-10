/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movimento_pleyer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguidoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:22:09 by vguidoni          #+#    #+#             */
/*   Updated: 2022/11/28 15:22:52 by vguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_movimento_sinista(t_programma *program)
{
	program->map[program->sprite->pos.y][program->sprite->pos.x] = '0';
	program->sprite->pos.x -= 1;
	program->map[program->sprite->pos.y][program->sprite->pos.x] = 'P';
	program->game.count_steps++;
	program->pach = "player11.xpm";
	return (0);
}

int	ft_movimento_destra(t_programma *program)
{
	program->map[program->sprite->pos.y][program->sprite->pos.x] = '0';
	program->sprite->pos.x += 1;
	program->map[program->sprite->pos.y][program->sprite->pos.x] = 'P';
	program->game.count_steps++;
	program->pach = "player10.xpm";
	return (0);
}

int	ft_movimento_giu(t_programma *program)
{
	program->map[program->sprite->pos.y][program->sprite->pos.x] = '0';
	program->sprite->pos.y += 1;
	program->map[program->sprite->pos.y][program->sprite->pos.x] = 'P';
	program->game.count_steps++;
	program->pach = "player5.xpm";
	return (0);
}

int	ft_movimento_su(t_programma *program)
{
	program->map[program->sprite->pos.y][program->sprite->pos.x] = '0';
	program->sprite->pos.y -= 1;
	program->map[program->sprite->pos.y][program->sprite->pos.x] = 'P';
	program->game.count_steps++;
	program->pach = "player3.xpm";
	return (0);
}

int	ft_movimenti(int k, t_programma *program)
{
	if (program->sprite->pos.x == 0 && program->sprite->pos.y == 0)
		ft_inizio_posizione(program);
	ft_movimento_s_d(k, program);
	ft_movimento_s_g(k, program);
	return (0);
}
