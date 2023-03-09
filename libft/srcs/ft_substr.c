/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehubert <jehubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:07:07 by jehubert          #+#    #+#             */
/*   Updated: 2022/12/06 15:52:13 by jehubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	char	*scpy;

	if (!s)
		return (NULL);
	scpy = &((char *)s)[start];
	if (start > ft_strlen(s))
		return (ft_calloc(1, 1));
	if (len > ft_strlen(scpy))
		len = ft_strlen(scpy);
	sub = ft_calloc(sizeof(char), (len + 1));
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, scpy, len + 1);
	return (sub);
}
