/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehubert <jehubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:31:39 by jehubert          #+#    #+#             */
/*   Updated: 2022/12/06 15:51:48 by jehubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;

	if (!src)
		return (0);
	j = ft_strlen(src);
	if (!dest || size == 0)
		return (j);
	i = ft_strlen(dest);
	k = 0;
	if (size <= i)
		j = j + size;
	else
		j = j + i;
	while (i + 1 < size && src[k] != '\0')
	{
		dest[i] = src[k];
		i++;
		k++;
	}
	if (i < size)
		dest[i] = '\0';
	return (j);
}
