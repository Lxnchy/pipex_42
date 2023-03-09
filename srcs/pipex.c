/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehubert <jehubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:03:31 by jehubert          #+#    #+#             */
/*   Updated: 2023/03/02 22:36:10 by jehubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*ft_new_strjoin(char *s1, char *s2)
{
	char	*res;

	res = malloc(gnl_strlen(s1) + gnl_strlen(s2) + 1);
	if (!res)
	{
		free(s1);
		free(s2);
		return (NULL);
	}
	res[0] = '\0';
	gnl_strlcat(res, s1, gnl_strlen(s1) + 1);
	gnl_strlcat(&res[gnl_strlen(s1)], s2, gnl_strlen(s2) + 1);
	if (s2[0] != ' ')
		free(s2);
	return (free(s1), res);
}

void	ft_pipex(int ac, char **av, char **envp)
{
	t_pipex	px;

	if (ac != 5)
		ft_bad_args();
	ft_get_files(&px, av, ac);
	ft_get_path(&px, envp);
	px.cmd = ft_cmd_split(&px, av, ac);
	ft_get_pipe(&px, ac);
	ft_fork(&px, ac, envp);
	if (px.here_doc)
		unlink(".tmp_hd");
	ft_wait(ac - 3 - px.here_doc);
}

int	main(int ac, char **av, char **envp)
{
	ft_pipex(ac, av, envp);
	return (0);
}
