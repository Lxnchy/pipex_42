/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehubert <jehubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:03:22 by jehubert          #+#    #+#             */
/*   Updated: 2022/12/06 15:52:07 by jehubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			len;
	unsigned char	d;

	if (!s)
		return (NULL);
	d = (unsigned char)c;
	len = ft_strlen(s) + 1;
	while (len--)
		if (s[len] == d)
			return ((char *)&s[len]);
	return (NULL);
}
