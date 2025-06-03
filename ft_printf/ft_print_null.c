/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_null.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:14:50 by jaejo             #+#    #+#             */
/*   Updated: 2024/10/23 23:41:26 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_width_null(t_setting flag)
{
	int	i;

	i = 0;
	if (flag.width > 6 && flag.minus == 0)
	{
		while (flag.width - 6 - i > 0)
		{
			write (1, " ", 1);
			i++;
		}
		write (1, "(null)", 6);
		return (flag.width);
	}
	else if (flag.width > 6 && flag.minus == 1)
	{
		write (1, "(null)", 6);
		while (flag.width - 6 - i > 0)
		{
			write (1, " ", 1);
			i++;
		}
		return (flag.width);
	}
	return (0);
}

static int	ft_dot_null(t_setting flag)
{
	int	i;

	i = 0;
	if (flag.dot_len < 6 && flag.width == 0)
		return (i);
	else if (flag.dot_len >= 6 && flag.width > 6)
	{
		while (flag.width - 6 - i > 0)
		{
			write (1, " ", 1);
			i++;
		}
		write (1, "(null)", 6);
		return (flag.width);
	}
	else if (flag.dot_len <= 6 && flag.width > 0)
	{
		while (flag.width - i > 0)
		{
			write (1, " ", 1);
			i++;
		}
		return (flag.width);
	}
	return (0);
}

static int	ft_dot_mnull(t_setting flag)
{
	int	i;

	i = 0;
	if (flag.dot_len < 6 && flag.width == 0)
		return (i);
	else if (flag.dot_len >= 6 && flag.width > 6)
	{
		write (1, "(null)", 6);
		while (flag.width - 6 - i > 0)
		{
			write (1, " ", 1);
			i++;
		}
		return (flag.width);
	}
	else if (flag.dot_len <= 6 && flag.width > 0)
	{
		while (flag.width - i > 0)
		{
			write (1, " ", 1);
			i++;
		}
		return (flag.width);
	}
	return (0);
}

int	ft_null_div(t_setting flag)
{
	if ((flag.dot == 0 && flag.width == 0) || \
			(flag.width <= 6 && flag.dot == 0) || \
			(flag.dot_len >= 6 && flag.width <= 6))
	{
		write (1, "(null)", 6);
		return (6);
	}
	else if (flag.dot == 0 && flag.width > 0)
		return (ft_width_null(flag));
	else if (flag.dot == 1 && flag.minus == 0)
		return (ft_dot_null(flag));
	else if (flag.dot == 1 && flag.minus == 1)
		return (ft_dot_mnull(flag));
	return (0);
}
