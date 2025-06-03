/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 23:01:50 by jaejo             #+#    #+#             */
/*   Updated: 2024/10/24 00:28:06 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_width(t_setting flag, char *temp)
{
	int	i;

	i = 0;
	if (flag.width <= (int)ft_strlen(temp))
		return (ft_print_str(temp));
	else if (flag.width > (int)ft_strlen(temp) && flag.minus == 0)
	{
		while (flag.width - (int)ft_strlen(temp) - i > 0)
		{
			write (1, " ", 1);
			i++;
		}
		ft_print_str(temp);
		return (flag.width);
	}
	else if (flag.width > (int)ft_strlen(temp) && flag.minus == 1)
	{
		ft_print_str(temp);
		while (flag.width - (int)ft_strlen(temp) - i > 0)
		{
			write (1, " ", 1);
			i++;
		}
	}
	return (flag.width);
}

int	ft_print_s(t_setting flag, va_list ap)
{
	char	*temp;
	int		i;

	i = 0;
	temp = va_arg(ap, char *);
	if (!temp)
		return (ft_null_div(flag));
	if (flag.dot == 0 && flag.width == 0)
		return (ft_print_str(temp));
	else if (flag.dot == 0 && flag.width > 0)
		return (ft_print_width(flag, temp));
	else if (flag.dot == 1 && flag.minus == 0)
		return (ft_str_dot(flag, temp, i));
	else if (flag.dot == 1 && flag.minus == 1)
		return (ft_str_mdot(flag, temp, i));
	return (0);
}
