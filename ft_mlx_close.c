/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_close.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguidoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:40:57 by vguidoni          #+#    #+#             */
/*   Updated: 2022/11/28 15:41:19 by vguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	mlx_close(t_programma *program)
{
	ft_free_exit(program, "\e[33m\e[1mFattelo piacere\e[0m\n");
	return (0);
}
