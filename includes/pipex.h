/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehubert <jehubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:03:21 by jehubert          #+#    #+#             */
/*   Updated: 2023/03/02 22:32:31 by jehubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/includes/libft.h"
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <errno.h>

typedef struct s_pipex		t_pipex;
typedef struct s_cmdlist	t_cmdlist;

struct s_cmdlist
{
	char				**cmd;
	int					size;
	struct s_cmdlist	*n;
};

struct s_pipex
{
	int			here_doc;
	int			input_file;
	int			output_file;
	int			*pfd;
	int			*pid;
	char		*limiter;
	char		**paths;
	t_cmdlist	*cmd;
};

/* cmdlist */

t_cmdlist	*ft_newcmd(char **cmd);
void		ft_cmdaddback(t_cmdlist **cmds, t_cmdlist *new);
int			ft_split_size(char **spl);

/* Get */

void		ft_get_files(t_pipex *px, char **av, int ac);
void		ft_get_path(t_pipex *px, char **envp);
void		ft_get_cmd(t_pipex *px, char **av, int ac);
char		*ft_get_exe(char **path, char *cmd);
void		ft_get_pipe(t_pipex *px, int ac);

/* Childs */

void		ft_fork(t_pipex *px, int ac, char **envp);

/* Utils */

void		ft_clean_pipes(t_pipex *px, int ac);
void		ft_fd_dup2(int a, int b);
void		ft_clean_split(char **split, int size);
void		ft_master_free(t_pipex *px, int ac);
void		ft_remove_quote(char *cmd);

/* Error */

void		ft_error_cmd(char *cmd);
void		ft_bad_args(void);
void		ft_wait(int nb_cmd);

/* Here_doc */

int			ft_heredoc(char **av);

/* Main */

void		ft_pipex(int ac, char **av, char **envp);

/* Parsing */

t_cmdlist	*ft_cmd_split(t_pipex *px, char **av, int ac);
char		*ft_new_strjoin(char *s1, char *s2);

#endif