/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguidoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:03:31 by vguidoni          #+#    #+#             */
/*   Updated: 2022/11/28 15:03:35 by vguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_bzero(void *s, size_t n)
{
	size_t	j;
	char	*y;

	j = 0;
	y = s;
	while (j < n)
	{
		y[j] = '\0';
		j++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;
	size_t	y;

	y = size * nmemb;
	if (nmemb != 0 && size != y / nmemb)
		return (NULL);
	p = (void *)malloc(y);
	if (p == NULL)
		return (NULL);
	ft_bzero(p, y);
	return (p);
}

static int	ft_mbcount(long int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		count++;
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static char	*ft_reverse( long int n, char *k)
{
	size_t		y;

	y = ft_mbcount(n);
	k[y] = '\0';
	if (n == 0)
		k[0] = '0';
	if (n < 0)
	{
		k[0] = '-';
		n *= -1;
	}
	y--;
	while (n != 0)
	{
		k[y] = (n % 10) + 48;
		n /= 10;
		y--;
	}
	return (k);
}

char	*ft_itoa(int n)
{
	char		*k;
	size_t		f;
	long int	l;

	l = n;
	f = ft_mbcount(l);
	k = ft_calloc((f + 1), sizeof(char));
	ft_reverse(l, k);
	return (k);
}
