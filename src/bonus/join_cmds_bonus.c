/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_cmds_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:04:18 by waraissi          #+#    #+#             */
/*   Updated: 2023/01/21 01:14:54 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex_bonus.h"

int	get_paths_len(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	**join_commands(t_heredoc *vars, char *arg)
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
