/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehubert <jehubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:41:53 by jehubert          #+#    #+#             */
/*   Updated: 2022/12/06 15:50:33 by jehubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s2;
	unsigned char	d;

	if (!s)
		return (NULL);
	s2 = (unsigned char *)s;
	d = (unsigned char)c;
	while (n)
	{
		if (*s2 == d)
			return (s2);
		s2++;
		n--;
	}
	return (NULL);
}
