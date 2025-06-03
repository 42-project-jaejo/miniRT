/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_mdot_div.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 19:41:40 by jaejo             #+#    #+#             */
/*   Updated: 2024/10/28 17:35:45 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_big_dotlen(t_setting flag, char *nbr, int i)
{
	if (flag.dot_len == 0 && nbr[0] == '0')
	{
		while (flag.width - i++ > 0)
			write (1, " ", 1);
		return (flag.width);
	}
	if (flag. width == 0 && (int)ft_strlen(nbr) >= flag.dot_len)
		return (ft_print_istr(nbr));
	while (flag.dot_len - (int)ft_strlen(nbr) - i++ > 0)
		write (1, "0", 1);
	ft_print_istr(nbr);
	return (flag.dot_len);
}

static int	ft_big_width(t_setting flag, char *nbr, int i)
{
	if (flag.dot_len >= (int)ft_strlen(nbr))
	{
		i = flag.dot_len;
		while ((flag.dot_len--) - (int)ft_strlen(nbr) > 0)
			write (1, "0", 1);
		ft_print_istr(nbr);
		while (flag.width - i++ > 0)
			write (1, " ", 1);
		return (flag.width);
	}
	else if (flag.dot_len < (int)ft_strlen(nbr))
	{
		i = (int)ft_strlen(nbr);
		if (nbr[0] != '0')
			ft_print_istr(nbr);
		else
			write (1, " ", 1);
		while (flag.width - i++ > 0)
			write (1, " ", 1);
	}
	return (flag.width);
}

static int	ft_big_nbrlen(t_setting flag, char *nbr, int i)
{
	if (flag.width <= (int)ft_strlen(nbr))
	{
		if (nbr[0] != '0')
			return (ft_print_istr(nbr));
		else
			while (flag.width - i++ > 0)
				write (1, " ", 1);
		return (flag.width);
	}
	else if (flag.width > (int)ft_strlen(nbr))
	{
		i = (int)ft_strlen(nbr);
		if (nbr[0] != '0')
			ft_print_istr(nbr);
		else
			write (1, " ", 1);
		while (flag.width - i++ > 0)
			write (1, " ", 1);
	}
	return (flag.width);
}

int	ft_u_mdot_div(t_setting flag, char *nbr, int i)
{
	if (flag.dot_len <= (int)ft_strlen(nbr) && flag.width > 0)
		return (ft_big_nbrlen(flag, nbr, i));
	else if (flag.dot_len <= flag.width && flag.width > 0)
		return (ft_big_width(flag, nbr, i));
	else
		return (ft_big_dotlen(flag, nbr, i));
}
