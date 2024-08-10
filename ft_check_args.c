/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguidoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:34:30 by vguidoni          #+#    #+#             */
/*   Updated: 2022/11/28 15:34:59 by vguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_args(int argc, char **argv)
{
	if (argc < 2)
		error("prova a mettere 2 argomenti\n");
	if (argc > 2)
		error("hai messo troppi argomenti\n");
	if (ft_strstr(argv[1], ".ber") == NULL)
		error("prova a mettere.ber");
	return (0);
}
