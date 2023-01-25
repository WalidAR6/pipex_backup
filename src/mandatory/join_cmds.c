/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 01:24:28 by waraissi          #+#    #+#             */
/*   Updated: 2023/01/21 00:01:46 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex.h"

int	get_paths_len(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	**join_commands(t_params *vars, char *arg)
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
