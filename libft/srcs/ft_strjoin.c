/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehubert <jehubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:05:55 by jehubert          #+#    #+#             */
/*   Updated: 2022/12/06 15:51:44 by jehubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	totlen;

	if (!s1 || !s2)
		return (NULL);
	totlen = ft_strlen(s1) + ft_strlen(s2);
	res = ft_calloc(sizeof(char), (totlen + 1));
	if (!res)
		return (NULL);
	ft_strlcat(res, (char *)s1, ft_strlen(s1) + 1);
	ft_strlcat(&res[ft_strlen(s1)], (char *)s2, ft_strlen(s2) + 1);
	return (res);
}
