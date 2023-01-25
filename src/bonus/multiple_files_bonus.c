/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_files_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:31:19 by waraissi          #+#    #+#             */
/*   Updated: 2023/01/24 23:45:39 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex_bonus.h"

void	helper(t_vars *vars, int ac, char **av, char **envp)
{
	vars->ac = ac;
	vars->av = av;
	vars->envp = envp;
	vars->f_a = av[1];
	vars->l_a = av[ac - 1];
	check_first(vars);
	check_last(vars);
}

void	close_fds(int fd0, int fd1, int n)
{
	if (n == 1)
	{
		if (close(fd1) == -1 || close(fd0) == -1)
			exit(1);
	}
	else if (n == 2)
	{
		if (close(fd1) == -1)
			exit(1);
	}
}

void	execute_multi_pipe(t_vars *vars, int i)
{
	int	id;

	if (pipe(vars->fd) == -1)
		exit(1);
	id = fork();
	if (id == -1)
		exit(1);
	if (id == 0)
	{
		if (dup2(vars->res, 0) == -1 || dup2(vars->fd[1], 1) == -1)
			exit(1);
		close_fds(vars->fd[0], vars->fd[1], 1);
		if (i == vars->ac - 2)
			if (dup2(vars->outfile, 1) == -1)
				exit(1);
		execute_first_cmd(vars, vars->envp, ft_split(vars->av[i], ' '));
	}
	else
	{
		close(vars->res);
		vars->res = dup(vars->fd[0]);
		close_fds(vars->fd[0], vars->fd[1], 1);
	}
}

char	**check_path(char	**p)
{
	p = malloc(3 * sizeof(char *));
	if (!p)
		return (NULL);
	p[0] = ft_strdup("");
	p[1] = ft_strdup("");
	p[2] = NULL;
	return (p);
}

void	multiple_pipes(int ac, char **av, char **envp, int i)
{
	t_vars	vars;
	char	**path;

	path = get_file_name_bonus(envp);
	if (!path)
		path = check_path(path);
	vars.path = ft_split(path[1], ':');
	helper(&vars, ac, av, envp);
	vars.res = vars.infile;
	while (i < ac - 1)
	{
		execute_multi_pipe(&vars, i);
		i++;
	}
	while (wait(NULL) > 0)
		;
	close(vars.res);
	close(vars.infile);
	close(vars.outfile);
	ft_free(path);
	ft_free(vars.path);
}
