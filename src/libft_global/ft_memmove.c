/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 20:26:23 by waraissi          #+#    #+#             */
/*   Updated: 2023/01/06 14:57:53 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (src == dest || n == 0)
		return (dest);
	if (src >= dest)
	{
		ft_memcpy(dest, src, n);
	}
	else
	{
		n += 1;
		while (--n)
		{
			((unsigned char *)dest)[n - 1] = ((unsigned char *)src)[n - 1];
		}
	}
	return (dest);
}
