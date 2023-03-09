/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehubert <jehubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:52:09 by jehubert          #+#    #+#             */
/*   Updated: 2022/12/06 15:51:57 by jehubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	int		i;

	if (!s || !f)
		return (NULL);
	i = -1;
	res = ft_calloc(1, ft_strlen(s) + 1);
	if (!res)
		return (NULL);
	while (s[++i])
		res[i] = (*f)(i, s[i]);
	res[i] = '\0';
	return (res);
}
