/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 20:25:32 by jaejo             #+#    #+#             */
/*   Updated: 2024/10/29 14:43:14 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(const char *str)
{
	write(1, str, 1);
	return (1);
}

int	ft_print_address(char *p)
{
	if (p[0] != '(')
	{
		write (1, "0x", 2);
		return (2);
	}
	return (0);
}

int	ft_print_str(const char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		write (1, str++, 1);
		i++;
	}
	return (i);
}

int	ft_print_istr(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		write (1, &str[i], 1);
		i++;
	}
	free(str);
	return (i);
}
