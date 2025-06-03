/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ux_mdot_div.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:39:08 by jaejo             #+#    #+#             */
/*   Updated: 2024/10/29 14:47:25 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_big_width(t_setting flag, char *nbr, int i)
{
	if (flag.dot_len > (int)ft_strlen(nbr))
	{
		i = flag.dot_len;
		i += ft_print_uxhash(flag, nbr);
		while ((flag.dot_len--) - (int)ft_strlen(nbr) > 0)
			write (1, "0", 1);
		ft_print_istr(nbr);
		while (flag.width - i++ > 0)
			write (1, " ", 1);
		return (flag.width);
	}
	else if (flag.width >= (int)ft_strlen(nbr))
	{
		if (flag.hash == 1)
			i += 2;
		while (flag.width - (int)ft_strlen(nbr) - i++ > 0)
			write (1, " ", 1);
		ft_print_uxhash(flag, nbr);
		ft_print_istr(nbr);
	}
	return (flag.width);
}

static int	ft_big_nbrlen(t_setting flag, char *nbr, int i)
{
	if (flag.width <= (int)ft_strlen(nbr))
	{
		i += ft_print_uxhash(flag, nbr);
		return (ft_print_istr(nbr) + i);
	}
	else
	{
		i = (int)ft_strlen(nbr);
		i += ft_print_uxhash(flag, nbr);
		ft_print_istr(nbr);
		while (flag.width - i++ > 0)
			write (1, " ", 1);
		return (flag.width);
	}
}

static int	ft_else_dotlen(t_setting flag, char *nbr, int i)
{
	if (flag.dot_len > (int)ft_strlen(nbr))
	{
		ft_print_uxhash(flag, nbr);
		while (flag.dot_len - (int)ft_strlen(nbr) - i++ > 0)
			write (1, "0", 1);
		i = 0;
		if (flag.hash == 1 && nbr[0] != '0')
			i = 2;
		ft_print_istr(nbr);
		return (flag.dot_len + i);
	}
	else if (flag.width > (int)ft_strlen(nbr))
	{
		i += ft_print_xhash(flag, nbr);
		i += ft_print_istr(nbr);
		while (flag.width - i++ > 0)
			write (1, " ", 1);
		return (flag.width);
	}
	else
		i += ft_print_uxhash(flag, nbr);
	return (ft_print_istr(nbr) + i);
}

static int	ft_big_dotlen(t_setting flag, char *nbr, int i)
{
	if (nbr[0] == '0' && flag.dot_len == 0)
	{
		while (flag.width - i++ > 0)
			write (1, " ", 1);
		return (flag.width);
	}
	else
		return (ft_else_dotlen(flag, nbr, i));
}

int	ft_ux_mdot_div(t_setting flag, char *nbr, int i)
{
	if (flag.dot_len <= (int)ft_strlen(nbr) && flag.width > 0 && \
			flag.dot_len > 0)
		return (ft_big_nbrlen(flag, nbr, i));
	else if (flag.dot_len <= flag.width && flag.width > 0 && flag.dot_len > 0)
		return (ft_big_width(flag, nbr, i));
	else
		return (ft_big_dotlen(flag, nbr, i));
}
