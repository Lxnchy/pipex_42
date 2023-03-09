/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehubert <jehubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 00:32:52 by jehubert          #+#    #+#             */
/*   Updated: 2023/03/02 22:38:19 by jehubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_fd_dup2(int a, int b)
{
	dup2(a, 0);
	close(a);
	dup2(b, 1);
	close(b);
}

void	ft_clean_pipes(t_pipex *px, int ac)
{
	int		i;

	i = -1;
	while (++i < (ac - 4) * 2)
		close(px->pfd[i]);
}

void	ft_clean_split(char **split, int size)
{
	int	i;

	i = -1;
	if (!size)
	{
		while (split[++i])
			free(split[i]);
	}
	else
	{
		while (++i < size)
			free(split[i]);
	}
	free(split);
}

void	ft_master_free(t_pipex *px, int ac)
{
	t_cmdlist	*to_free;

	while (px->cmd)
	{
		to_free = px->cmd;
		px->cmd = px->cmd->n;
		ft_clean_split(to_free->cmd, ft_split_size(to_free->cmd));
		free(to_free);
	}
	close(px->input_file);
	close(px->output_file);
	ft_clean_split(px->paths, 0);
	ft_clean_pipes(px, ac);
	free(px->pfd);
	free(px->pid);
}

void	ft_remove_quote(char *cmd)
{
	int	i;

	if (cmd[ft_strlen(cmd) - 1] == '\'')
		cmd[ft_strlen(cmd) - 1] = 0;
	if (cmd[0] == '\'')
	{
		i = -1;
		while (++i < (int)ft_strlen(cmd))
			cmd[i] = cmd[i + 1];
	}
}
