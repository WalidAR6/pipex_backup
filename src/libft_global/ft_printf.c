/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:43:25 by waraissi          #+#    #+#             */
/*   Updated: 2023/01/06 14:58:01 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	conditions(int fd, const char *str, int *res, va_list	args)
{
	if (*str == 'c')
		ft_putchar (fd, va_arg(args, int), res);
	else if (*str == 'd' || *str == 'i')
		ft_putnbr (fd, va_arg(args, int), res);
	else if (*str == 's')
		ft_putstr (fd, va_arg(args, char *), res);
	else if (*str == 'p')
	{
		ft_putstr(fd, "0x", res);
		ft_putnbr_base(fd, va_arg(args, unsigned long long), res);
	}
	else if (*str == 'u')
		ft_putnbr_unsigned (fd, va_arg(args, unsigned int), res);
	else if (*str == 'x')
		ft_putnbr_base_lower (fd, va_arg(args, unsigned int), res);
	else if (*str == 'X')
		ft_putnbr_base_upper (fd, va_arg(args, unsigned int), res);
	else if (*str == '%')
		ft_putchar(fd, '%', res);
	else
		ft_putchar(fd, *str, res);
}

int	ft_printf(int fd, const char *str, ...)
{
	va_list	args;
	int		res;

	res = 0;
	if (write(fd, "", 0) == -1)
		return (-1);
	va_start (args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (!*str)
			{
				write(1, "", 1);
			}
			else
				conditions(fd, str++, &res, args);
		}
		else
			ft_putchar (fd, *str++, &res);
	}
	va_end (args);
	return (res);
}
