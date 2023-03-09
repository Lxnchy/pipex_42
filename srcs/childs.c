/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehubert <jehubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:14:06 by jehubert          #+#    #+#             */
/*   Updated: 2023/03/02 22:36:17 by jehubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static char	*ft_cmd_check(t_pipex *px, int ac)
{
	char	*cmd;

	cmd = ft_get_exe(px->paths, px->cmd->cmd[0]);
	if (!cmd)
	{
		ft_error_cmd(px->cmd->cmd[0]);
		if (!px->cmd->n)
		{
			strerror(127);
			ft_master_free(px, ac);
			exit(127);
		}
		return (NULL);
	}
	return (cmd);
}

static void	ft_child(t_pipex *px, int ac, int nb_cmd, char **envp)
{
	char		*cmd;

	cmd = ft_cmd_check(px, ac);
	if (!cmd)
		return ;
	px->pid[nb_cmd] = fork();
	if (!px->pid[nb_cmd])
	{
		if (!nb_cmd)
			ft_fd_dup2(px->input_file, px->pfd[1]);
		else if (!px->cmd->n)
			ft_fd_dup2(px->pfd[2 * (nb_cmd - 1)], px->output_file);
		else
			ft_fd_dup2(px->pfd[2 * (nb_cmd - 1)], px->pfd[2 * nb_cmd + 1]);
		ft_clean_pipes(px, ac);
		execve(cmd, px->cmd->cmd, envp);
	}
	free(cmd);
}

void	ft_fork(t_pipex *px, int ac, char **envp)
{
	int			nb_cmd;
	t_cmdlist	*to_free;

	nb_cmd = -1;
	px->pid = malloc(sizeof(int) * (ac - 3 - px->here_doc));
	if (!px->pid)
		return ;
	while (++nb_cmd < ac - 3 - px->here_doc)
	{
		ft_child(px, ac, nb_cmd, envp);
		to_free = px->cmd;
		px->cmd = px->cmd->n;
		ft_clean_split(to_free->cmd, ft_split_size(to_free->cmd));
		free(to_free);
	}
	ft_master_free(px, ac);
}
