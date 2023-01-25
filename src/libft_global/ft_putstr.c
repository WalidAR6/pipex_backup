/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:41:53 by waraissi          #+#    #+#             */
/*   Updated: 2023/01/06 14:58:41 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	ft_putstr(int fd, char *s, int *res)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(fd, "(null)", 6);
		*res += 6;
	}
	else
	{
		while (s[i])
		{
			ft_putchar(fd, s[i], res);
			i++;
		}
	}
}
