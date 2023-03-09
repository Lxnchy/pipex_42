/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehubert <jehubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:21:46 by jehubert          #+#    #+#             */
/*   Updated: 2023/03/01 17:03:41 by jehubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_error_cmd(char *cmd)
{
	ft_putstr_fd("zsh: command not found:", 2);
	ft_putstr_fd(cmd, 2);
	write(2, "\n", 1);
}

void	ft_bad_args(void)
{
	ft_putstr_fd("./pipex: Invalid number of arguments\n", 2);
	exit(1);
}

void	ft_wait(int nb_cmd)
{
	int	status;

	while (nb_cmd--)
	{
		waitpid(0, &status, 0);
		if (WIFEXITED(status))
			if (WEXITSTATUS(status))
				exit(WEXITSTATUS(status));
	}
}
