/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_setting.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 23:39:22 by jaejo             #+#    #+#             */
/*   Updated: 2024/10/28 20:20:29 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_spe(const char *str, t_setting flag, va_list ap)
{
	if (*str == 'c')
		return (ft_print_c(flag, ap));
	else if (*str == 's')
		return (ft_print_s(flag, ap));
	else if (*str == 'i' || *str == 'd')
		return (ft_print_id(flag, ap));
	else if (*str == '%')
		return (ft_print_percent());
	else if (*str == 'u')
		return (ft_print_u(flag, ap));
	else if (*str == 'x')
		return (ft_print_x(flag, ap));
	else if (*str == 'X')
		return (ft_print_ux(flag, ap));
	else if (*str == 'p')
		return (ft_print_p(flag, ap));
	return (0);
}
