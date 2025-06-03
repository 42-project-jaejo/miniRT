/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mid_mdot_div.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:31:10 by jaejo             #+#    #+#             */
/*   Updated: 2024/10/29 14:30:24 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_big_nbrlen(t_setting flag, char *nbr, int i)
{
	write(1, "-", 1);
	if ((int)ft_strlen(nbr) >= flag.width)
		return (ft_print_istr(nbr));
	else if ((int)ft_strlen(nbr) < flag.width)
	{
		i = (int)ft_strlen(nbr);
		ft_print_istr(nbr);
		while (flag.width - i++ > 0)
			write (1, " ", 1);
	}
	return (flag.width);
}

static int	ft_big_width(t_setting flag, char *nbr, int i)
{
	if (flag.dot_len >= (int)ft_strlen(nbr) - 1)
	{
		write (1, &nbr[0], 1);
		while (flag.dot_len - (int)ft_strlen(nbr) - i++ + 1 > 0)
			write (1, "0", 1);
		ft_print_istr(nbr);
		i = 0;
		while (flag.width - flag.dot_len - i++ - 1 > 0)
			write (1, " ", 1);
		if (flag.width == flag.dot_len)
			flag.width++;
		return (flag.width);
	}
	else if (flag.dot_len < (int)ft_strlen(nbr) - 1)
	{
		i = (int)ft_strlen(nbr);
		write (1, "-", 1);
		ft_print_istr(nbr);
		while (flag.width - i++ > 0)
			write (1, " ", 1);
	}
	return (flag.width);
}

static int	ft_zero_width(t_setting flag, char *nbr, int i)
{
	if (flag.dot_len <= (int)ft_strlen(nbr) - 1)
	{
		write (1, "-", 1);
		return (ft_print_istr(nbr));
	}
	else if (flag.dot_len > (int)ft_strlen(nbr) - 1)
	{
		write (1, "-", 1);
		while (flag.dot_len - (int)ft_strlen(nbr) - i + 1 > 0)
		{
			write (1, "0", 1);
			i++;
		}
		ft_print_istr(nbr);
		return (flag.dot_len + 1);
	}
	return (0);
}

int	ft_mid_mdot_div(t_setting flag, char *nbr, int i)
{
	if (flag.dot_len <= (int)ft_strlen(nbr) - 1 && flag.width > 0)
		return (ft_big_nbrlen(flag, nbr, i));
	else if (flag.dot_len <= flag.width && flag.width > 0)
		return (ft_big_width(flag, nbr, i));
	else
		return (ft_zero_width(flag, nbr, i));
	return (0);
}
