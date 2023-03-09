/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdlist.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehubert <jehubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:39:35 by jehubert          #+#    #+#             */
/*   Updated: 2023/03/02 22:26:59 by jehubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	ft_split_size(char **spl)
{
	int	i;

	i = 0;
	while (spl[i])
		i++;
	return (i);
}

t_cmdlist	*ft_newcmd(char **cmd)
{
	t_cmdlist	*new;

	new = malloc(sizeof(t_cmdlist));
	if (!new)
		return (NULL);
	new->cmd = cmd;
	new->n = NULL;
	new->size = ft_split_size(cmd);
	return (new);
}

void	ft_cmdaddback(t_cmdlist **cmds, t_cmdlist *new)
{
	t_cmdlist	*tmp;

	if (!new)
		return ;
	if (!*cmds)
	{
		*cmds = new;
		return ;
	}
	tmp = *cmds;
	while (tmp->n)
		tmp = tmp->n;
	tmp->n = new;
}
