/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_id_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:02:23 by jaejo             #+#    #+#             */
/*   Updated: 2024/10/26 22:33:24 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_plus_check(t_setting flag, char *nbr)
{
	int	i;

	i = 0;
	if (flag.plus == 1 && flag.zero == 0 && nbr[0] != '-')
	{
		write (1, "+", 1);
		i++;
	}
	return (i);
}

static void	ft_print_zero(t_setting flag, char *nbr, int i)
{
	if (nbr[0] == '-' && flag.zero == 1)
		write (1, "-", 1);
	if (flag.plus == 1 && nbr[0] != '-')
		write (1, "+", 1);
	while (flag.width - i > 0 && flag.zero == 1)
	{
		write (1, "0", 1);
		i++;
	}
}

int	ft_id_width(t_setting flag, char *nbr, int i)
{
	i = (int)strlen(nbr);
	if (flag.width > i && flag.minus == 0)
	{
		ft_print_zero(flag, nbr, i);
		while (flag.width - i++ - 1 > 0 && flag.zero == 0)
			write (1, " ", 1);
		if (!(ft_plus_check(flag, nbr)) && flag.zero == 0)
			write (1, " ", 1);
		if (nbr[0] == '-' && flag.zero == 0)
			write (1, "-", 1);
		ft_print_istr(nbr);
		return (flag.width);
	}
	else if (flag.width > i && flag.minus == 1)
	{
		i += ft_plus_check(flag, nbr);
		if (nbr[0] == '-')
			write (1, "-", 1);
		ft_print_istr(nbr);
		while (flag.width - i++ > 0)
			write (1, " ", 1);
	}
	return (flag.width);
}
