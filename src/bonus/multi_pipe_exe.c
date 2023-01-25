/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_pipe_exe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:02:24 by waraissi          #+#    #+#             */
/*   Updated: 2023/01/24 22:38:59 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex_bonus.h"

char	**join_commands_multi(t_vars *vars, char *arg)
{
	int		i;
	char	**cmd;

	i = 0;
	cmd = malloc((get_paths_len(vars->path) + 1) * sizeof(*cmd));
	if (!cmd)
		return (NULL);
	while (vars->path[i])
	{
		cmd[i] = ft_strjoin_sep(vars->path[i], arg, "/");
		i++;
	}
	cmd[i] = NULL;
	return (cmd);
}

char	*get_name_multi(t_vars *vars, char **cmd)
{
	char	**paths;
	int		i;
	char	*p;

	i = 0;
	if (*cmd[0] == '.')
		return (ft_strdup(cmd[0]));
	if (ft_strchr(cmd[0], '/'))
		paths = sep_first(cmd[0]);
	else
		paths = join_commands_multi(vars, cmd[0]);
	while (paths[i])
	{
		if (!access(paths[i], F_OK))
			break ;
		i++;
	}
	if (paths[i] == NULL)
		return (ft_free(paths), NULL);
	p = ft_strdup(paths[i]);
	return (ft_free(paths), p);
}

void	execute_first_cmd(t_vars *vars, char **envp, char **cmd)
{
	char	*file_name;

	if (!cmd[0])
	{
		ft_printf(2, "pipex: : command not found\n");
		exit(1);
	}	
	file_name = get_name_multi(vars, cmd);
	if (file_name == NULL)
	{
		ft_printf(2, "pipex: %s: command not found\n", cmd[0]);
		exit(1);
	}
	execve(file_name, cmd, envp);
	ft_printf(2, "pipex: %s: %s\n", cmd[0], strerror(errno));
	free(file_name);
	exit(1);
}
