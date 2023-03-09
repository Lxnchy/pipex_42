/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehubert <jehubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:29:54 by jehubert          #+#    #+#             */
/*   Updated: 2022/12/06 15:52:04 by jehubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (!big || !little)
		return (NULL);
	if (*little == '\0')
		return ((char *)big);
	i = -1;
	j = 0;
	if (big[0] == little[0] && len == 1)
		return ((char *)big);
	while (big[++i] && i + 1 < len)
	{
		j = -1;
		while (little[++j] && big[i + j] && i + j < len)
			if (little[j] != big[i + j])
				break ;
		if (little[j] == '\0')
			return ((char *)&big[i]);
	}
	return (NULL);
}
