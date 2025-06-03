/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsch <seungsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:20:37 by jaejo             #+#    #+#             */
/*   Updated: 2025/06/04 00:26:28 by seungsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	len(unsigned long long temp)
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

static char	*ft_nil(unsigned long long temp)
{
	char	*nbr;

	nbr = NULL;
	if (temp == 0)
	{
		nbr = (char *)malloc(sizeof(char) * 6);
		if (nbr == 0)
			return (NULL);
		nbr[0] = '(';
		nbr[1] = 'n';
		nbr[2] = 'i';
		nbr[3] = 'l';
		nbr[4] = ')';
		nbr[5] = '\0';
	}
	return (nbr);
}

static char	*ft_hexnbr(unsigned long long temp)
{
	char				*nbr;
	int					i;
	unsigned long long	j;

	if (temp == 0)
		return (ft_nil(temp));
	i = len(temp);
	nbr = (char *)malloc(sizeof(char) * i + 1);
	if (nbr == 0)
		return (NULL);
	nbr[i] = '\0';
	while (temp != 0)
	{
		i--;
		j = temp % 16;
		if (j < 10)
			nbr[i] = 48 + j;
		else
			nbr[i] = 97 + (j - 10);
		temp = temp / 16;
	}
	return (nbr);
}

static int	ft_onlyflag_p(t_setting flag, char *p, int i)
{
	i = (int)ft_strlen(p);
	if (p[0] != '(')
		i += 2;
	if (flag.width > i && flag.minus == 0)
	{
		while (flag.width - i++ > 0)
			write(1, " ", 1);
		ft_print_address(p);
		ft_print_istr(p);
		return (flag.width);
	}
	else if (flag.width > (int)ft_strlen(p) + 2 && flag.minus == 1)
	{
		ft_print_address(p);
		ft_print_istr(p);
		while (flag.width - i++ > 0)
			write(1, " ", 1);
		return (flag.width);
	}
	else
		ft_print_address(p);
	ft_print_istr(p);
	return (i);
}

int	ft_print_p(t_setting flag, va_list ap)
{
	void	*temp;
	char	*p;
	int		i;

	i = 0;
	temp = va_arg(ap, void *);
	p = ft_hexnbr((unsigned long long)temp);
	if (flag.dot == 0 && flag.zero == 0)
		return (ft_onlyflag_p(flag, p, i));
	return (0);
}
