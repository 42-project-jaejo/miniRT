/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 17:07:23 by jaejo             #+#    #+#             */
/*   Updated: 2024/10/15 21:02:22 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len(long n, int *flag)
{
	int	i;

	i = 0;
	*flag = 0;
	if (n < 0)
	{
		n *= -1;
		*flag = 1;
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

char	*ft_itoa(int n)
{
	char	*temp;
	int		i;
	int		flag;
	long	nbr;

	nbr = n;
	i = len(nbr, &flag);
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
	if (flag)
		temp[0] = '-';
	else if (n == 0)
		temp[0] = '0';
	return (temp);
}
