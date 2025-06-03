/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_setting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 22:54:37 by jaejo             #+#    #+#             */
/*   Updated: 2024/10/28 19:28:42 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_setting	ft_width_len(const char *str, t_setting flag)
{
	int	i;
	int	temp;

	i = 0;
	temp = 0;
	while (str[i] == '#' || str[i] == '0' || str[i] == '-' || \
			str[i] == '+' || str[i] == ' ')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		temp = (temp * 10) + (str[i] - 48);
		i++;
	}
	flag.width = temp;
	return (flag);
}

static t_setting	ft_dot_len(const char *str, t_setting flag)
{
	int	i;
	int	temp;

	i = 0;
	temp = 0;
	if (flag.dot == 1)
	{
		while (str[i] != '.')
			i++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		temp = (temp * 10) + (str[i] - 48);
		i++;
	}
	flag.dot_len = temp;
	return (flag);
}

t_setting	ft_flag_setting(const char *str, t_setting flag)
{
	int	i;

	i = 0;
	while (!ft_strchr(SPE, str[i]))
	{
		if (str[i] == '0' && str[i - 1] != '.' && \
				!(str[i - 1] >= '1' && str[i - 1] <= '9'))
			flag.zero = 1;
		else if (str[i] == '-')
			flag.minus = 1;
		else if (str[i] == ' ')
			flag.space = 1;
		else if (str[i] == '+')
			flag.plus = 1;
		else if (str[i] == '#')
			flag.hash = 1;
		else if (str[i] == '.')
			flag.dot = 1;
		i++;
	}
	flag = ft_width_len(str, flag);
	if (flag.dot)
		flag = ft_dot_len(str, flag);
	return (flag);
}
