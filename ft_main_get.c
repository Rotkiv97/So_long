/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguidoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:45:55 by vguidoni          #+#    #+#             */
/*   Updated: 2022/12/06 12:46:05 by vguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	**ft_main_get(int fd)
{
	char	**line;
	int		l;

	l = 0;
	line = malloc(sizeof(char *) * (22 + 1));
	while (l <= 22)
	{
		line[l] = get_next_line(fd);
		if (line[l] == NULL)
			break ;
		l++;
	}
	return (line);
}
