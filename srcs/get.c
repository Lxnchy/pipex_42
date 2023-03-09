/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehubert <jehubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:55:30 by jehubert          #+#    #+#             */
/*   Updated: 2023/03/08 12:17:13 by jehubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_get_files(t_pipex *px, char **av, int ac)
{
	if (!ft_strncmp("here_doc", av[1], ft_strlen(av[1])))
	{
		px->here_doc = 1;
		px->input_file = ft_heredoc(av);
		px->output_file = open(av[ac - 1], O_CREAT | O_APPEND | O_RDWR, 000644);
	}
	else
	{
		px->here_doc = 0;
		px->input_file = open(av[1], O_RDONLY);
		px->output_file = open(av[ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0000644);
	}
	if (px->input_file < 0)
	{
		perror(av[1]);
		exit(1);
	}
	if (px->output_file < 0)
	{
		perror(av[ac - 1]);
		exit(errno);
	}
}

void	ft_get_path(t_pipex *px, char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	px->paths = ft_split(*envp + 5, ':');
}

char	*ft_get_exe(char **path, char *cmd)
{
	char	*temp;
	char	*res;

	if (!access(cmd, F_OK))
		return (ft_strdup(cmd));
	while (*path)
	{
		temp = ft_strjoin(*path, "/");
		res = ft_strjoin(temp, cmd);
		free(temp);
		if (!access(res, F_OK))
			return (res);
		free(res);
		path++;
	}
	return (NULL);
}

void	ft_get_pipe(t_pipex *px, int ac)
{
	int	i;

	i = -1;
	px->pfd = malloc(sizeof(int) * (ac - 4) * 2);
	if (!px->pfd)
		return ;
	while (++i < (ac - 4))
	{
		if (pipe(px->pfd + (2 * i)) < 0)
		{
			perror("Pipe");
			exit(errno);
		}
	}
}
