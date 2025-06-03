/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 18:52:27 by jaejo             #+#    #+#             */
/*   Updated: 2024/10/27 20:31:24 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	len(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*ft_print_itoa(unsigned int n)
{
	char		*temp;
	int			i;
	long long	nbr;

	nbr = n;
	i = len(nbr);
	temp = (char *)malloc (sizeof(char) * (i + 1));
	if (temp == 0)
		return (NULL);
	temp[i] = '\0';
	if (n == 0)
		temp[0] = '0';
	while (--i >= 0)
	{
		temp[i] = nbr % 10 + 48;
		nbr = nbr / 10;
	}
	return (temp);
}

static int	ft_onlyflag_unbr(t_setting flag, char *nbr, int i)
{
	i = (int)ft_strlen(nbr);
	if (flag.width > i && flag.minus == 0)
	{
		while (flag.width - i++ > 0)
			write (1, " ", 1);
		ft_print_istr(nbr);
		return (flag.width);
	}
	else if (flag.width > i && flag.minus == 1)
	{
		ft_print_istr(nbr);
		while (flag.width - i++ > 0)
			write (1, " ", 1);
		return (flag.width);
	}
	return (ft_print_istr(nbr));
}

static int	ft_zeroflag_unbr(t_setting flag, char *nbr, int i)
{
	i = (int)ft_strlen(nbr);
	if (flag.width > i && flag.minus == 0)
	{
		while (flag.width - i++ > 0)
			write (1, "0", 1);
		ft_print_istr(nbr);
		return (flag.width);
	}
	else if (flag.width > i && flag.minus == 1)
	{
		ft_print_istr(nbr);
		while (flag.width - i++ > 0)
			write (1, " ", 1);
		return (flag.width);
	}
	return (ft_print_istr(nbr));
}

int	ft_print_u(t_setting flag, va_list ap)
{
	unsigned int	temp;
	char			*nbr;
	int				i;

	i = 0;
	temp = va_arg(ap, unsigned int);
	nbr = ft_print_itoa(temp);
	if (flag.dot == 0 && flag.zero == 0)
		return (ft_onlyflag_unbr(flag, nbr, i));
	else if (flag.dot == 0 && flag.zero == 1)
		return (ft_zeroflag_unbr(flag, nbr, i));
	else if (flag.dot == 1 && flag.minus == 0)
		return (ft_u_dot_div(flag, nbr, i));
	else if (flag.dot == 1 && flag.minus == 1)
		return (ft_u_mdot_div(flag, nbr, i));
	return (0);
}
