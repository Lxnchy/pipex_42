/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehubert <jehubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:55:04 by jehubert          #+#    #+#             */
/*   Updated: 2022/12/06 15:51:01 by jehubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	putnbrhex(unsigned long long nb, int *i, int size)
{
	char	*base;

	if (size)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (nb / 16)
		putnbrhex(nb / 16, i, size);
	ft_putchar_fd(base[nb % 16], 1);
	*i = *i + 1;
	(void)i;
}

int	hexmaster(unsigned long long nb, int size, int isptr)
{
	int	i;

	i = 0;
	if (isptr && nb == 0)
		return (ftputstr(NPTR));
	if (isptr)
		i = ftputstr("0x");
	putnbrhex(nb, &i, size);
	return (i);
}

int	checkflag(char flag, va_list *args)
{
	if (flag == 'c')
		return ((char)ftputchar(va_arg(*args, int)));
	else if (flag == 's')
		return (ftputstr(va_arg(*args, char *)));
	else if (flag == 'p')
		return (hexmaster((unsigned long long)va_arg(*args, void *), 0, 1));
	else if (flag == 'i')
		return (ftputnbr(va_arg(*args, int)));
	else if (flag == 'd')
		return (ftputnbr(va_arg(*args, int)));
	else if (flag == 'u')
		return (uintmaster(va_arg(*args, unsigned int)));
	else if (flag == 'x')
		return (hexmaster(va_arg(*args, unsigned int), 0, 0));
	else if (flag == 'X')
		return (hexmaster(va_arg(*args, unsigned int), 1, 0));
	else if (flag == '%')
		return (ftputchar('%'));
	else
		return (0);
}

int	ft_printf(const char *av, ...)
{
	int		cnt;
	int		i;
	va_list	args;

	cnt = 0;
	i = 0;
	va_start(args, av);
	while (av[i])
	{
		if (av[i] == '%' && av[i + 1])
		{
			i++;
			cnt += checkflag(av[i], &args);
		}
		else
			cnt += ftputchar(av[i]);
		i++;
	}
	va_end(args);
	return (cnt);
}
