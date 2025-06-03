/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 20:43:31 by jaejo             #+#    #+#             */
/*   Updated: 2024/10/22 23:05:19 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_setting	ft_flag_format(t_setting flag)
{
	flag.specifier = 0;
	flag.minus = 0;
	flag.plus = 0;
	flag.space = 0;
	flag.hash = 0;
	flag.zero = 0;
	flag.dot = 0;
	flag.dot_len = 0;
	flag.width = 0;
	return (flag);
}

int	ft_printf(const char *str, ...)
{
	va_list		ap;
	t_setting	flag;
	int			print_len;

	print_len = 0;
	va_start(ap, str);
	while (*str)
	{
		flag = ft_flag_format(flag);
		if (*str == '%')
		{
			if (*(++str))
				flag = ft_flag_setting(str, flag);
			while (*str && !ft_strchr(SPE, *str))
				str++;
			print_len += ft_check_spe(str, flag, ap);
		}
		else
			print_len += ft_print_char(str);
		if (*str)
			str++;
	}
	va_end(ap);
	return (print_len);
}
