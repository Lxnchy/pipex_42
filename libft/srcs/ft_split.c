/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehubert <jehubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 08:25:51 by jehubert          #+#    #+#             */
/*   Updated: 2023/02/28 23:30:45 by jehubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	sublen(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static int	nbw(char const *s, char c)
{
	int	nb;
	int	i;

	nb = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			nb++;
		while (s[i] != c && s[i])
			i++;
	}
	return (nb);
}

static char	**clean_split(char **split)
{
	unsigned int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**spl;
	int		nb;
	int		i;

	if (!s)
		return (NULL);
	nb = -1;
	spl = ft_calloc(sizeof(char *), nbw(s, c) + 1);
	if (!spl)
		return (NULL);
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			spl[++nb] = ft_substr(s, i, sublen(&s[i], c));
			if (!spl[nb])
				return (clean_split(spl));
		}
		while (s[i] && s[i] != c)
			i++;
	}
	return (spl);
}
