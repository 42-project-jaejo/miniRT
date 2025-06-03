/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_X.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 23:10:51 by jaejo             #+#    #+#             */
/*   Updated: 2024/10/28 20:01:36 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	len(unsigned int temp)
{
	int	i;

	i = 0;
	if (temp == 0)
		return (1);
	while (temp > 0)
	{
		temp = temp / 16;
		i++;
	}
	return (i);
}

static char	*ft_hexnbr(unsigned int temp)
{
	char			*nbr;
	int				i;
	unsigned int	j;

	i = len(temp);
	nbr = (char *)malloc (sizeof(char) * i + 1);
	if (nbr == 0)
		return (NULL);
	nbr[i] = '\0';
	if (temp == 0)
		nbr[0] = '0';
	while (temp != 0)
	{
		i--;
		j = temp % 16;
		if (j < 10)
			nbr[i] = 48 + j;
		else
			nbr[i] = 65 + (j - 10);
		temp = temp / 16;
	}
	return (nbr);
}

static int	ft_onlyflag_hex(t_setting flag, char *nbr, int i)
{
	if (flag.width > (int)ft_strlen(nbr) && flag.minus == 0)
	{
		if (flag.hash == 1)
			i += 2;
		while (flag.width - (int)ft_strlen(nbr) - i++ > 0)
			write (1, " ", 1);
		ft_print_uxhash(flag, nbr);
		ft_print_istr(nbr);
		return (flag.width);
	}
	else if (flag.width > (int)ft_strlen(nbr) && flag.minus == 1)
	{
		i = (int)ft_strlen(nbr);
		i += ft_print_uxhash(flag, nbr);
		ft_print_istr(nbr);
		while (flag.width - i++ > 0)
			write (1, " ", 1);
		return (flag.width);
	}
	else
		i += ft_print_uxhash(flag, nbr);
	return (ft_print_istr(nbr) + i);
}

static int	ft_zeroflag_hex(t_setting flag, char *nbr, int i)
{
	if (flag.width > (int)ft_strlen(nbr) && flag.minus == 0)
	{
		i += ft_print_uxhash(flag, nbr);
		while (flag.width - (int)ft_strlen(nbr) - i++ > 0)
			write (1, "0", 1);
		ft_print_istr(nbr);
		return (flag.width);
	}
	else if (flag.width > (int)ft_strlen(nbr) && flag.minus == 1)
	{
		i = (int)ft_strlen(nbr);
		i += ft_print_uxhash(flag, nbr);
		ft_print_istr(nbr);
		while (flag.width - i++ > 0)
			write (1, " ", 1);
		return (flag.width);
	}
	else
		i += ft_print_uxhash(flag, nbr);
	return (ft_print_istr(nbr) + i);
}

int	ft_print_ux(t_setting flag, va_list ap)
{
	char			*nbr;
	unsigned int	temp;
	int				i;

	i = 0;
	temp = va_arg(ap, unsigned int);
	nbr = ft_hexnbr(temp);
	if (flag.dot == 0 && flag.zero == 0)
		return (ft_onlyflag_hex(flag, nbr, i));
	else if (flag.dot == 0 && flag.zero == 1)
		return (ft_zeroflag_hex(flag, nbr, i));
	else if (flag.dot == 1 && flag.minus == 0)
		return (ft_ux_dot_div(flag, nbr, i));
	else if (flag.dot == 1 && flag.minus == 1)
		return (ft_ux_mdot_div(flag, nbr, i));
	return (0);
}
