/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehubert <jehubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:20:34 by jehubert          #+#    #+#             */
/*   Updated: 2022/12/06 15:52:26 by jehubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	gnl_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

size_t	gnl_strlcat(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	k;

	i = gnl_strlen(dest);
	k = 0;
	if (size == 0)
		return (0);
	while (i + 1 < size && src[k])
	{
		dest[i] = src[k];
		i++;
		k++;
	}
	if (i < size)
		dest[i] = '\0';
	return (1);
}

int	gnl_strchr(char *s, int c)
{
	int				i;
	unsigned char	d;

	if (!s)
		return (-1);
	d = (unsigned char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == d)
			return (i);
		i++;
	}
	if (s[i] == c)
		return (i);
	return (-1);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*res;

	res = malloc(gnl_strlen(s1) + gnl_strlen(s2) + 1);
	if (!res)
	{
		free(s1);
		free(s2);
		return (NULL);
	}
	res[0] = '\0';
	gnl_strlcat(res, s1, gnl_strlen(s1) + 1);
	gnl_strlcat(&res[gnl_strlen(s1)], s2, gnl_strlen(s2) + 1);
	free(s1);
	free(s2);
	return (res);
}

size_t	gnl_strlcpy(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	src_len = gnl_strlen(src);
	i = 0;
	if (size == 0)
		return (src_len);
	while (i + 1 < size && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_len);
}
