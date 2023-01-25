/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 01:50:26 by waraissi          #+#    #+#             */
/*   Updated: 2023/01/23 01:52:37 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex_bonus.h"

void	here_loop(t_heredoc *vars, int tmp)
{
	while (1)
	{
		if (write(1, "> ", 2) == -1)
			exit(1);
		vars->line = get_next_line(0);
		if (vars->line == NULL || ft_strcmp(vars->line, vars->limiter) == 0)
		{
			free(vars->line);
			break ;
		}
		if (write(tmp, vars->line, ft_strlen(vars->line)) == -1)
			exit(1);
		free(vars->line);
	}
}
