/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 20:29:36 by waraissi          #+#    #+#             */
/*   Updated: 2023/01/24 23:44:48 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex_bonus.h"

void	ft_free(char **p)
{
	int	i;

	i = 0;
	while (p[i])
	{
		free(p[i]);
		i++;
	}
	free(p);
}

void	free_args(t_heredoc *vars, char **cmd1, char **cmd2, char **path)
{
	ft_free(cmd1);
	ft_free(cmd2);
	ft_free(path);
	ft_free(vars->path);
}

int	main(int ac, char **av, char **envp)
{
	if (ac == 6 && !ft_strncmp(av[1], "here_doc", sizeof(av[1])))
		here_doc(ac, av, envp);
	else if (ac > 1 && ft_strncmp(av[1], "here_doc", sizeof(av[1])))
		multiple_pipes(ac, av, envp, 2);
	else
		return (ft_printf(2, "Error check your args"), 1);
	return (0);
}
