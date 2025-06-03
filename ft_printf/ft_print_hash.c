/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hash.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:42:07 by jaejo             #+#    #+#             */
/*   Updated: 2024/10/29 14:42:52 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_xhash(t_setting flag, char *nbr)
{
	int	i;

	i = 0;
	if (flag.hash == 1 && nbr[0] != '0')
	{
		write (1, "0x", 2);
		i += 2;
	}
	return (i);
}

int	ft_print_uxhash(t_setting flag, char *nbr)
{
	int	i;

	i = 0;
	if (flag.hash == 1 && nbr[0] != '0')
	{
		write (1, "0X", 2);
		i += 2;
	}
	return (i);
}
