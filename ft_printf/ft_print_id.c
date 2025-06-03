/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_id.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:28:22 by jaejo             #+#    #+#             */
/*   Updated: 2024/10/26 22:37:04 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	len(long long n, int *minus)
{
	int	i;

	i = 0;
	*minus = 0;
	if (n < 0)
	{
		n *= -1;
		*minus = 1;
		i++;
	}
	else if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*ft_print_itoa(long long n)
{
	char		*temp;
	int			i;
	int			minus;
	long long	nbr;

	nbr = n;
	i = len(nbr, &minus);
	if (nbr < 0)
		nbr *= -1;
	temp = (char *)malloc (sizeof(char) * (i + 1));
	if (temp == 0)
		return (NULL);
	temp[i] = '\0';
	while (--i >= 0)
	{
		temp[i] = nbr % 10 + 48;
		nbr = nbr / 10;
	}
	if (minus)
		temp[0] = '-';
	else if (n == 0)
		temp[0] = '0';
	return (temp);
}

int	ft_onlyflag_nbr(t_setting flag, char *nbr, int i)
{
	if (flag.plus == 0 && flag.space == 1 && nbr[0] != '-')
	{
		write (1, " ", 1);
		i++;
	}
	else if (flag.plus == 1 && nbr[0] != '-')
	{
		write (1, "+", 1);
		i++;
	}
	if (nbr[0] == '-')
		write (1, "-", 1);
	return (ft_print_istr(nbr) + i);
}

int	ft_print_id(t_setting flag, va_list ap)
{
	int			i;
	long long	temp;
	char		*nbr;

	i = 0;
	temp = va_arg(ap, int);
	nbr = ft_print_itoa(temp);
	if (flag.dot == 0 && flag.width <= (int)ft_strlen(nbr))
		return (ft_onlyflag_nbr(flag, nbr, i));
	else if (flag.dot == 0 && flag.width > (int)ft_strlen(nbr))
		return (ft_id_width(flag, nbr, i));
	else if (flag.dot == 1 && flag.minus == 0 && nbr[0] != '-')
		return (ft_id_dot_div(flag, nbr, i));
	else if (flag.dot == 1 && flag.minus == 1 && nbr[0] != '-')
		return (ft_id_mdot_div(flag, nbr, i));
	else if (flag.dot == 1 && flag.minus == 0 && nbr[0] == '-')
		return (ft_mid_dot_div(flag, nbr, i));
	else if (flag.dot == 1 && flag.minus == 1 && nbr[0] == '-')
		return (ft_mid_mdot_div(flag, nbr, i));
	return (0);
}
