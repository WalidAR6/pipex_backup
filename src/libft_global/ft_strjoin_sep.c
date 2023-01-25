/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_sep.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 22:39:16 by waraissi          #+#    #+#             */
/*   Updated: 2023/01/21 23:55:01 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_strjoin_sep(char *s1, char *s2, char *sep)
{
	size_t	i;
	size_t	j;
	size_t	x;
	char	*p;

	i = -1;
	j = -1;
	x = -1;
	p = malloc(ft_strlen(s1) + ft_strlen(s2) + ft_strlen(sep) + 1);
	if (!p)
		return (NULL);
	while (s1[++i])
		p[i] = s1[i];
	while (sep[++x])
		p[x + i] = sep[x];
	while (s2[++j])
		p[i + x + j] = s2[j];
	p[i + x + j] = 0;
	return (p);
}
