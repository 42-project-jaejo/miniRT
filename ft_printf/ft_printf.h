/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 20:45:22 by jaejo             #+#    #+#             */
/*   Updated: 2024/10/28 21:20:39 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define SPE "csidupxX%"

# include <stdarg.h>
# include <unistd.h>
# include "./libft/libft.h"

typedef struct s_setting
{
	char	specifier;
	int		minus;
	int		plus;
	int		space;
	int		hash;
	int		zero;
	int		dot;
	int		dot_len;
	int		width;
}	t_setting;

int			ft_check_spe(const char *str, t_setting flag, va_list ap);
int			ft_print_percent(void);
int			ft_print_c(t_setting flag, va_list ap);
int			ft_print_s(t_setting flag, va_list ap);
int			ft_print_id(t_setting flag, va_list ap);
int			ft_print_u(t_setting flag, va_list ap);
int			ft_print_x(t_setting flag, va_list ap);
int			ft_print_ux(t_setting flag, va_list ap);
int			ft_print_p(t_setting flag, va_list ap);
int			ft_u_dot_div(t_setting flag, char *nbr, int i);
int			ft_u_mdot_div(t_setting flag, char *nbr, int i);
int			ft_id_dot_div(t_setting flag, char *nbr, int i);
int			ft_id_mdot_div(t_setting flag, char *nbr, int i);
int			ft_mid_dot_div(t_setting flag, char *nbr, int i);
int			ft_mid_mdot_div(t_setting flag, char *nbr, int i);
int			ft_id_width(t_setting flag, char *nbr, int i);
int			ft_m_id_width(t_setting flag, char *nbr, int i);
int			ft_x_dot_div(t_setting flag, char *nbr, int i);
int			ft_x_mdot_div(t_setting flag, char *nbr, int i);
int			ft_ux_dot_div(t_setting flag, char *nbr, int i);
int			ft_ux_mdot_div(t_setting flag, char *nbr, int i);
int			ft_str_dot(t_setting flag, char *temp, int i);
int			ft_str_mdot(t_setting flag, char *temp, int i);
int			ft_null_div(t_setting flag);
int			ft_print_char(const char *str);
int			ft_print_xhash(t_setting flag, char *nbr);
int			ft_print_uxhash(t_setting flag, char *nbr);
int			ft_print_address(char *p);
int			ft_print_str(const char *str);
int			ft_print_istr(char *str);
int			ft_printf(const char *str, ...);
t_setting	ft_flag_format(t_setting flag);
t_setting	ft_flag_setting(const char *str, t_setting flag);

#endif
