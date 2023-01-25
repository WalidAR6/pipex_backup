/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_last.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 23:38:23 by waraissi          #+#    #+#             */
/*   Updated: 2023/01/23 16:29:51 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex_bonus.h"

void	check_first(t_vars *vars)
{
	vars->infile = open(vars->f_a, O_RDONLY);
	if (vars->infile == -1)
	{
		ft_printf(2, "%s: No such file or directory\n", vars->f_a);
	}
}

void	check_last(t_vars *vars)
{
	vars->outfile = open(vars->l_a, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (vars->outfile == -1)
	{
		ft_printf(2, "Error");
	}
}
