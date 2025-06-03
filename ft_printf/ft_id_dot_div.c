/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_id_dot_div.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:31:10 by jaejo             #+#    #+#             */
/*   Updated: 2024/10/29 14:16:57 by jaejo            ###   ########.fr       */
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
		while (flag.width - (int)ft_strlen(nbr) - i++ > 0)
			write (1, " ", 1);
		if (nbr[0] == '0')
		{
			free(nbr);
			write (1, " ", 1);
			return (i);
		}
		return (ft_print_istr(nbr) + i - 1);
	}
	return (0);
}

static int	ft_big_width(t_setting flag, char *nbr, int i)
{
	if (flag.dot_len >= (int)ft_strlen(nbr))
	{
		while (flag.width - flag.dot_len - (i++) - 1 > 0)
			write (1, " ", 1);
		if (!(ft_plus_check(flag)) && flag.dot_len != flag.width)
			write (1, " ", 1);
		while ((flag.dot_len--) - (int)ft_strlen(nbr) > 0)
			write (1, "0", 1);
		ft_print_istr(nbr);
		return (flag.width);
	}
	else if (flag.dot_len < (int)ft_strlen(nbr))
	{
		while (flag.width - (int)ft_strlen(nbr) - i - 1 > 0)
		{
			write (1, " ", 1);
			i++;
		}
		if (!(ft_plus_check(flag)) && flag.dot_len)
			write (1, " ", 1);
		ft_print_istr(nbr);
	}
	return (flag.width);
}

static int	ft_zero_width(t_setting flag, char *nbr, int i)
{
	i = (int)ft_strlen(nbr);
	if (flag.plus == 1)
	{
		write (1, "+", 1);
		i++;
	}
	if (nbr[0] == '0' && flag.dot_len < 1)
	{
		free(nbr);
		return (flag.dot_len + flag.plus);
	}
	if (flag.dot_len <= i)
		return (ft_print_istr(nbr) + flag.plus);
	else if (flag.dot_len > i)
	{
		while (flag.dot_len - i > 0)
		{
			write (1, "0", 1);
			i++;
		}
		ft_print_istr(nbr);
	}
	return (flag.dot_len);
}

int	ft_id_dot_div(t_setting flag, char *nbr, int i)
{
	if (flag.dot_len <= (int)ft_strlen(nbr) && flag.width > 0)
		return (ft_big_nbrlen(flag, nbr, i));
	else if (flag.dot_len <= flag.width && flag.width > 0)
		return (ft_big_width(flag, nbr, i));
	else
		return (ft_zero_width(flag, nbr, i));
	return (0);
}
