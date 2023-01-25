/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 22:41:05 by waraissi          #+#    #+#             */
/*   Updated: 2023/01/24 22:57:35 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex.h"

void	exec_cmd_2(t_params *vars, char **envp, char **cmd, int *fd)
{
	int	id;

	id = fork();
	if (id == -1)
		exit(1);
	if (id == 0)
	{
		if (close(fd[1]) == -1 || dup2(fd[0], 0) == -1 || close(fd[0]) == -1
			||dup2(vars->outfile, 1) == -1)
			exit(1);
		execute_cmd(vars, envp, cmd);
	}
	else
	{
		if (close(fd[1]) == -1 || close(fd[0]) == -1)
			exit(1);
	}
}

void	exec_all_cmd(t_params *vars, char **envp, char **cmd1, char **cmd2)
{
	int	fds[2];
	int	id;

	if (pipe(fds) == -1)
		exit(1);
	id = fork();
	if (id == -1)
		exit(1);
	if (id == 0)
	{
		if (close(fds[0]) == -1 || dup2(vars->infile, 0) == -1
			|| dup2(fds[1], 1) == -1 || close(fds[1]) == -1)
			exit(1);
		execute_cmd(vars, envp, cmd1);
	}
	else
		exec_cmd_2(vars, envp, cmd2, fds);
	while (wait(NULL) > 0)
		;
}
