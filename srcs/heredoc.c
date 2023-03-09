/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehubert <jehubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:26:17 by jehubert          #+#    #+#             */
/*   Updated: 2023/03/09 16:59:27 by jehubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	ft_get_stdin(char *lim, int fd)
{
	char	*tmp;

	while (1)
	{
		ft_putstr_fd("heredoc>", 1);
		tmp = get_next_line(0, lim);
		if (!tmp)
			break ;
		if (!ft_strncmp(lim, tmp, ft_strlen(lim) + 1))
			break ;
		ft_putstr_fd(tmp, fd);
		free(tmp);
	}
	if (tmp)
		free(tmp);
}

int	ft_heredoc(char **av)
{
	int		fd;
	char	*lim;

	fd = open(".tmp_hd", O_CREAT | O_WRONLY | O_TRUNC, 0000644);
	if (fd < 0)
	{
		perror(".tmp_hd");
		exit(errno);
	}
	lim = av[2];
	ft_get_stdin(lim, fd);
	close(fd);
	fd = open(".tmp_hd", O_RDONLY, 0000644);
	if (fd < 0)
	{
		perror(".tmp_hd");
		unlink(".tmp_hd");
		exit(errno);
	}
	return (fd);
}
