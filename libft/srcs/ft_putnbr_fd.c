/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehubert <jehubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:39:29 by jehubert          #+#    #+#             */
/*   Updated: 2022/12/06 15:51:13 by jehubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void	real_putnbr(unsigned int n, int fd)
{
	if (n / 10)
		real_putnbr(n / 10, fd);
	ft_putchar_fd(n % 10 + '0', fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	n2;

	n2 = 0;
	if (n < 0)
	{
		n2 = -n;
		ft_putchar_fd('-', fd);
	}
	else if (n >= 0)
		n2 = n;
	real_putnbr(n2, fd);
}
