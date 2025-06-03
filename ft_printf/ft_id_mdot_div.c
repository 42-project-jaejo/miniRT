/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_id_mdot_div.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:31:10 by jaejo             #+#    #+#             */
/*   Updated: 2024/10/26 22:36:01 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_plus_check(t_setting flag)
{
	int	i;

	i = 0;
	if (flag.plus == 1)
	{
		write (1, "+", 1);
		i++;
	}
	return (i);
}

static int	ft_big_nbrlen(t_setting flag, char *nbr, int i)
{
	if (flag.plus == 1)
	{
		write (1, "+", 1);
		i++;
	}
	if ((int)ft_strlen(nbr) >= flag.width)
		return (ft_print_istr(nbr) + i);
	else if ((int)ft_strlen(nbr) < flag.width)
	{
		if (nbr[0] == '0')
		{
			while (flag.width - (int)ft_strlen(nbr) - i++ > 0)
				write (1, " ", 1);
			free(nbr);
			write (1, " ", 1);
			return (i);
		}
		i = (int)ft_strlen(nbr);
		ft_print_istr(nbr);
		while (flag.width - i++ > 0)
			write (1, " ", 1);
	}
	return (flag.width);
}

static int	ft_zero_width(t_setting flag, char *nbr, int i)
{
	if (flag.plus == 1)
	{
		write (1, "+", 1);
		i++;
	}
	if (flag.dot_len <= (int)ft_strlen(nbr))
		return (ft_print_istr(nbr));
	else if (flag.dot_len > (int)ft_strlen(nbr))
	{
		while (flag.dot_len - (int)ft_strlen(nbr) - i > 0)
		{
			write (1, "0", 1);
			i++;
		}
		ft_print_istr(nbr);
	}
	return (flag.dot_len);
}

static int	ft_big_width(t_setting flag, char *nbr, int i)
{
	if (flag.dot_len >= (int)ft_strlen(nbr))
	{
		ft_plus_check(flag);
		while (flag.dot_len - (int)ft_strlen(nbr) - i++ > 0)
			write (1, "0", 1);
		ft_print_istr(nbr);
		i = 0;
		while (flag.width - flag.dot_len - (i++) > 0)
			write (1, " ", 1);
		return (flag.width);
	}
	else if (flag.dot_len < (int)ft_strlen(nbr))
	{
		i = (int)ft_strlen(nbr);
		if (!(ft_plus_check(flag)))
			write (1, " ", 1);
		ft_print_istr(nbr);
		while (flag.width - i - 1 > 0)
		{
			write (1, " ", 1);
			i++;
		}
	}
	return (flag.width);
}

int	ft_id_mdot_div(t_setting flag, char *nbr, int i)
{
	if (flag.dot_len <= (int)ft_strlen(nbr) && flag.width > 0)
		return (ft_big_nbrlen(flag, nbr, i));
	else if (flag.dot_len <= flag.width && flag.width > 0)
		return (ft_big_width(flag, nbr, i));
	else
		return (ft_zero_width(flag, nbr, i));
	return (0);
}
