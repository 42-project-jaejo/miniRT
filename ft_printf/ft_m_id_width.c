/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_m_id_width.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:02:23 by jaejo             #+#    #+#             */
/*   Updated: 2024/10/24 20:45:33 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_m_id_width(t_setting flag, char *nbr, int i)
{
	if (flag.width > (int)ft_strlen(nbr) && flag.minus == 0)
	{
		while (flag.width - (int)ft_strlen(nbr) - i > 0)
		{
			write (1, " ", 1);
			i++;
		}
		ft_print_istr(nbr);
		return (flag.width);
	}
	else if (flag.width > (int)ft_strlen(nbr) && flag.minus == 1)
	{
		ft_print_istr(nbr);
		while (flag.width - (int)ft_strlen(nbr) - i > 0)
		{
			write (1, " ", 1);
			i++;
		}
	}
	return (flag.width);
}
