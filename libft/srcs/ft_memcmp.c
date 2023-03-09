/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehubert <jehubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:01:42 by jehubert          #+#    #+#             */
/*   Updated: 2022/12/06 15:50:36 by jehubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1cpy;
	unsigned char	*s2cpy;

	if (!s1 || !s2 || n == 0)
		return (0);
	s1cpy = (unsigned char *)s1;
	s2cpy = (unsigned char *)s2;
	while (n)
	{
		if (*s1cpy - *s2cpy)
			return (*s1cpy - *s2cpy);
		n--;
		s1cpy++;
		s2cpy++;
	}
	return (0);
}
