/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_esposizione.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguidoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:42:33 by vguidoni          #+#    #+#             */
/*   Updated: 2022/11/28 15:43:31 by vguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_esposizione(t_programma *program)
{
	ft_stampa_mappa(program);
	ft_stampa_passaggi(program);
	return (0);
}
