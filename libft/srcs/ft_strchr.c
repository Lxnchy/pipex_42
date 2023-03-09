/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehubert <jehubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:43:24 by jehubert          #+#    #+#             */
/*   Updated: 2023/02/28 23:20:55 by jehubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	char			*s2;
	unsigned char	d;

	s2 = (char *)s;
	d = (unsigned char)c;
	while (*s2)
	{
		if (*s2 == d)
			return (s2);
		s2++;
	}
	if (*s2 == c)
		return (s2);
	return (NULL);
}
