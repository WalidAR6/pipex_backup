/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_lower.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:42:57 by waraissi          #+#    #+#             */
/*   Updated: 2023/01/06 14:58:19 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	ft_putnbr_base_lower(int fd, unsigned int nbr, int *res)
{
	char	*base;

	base = "0123456789abcdef";
	if (nbr < 16)
		ft_putchar(fd, base[nbr], res);
	else
	{
		ft_putnbr_base_lower(fd, nbr / 16, res);
		ft_putnbr_base_lower(fd, nbr % 16, res);
	}
}
