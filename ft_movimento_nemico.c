/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movimento_nemico.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguidoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:17:21 by vguidoni          #+#    #+#             */
/*   Updated: 2022/11/28 15:18:33 by vguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_nemico_destra(t_programma *program)
{
	if (program->map[program->nemico.pos.y][program->nemico.pos.x +1] == 'P')
		ft_free_exit(program, "\e[31m\e[1mGAME OVER\n");
	program->map[program->nemico.pos.y][program->nemico.pos.x] = '0';
	program->nemico.pos.x += 1;
	program->map[program->nemico.pos.y][program->nemico.pos.x] = 'Y';
	program->game.count_enemy++;
	return (0);
}

int	ft_nemico_sotto(t_programma *program)
{
	if (program->map[program->nemico.pos.y +1][program->nemico.pos.x] == 'P')
		ft_free_exit(program, "\e[31m\e[1mGAME OVER\n");
	program->map[program->nemico.pos.y][program->nemico.pos.x] = '0';
	program->nemico.pos.y += 1;
	program->map[program->nemico.pos.y][program->nemico.pos.x] = 'Y';
	program->game.count_enemy++;
	return (0);
}

int	ft_nemico_sinistra(t_programma *program)
{
	if (program->map[program->nemico.pos.y][program->nemico.pos.x -1] == 'P')
		ft_free_exit(program, "\e[31m\e[1mGAME OVER\n");
	program->map[program->nemico.pos.y][program->nemico.pos.x] = '0';
	program->nemico.pos.x -= 1;
	program->map[program->nemico.pos.y][program->nemico.pos.x] = 'Y';
	program->game.count_enemy++;
	return (0);
}

int	ft_nemico_su(t_programma *program)
{
	if (program->map[program->nemico.pos.y -1][program->nemico.pos.x] == 'P')
		ft_free_exit(program, "\e[31m\e[1mGAME OVER\n");
	program->map[program->nemico.pos.y][program->nemico.pos.x] = '0';
	program->nemico.pos.y -= 1;
	program->map[program->nemico.pos.y][program->nemico.pos.x] = 'Y';
	program->game.count_enemy++;
	return (0);
}
