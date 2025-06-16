/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 16:09:21 by jaejo             #+#    #+#             */
/*   Updated: 2025/06/10 20:37:04 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./scene.h"

int	split_size(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

double	ft_strtod(char *str, int i)
{
	int		flag;
	double	div;
	double	int_part;
	double	frac_part;

	flag = 1;
	div = 10.0;
	int_part = 0.0;
	frac_part = 0.0;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			flag = -1;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		int_part = int_part * 10 + (str[i++] - '0');
	if (str[i] == '.')
	{
		i++;
		while (str[i] && str[i] >= '0' && str[i] <= '9')
		{
			frac_part += (str[i++] - '0') / div;
			div *= 10.0;
		}
	}
	return (flag * (int_part + frac_part));
}

char	**minirt_data(int fd)
{
	char	*temp;
	char	*one_line;
	char	*all_line;
	char	**data;

	temp = NULL;
	one_line = get_next_line(fd);
	all_line = ft_strjoin(one_line, "\0");
	while (one_line)
	{
		free(one_line);
		one_line = get_next_line(fd);
		if (!one_line)
			break ;
		temp = all_line;
		all_line = ft_strjoin(all_line, one_line);
		free(temp);
	}
	data = ft_split(all_line, '\n');
	free(all_line);
	close(fd);
	return (data);
}

t_bool	object_data_check(char *data, int *flag, int size)
{
	static int	a_flag = 0;
	static int	l_flag = 0;
	static int	c_flag = 0;

	if ((!ft_strncmp(data, "cy", 3) && size == 6) || (!ft_strncmp(data, "pl", 3)
			&& size == 4) || (!ft_strncmp(data, "sp", 3) && size == 4))
		return (TRUE);
	else if (!ft_strncmp(data, "A", 2) && size == 3)
		a_flag++;
	else if (!ft_strncmp(data, "L", 2) && size == 4)
		l_flag++;
	else if (!ft_strncmp(data, "C", 2) && size == 4)
		c_flag++;
	else
		return (FALSE);
	if (a_flag == 1 && c_flag == 1 && l_flag >= 1)
		*flag = 1;
	else
		*flag = 0;
	return (TRUE);
}
