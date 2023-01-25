/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:44:11 by waraissi          #+#    #+#             */
/*   Updated: 2023/01/24 23:45:14 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex_bonus.h"

void	execution_sec(t_heredoc *vars, int *fd, char **cmd1)
{
	int	id;

	id = fork();
	if (id == -1)
		exit(1);
	if (id == 0)
	{
		if (close(fd[1]) == -1 || dup2(fd[0], 0) == -1 || close(fd[0]) == -1
			|| dup2(vars->outfile, 1) == -1)
			exit(1);
		execute_child(vars, cmd1);
	}
	else
	{
		if (close(fd[0]) == -1 || close(fd[1]) == -1)
			exit(1);
	}
}

void	execution(t_heredoc *vars, int tmp, char **cmd, char **cmd1)
{
	int	fd[2];
	int	id;

	if (pipe(fd) == -1)
		exit(1);
	id = fork();
	if (id == -1)
		exit(1);
	if (id == 0)
	{
		if (close(fd[0]) == -1 || dup2(tmp, 0) == -1 || close(tmp) == -1
			|| dup2(fd[1], 1) == -1 || close(fd[1]) == -1)
			exit(1);
		execute_child(vars, cmd);
	}
	else
	{
		if (close(tmp))
			exit(1);
		execution_sec(vars, fd, cmd1);
	}
	while (wait(NULL) > 0)
		;
}

void	execute_heredoc(t_heredoc *vars, char **cmd, char **cmd1)
{
	int		tmp;

	tmp = open(".heredoc.txt", O_RDWR | O_CREAT | O_APPEND, 0644);
	if (!tmp)
		exit(1);
	vars->limiter = ft_strjoin(vars->h_d, "\n");
	here_loop(vars, tmp);
	if (close(tmp) == -1)
		exit(1);
	tmp = open(".heredoc.txt", O_RDONLY);
	if (!tmp)
		exit(1);
	execution(vars, tmp, cmd, cmd1);
	free(vars->limiter);
	unlink(".heredoc.txt");
}

void	initialze(t_heredoc *vars, int ac, char **av, char **envp)
{
	vars->outfile = ac - 1;
	vars->l_a = av[ac - 1];
	vars->h_d = av[2];
	vars->envp = envp;
}

void	here_doc(int ac, char **av, char **envp)
{
	t_heredoc	vars;
	char		**cmd;
	char		**cmd1;
	char		**path;

	initialze(&vars, ac, av, envp);
	check_last_arg(&vars);
	path = get_file_name_bonus(envp);
	if (!path)
		path = check_path(path);
	vars.path = ft_split(path[1], ':');
	cmd = ft_split(av[3], ' ');
	cmd1 = ft_split(av[4], ' ');
	execute_heredoc(&vars, cmd, cmd1);
	free_args(&vars, cmd, cmd1, path);
}
