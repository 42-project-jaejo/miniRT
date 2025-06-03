/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 03:34:49 by jaejo             #+#    #+#             */
/*   Updated: 2024/10/22 23:05:57 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_c(t_setting flag, va_list ap)
{
	char	temp;
	int		i;

	i = flag.width - 1;
	temp = va_arg(ap, int);
	if (flag.minus == 1 && flag.width > 1)
	{
		write (1, &temp, 1);
		while (i--)
			write(1, " ", 1);
		return (flag.width);
	}
	while (--i > -1)
	{
		if (flag.minus != 1)
			write (1, " ", 1);
	}
	write(1, &temp, 1);
	if (flag.width == 0)
		return (1);
	return (flag.width);
}
