/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehubert <jehubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:22:44 by jehubert          #+#    #+#             */
/*   Updated: 2022/12/06 15:50:50 by jehubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ftputchar(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ftputstr(char *str)
{
	if (!str)
		return (ftputstr("(null)"));
	ft_putstr_fd(str, 1);
	return ((int)ft_strlen(str));
}

int	ftputnbr(int nb)
{
	int	i;

	i = 0;
	if (!nb)
		return (ftputchar('0'));
	ft_putnbr_fd(nb, 1);
	if (nb < 0)
		i++;
	while (nb)
	{
		nb /= 10;
		i++;
	}
	(void)nb;
	return (i);
}

int	uintmaster(unsigned int nb)
{
	int	i;

	i = 0;
	put_uint(nb, &i);
	return (i);
}

void	put_uint(unsigned int nb, int *i)
{
	char	temp;

	temp = nb % 10 + '0';
	if (nb / 10)
		put_uint(nb / 10, i);
	ft_putchar_fd(temp, 1);
	*i = *i + 1;
}
