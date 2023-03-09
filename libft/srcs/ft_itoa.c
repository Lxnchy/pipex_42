/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehubert <jehubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 17:03:03 by jehubert          #+#    #+#             */
/*   Updated: 2022/12/06 15:49:50 by jehubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	intlen(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	fill_char(unsigned int n, int sign, char *res)
{
	static int	i;
	char		temp;

	i = 0;
	if (sign < 0 && ++i - 1 == 0)
		res[0] = '-';
	temp = n % 10 + '0';
	n /= 10;
	if (n != 0)
		fill_char(n, sign, res);
	res[i] = temp;
	i++;
}

char	*ft_itoa(int n)
{
	char			*res;
	int				sign;
	unsigned int	nb;

	sign = 1;
	if (n < 0)
	{
		nb = -n;
		res = ft_calloc(1, intlen(n) + 2);
		sign = -1;
	}
	else
	{
		res = ft_calloc(1, intlen(n) + 1);
		nb = n;
	}
	if (!res)
		return (NULL);
	fill_char(nb, sign, res);
	return (res);
}
