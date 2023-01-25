/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:05:23 by waraissi          #+#    #+#             */
/*   Updated: 2023/01/24 20:05:32 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex_bonus.h"

void	check_last_arg(t_heredoc *vars)
{
	vars->outfile = open(vars->l_a, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (vars->outfile == -1)
	{
		ft_printf(2, "Error");
	}
}
