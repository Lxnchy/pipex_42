/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehubert <jehubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:49:47 by jehubert          #+#    #+#             */
/*   Updated: 2022/12/06 15:50:42 by jehubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	unsigned const char	*s;
	size_t				i;

	if (!dest || !src)
		return (dest);
	i = -1;
	d = (unsigned char *)dest;
	s = (unsigned const char *)src;
	while (++i < n)
		d[i] = s[i];
	return (dest);
}
