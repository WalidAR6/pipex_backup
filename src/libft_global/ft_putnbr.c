/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:42:06 by waraissi          #+#    #+#             */
/*   Updated: 2023/01/06 14:58:35 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	ft_putnbr(int fd, int n, int *res)
{
	if (n == -2147483648)
		ft_putstr(fd, "-2147483648", res);
	else if (n < 0)
	{
		n = -n;
		ft_putchar(fd, '-', res);
		ft_putnbr(fd, n, res);
	}
	else
	{
		if (n < 10)
			ft_putchar(fd, n + 48, res);
		else
		{
			ft_putnbr(fd, n / 10, res);
			ft_putnbr(fd, n % 10, res);
		}
	}
}
