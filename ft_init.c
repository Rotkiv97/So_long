/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguidoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:36:26 by vguidoni          #+#    #+#             */
/*   Updated: 2022/11/28 15:36:53 by vguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_init(t_programma *program)
{
	program->game.count_steps = 0;
	program->game.count_enemy = 0;
	program->sprite->pos.x = 0;
	program->sprite->pos.y = 0;
	program->enemy = 0;
	program->pach = "player3.xpm";
	return (0);
}
