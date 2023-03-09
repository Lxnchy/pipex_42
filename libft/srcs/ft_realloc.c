/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehubert <jehubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 21:01:13 by jehubert          #+#    #+#             */
/*   Updated: 2023/03/02 19:50:56 by jehubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*new;

	if (!ptr)
		return (ft_calloc(size, 1));
	new = ft_calloc(size, 1);
	if (!new)
		return (NULL);
	ft_memmove(new, ptr, size);
	free(ptr);
	return (new);
}
