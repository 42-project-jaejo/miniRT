/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_dot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 21:38:53 by jaejo             #+#    #+#             */
/*   Updated: 2024/10/28 23:16:26 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_big_width(t_setting flag, char *temp, int i)
{
	if (flag.dot_len >= (int)ft_strlen(temp))
	{
		while (flag.width - (int)ft_strlen(temp) - i > 0)
		{
			write (1, " ", 1);
			i++;
		}
		ft_print_str(temp);
		return (flag.width);
	}
	else if (flag.dot_len < (int)ft_strlen(temp))
	{
		while (flag.width - flag.dot_len - i > 0)
		{
			write (1, " ", 1);
			i++;
		}
		while (flag.dot_len-- > 0)
			write (1, temp++, 1);
		return (flag.width);
	}
	return (0);
}

static int	ft_big_strlen(t_setting flag, char *temp, int i)
{
	if (flag.dot_len >= flag.width)
	{
		while (flag.dot_len - i > 0)
		{
			write (1, temp++, 1);
			i++;
		}
		return (flag.dot_len);
	}
	else if (flag.dot_len < flag.width)
	{
		while (flag.width - flag.dot_len - i > 0)
		{
			write (1, " ", 1);
			i++;
		}
		while (flag.dot_len-- > 0)
			write (1, temp++, 1);
		return (flag.width);
	}
	return (0);
}

static int	ft_zero_width(t_setting flag, char *temp, int i)
{
	if (flag.dot_len >= (int)ft_strlen(temp))
	{
		while (flag.width - (int)ft_strlen(temp) - i++ > 0)
			write (1, " ", 1);
		i += ft_print_str(temp);
		return (i - 1);
	}
	else if (flag.dot_len < (int)ft_strlen(temp))
	{
		while (flag.dot_len - i > 0)
		{
			write (1, temp++, 1);
			i++;
		}
		return (flag.dot_len);
	}
	return (0);
}

int	ft_str_dot(t_setting flag, char *temp, int i)
{
	if (flag.dot_len <= (int)ft_strlen(temp) && flag.width > 0)
		return (ft_big_strlen(flag, temp, i));
	else if (flag.dot_len <= flag.width && flag.width > 0)
		return (ft_big_width(flag, temp, i));
	else
		return (ft_zero_width(flag, temp, i));
	return (0);
}
