/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehubert <jehubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 22:44:23 by jehubert          #+#    #+#             */
/*   Updated: 2023/03/02 22:32:13 by jehubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static int	ft_nb_tkn(char *cmd, char one, char two)
{
	int	i;
	int	in;
	int	out;

	i = -1;
	in = 0;
	out = 0;
	while (++i < (int)ft_strlen(cmd))
	{
		if (cmd[i] == one)
			in++;
		if (cmd[i] == two)
			out++;
	}
	return ((in + out) % 2 == 0);
}

static char	ft_check_all_token(char *cmd)
{
	if (!cmd)
		return (0);
	if (!ft_nb_tkn(cmd, '\'', 0))
		return (0);
	if (!ft_nb_tkn(cmd, '\"', 0))
		return (0);
	if (!ft_nb_tkn(cmd, '{', '}'))
		return (0);
	return (1);
}

static void	ft_rotate_cmd(char **cmd, int i, int j, char *new)
{
	int	size;
	int	k;

	size = -1;
	k = 1;
	while (cmd[++size])
		;
	cmd[j] = new;
	ft_remove_quote(cmd[j]);
	while (++i < size + 1)
	{
		cmd[j + k] = cmd[i];
		k++;
	}
}

static void	ft_check_cmd(char **cmd)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	while (cmd[i] && cmd[i + 1])
	{
		if (ft_check_all_token(cmd[i]))
			i++;
		else
		{
			tmp = cmd[i];
			j = i;
			while (!ft_check_all_token(tmp) && cmd[++i])
			{
				tmp = ft_new_strjoin(tmp, " ");
				tmp = ft_new_strjoin(tmp, cmd[i]);
			}
			ft_rotate_cmd(cmd, i, j, tmp);
		}
	}
}

t_cmdlist	*ft_cmd_split(t_pipex *px, char **av, int ac)
{
	int			i;
	t_cmdlist	*new;
	t_cmdlist	*tmp;

	i = 1 + px->here_doc;
	new = NULL;
	while (++i < ac - 1)
		ft_cmdaddback(&new, ft_newcmd(ft_split(av[i], ' ')));
	tmp = new;
	while (tmp)
	{
		ft_check_cmd(tmp->cmd);
		tmp = tmp->n;
	}
	return (new);
}
