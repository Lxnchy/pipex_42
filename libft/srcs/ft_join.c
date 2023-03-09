/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehubert <jehubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 22:35:29 by jehubert          #+#    #+#             */
/*   Updated: 2023/03/01 16:52:25 by jehubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_join(char *s1, char s2)
{
	char	*res;

	res = ft_realloc(s1, ft_strlen(s1) + 2);
	if (!res)
		return ;
	res[ft_strlen(s1)] = s2;
	res[ft_strlen(s1) + 1] = '\0';
	s1 = res;
}
