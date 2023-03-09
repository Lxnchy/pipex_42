/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehubert <jehubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:42:49 by jehubert          #+#    #+#             */
/*   Updated: 2022/12/06 15:52:10 by jehubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	is_set(char c, char *set)
{
	int	i;

	i = -1;
	while (set[++i])
		if (c == set[i])
			return (1);
	return (0);
}

static int	checkstart(char *s, char *set)
{
	int	i;

	i = 0;
	while (is_set(s[i], set) && s[i])
		i++;
	return (i);
}

static int	checkend(char *s, char *set)
{
	int	i;

	i = ft_strlen(s);
	while (is_set(s[i - 1], set) && i > 0)
		i--;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		start;
	int		end;

	if (!s1 || !set)
		return (NULL);
	if (s1[0] == 0)
		return (ft_calloc(1, 1));
	start = checkstart((char *)s1, (char *)set);
	end = checkend((char *)s1, (char *)set);
	if (start >= end)
		return (ft_calloc(1, 1));
	res = ft_calloc(sizeof(char), (end - start + 1));
	if (!res)
		return (NULL);
	ft_strlcpy(res, (char *)s1 + start, end - start + 1);
	return (res);
}
