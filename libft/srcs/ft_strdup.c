/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehubert <jehubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:34:13 by jehubert          #+#    #+#             */
/*   Updated: 2022/12/06 15:51:37 by jehubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *s)
{
	char	*new;

	new = ft_calloc(sizeof(char), (ft_strlen(s) + 1));
	if (!new)
		return (NULL);
	ft_strlcpy(new, (char *)s, ft_strlen(s) + 1);
	return (new);
}
