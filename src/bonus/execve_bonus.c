/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:59:55 by waraissi          #+#    #+#             */
/*   Updated: 2023/01/24 22:37:39 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex_bonus.h"

char	**sep_first(char *arg)
{
	char	**cmd;

	cmd = malloc(2 * sizeof(char *));
	if (!cmd)
		return (NULL);
	cmd[0] = ft_strdup(arg);
	cmd[1] = NULL;
	return (cmd);
}

char	*get_name(t_heredoc *vars, char **cmd)
{
	char	**paths;
	char	*p;
	int		i;

	i = 0;
	if (*cmd[0] == '.')
		return (ft_strdup(cmd[0]));
	if (ft_strchr(cmd[0], '/'))
		paths = sep_first(cmd[0]);
	else
		paths = join_commands(vars, cmd[0]);
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

void	execute_child(t_heredoc *vars, char **cmd)
{
	char	*file_name;

	if (!cmd[0])
	{
		ft_printf(2, "pipex: : command not found\n");
		exit(1);
	}
	file_name = get_name(vars, cmd);
	if (file_name == NULL)
	{
		ft_printf(2, "pipex: %s: command not found\n", cmd[0]);
		exit(1);
	}
	execve(file_name, cmd, vars->envp);
	ft_printf(2, "pipex: %s: %s\n", cmd[0], strerror(errno));
	free(file_name);
}
