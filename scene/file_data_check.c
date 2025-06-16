/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_data_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsch <seungsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 20:29:19 by jaejo             #+#    #+#             */
/*   Updated: 2025/06/17 03:33:34 by seungsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./scene.h"

static t_bool	value_data_check(char *data, int type)
{
	char	**vec;

	vec = ft_split(data, ',');
	if (split_size(vec) == 3)
	{
		if (type == RGB && 0 <= ft_strtod(vec[0], 0) && ft_strtod(vec[0], 0) \
			<= 255 && 0 <= ft_strtod(vec[1], 0) && ft_strtod(vec[1], 0) <= 255 \
			&& 0 <= ft_strtod(vec[2], 0) && ft_strtod(vec[2], 0) <= 255)
			return (split_free(vec), TRUE);
		else if (type == VEC)
			return (split_free(vec), TRUE);
		else if (type == O_VEC && -1.0 <= ft_strtod(vec[0], 0)
			&& ft_strtod(vec[0], 0) <= 1.0 && -1.0 <= ft_strtod(vec[1], 0)
			&& ft_strtod(vec[1], 0) <= 1.0 && -1.0 <= ft_strtod(vec[2], 0)
			&& ft_strtod(vec[2], 0) <= 1.0)
			return (split_free(vec), TRUE);
	}
	split_free(vec);
	return (FALSE);
}

static t_bool	detect_value_type(char **data)
{
	if (!ft_strncmp(data[0], "A", 2) && value_data_check(data[2], RGB)
		&& (0.0 <= ft_strtod(data[1], 0) && ft_strtod(data[1], 0) <= 1.0))
		return (TRUE);
	else if (!ft_strncmp(data[0], "C", 2) && value_data_check(data[1], VEC)
		&& 0 <= ft_atoi(data[3]) && ft_atoi(data[3]) <= 180
		&& value_data_check(data[2], O_VEC) && \
		cam_direction_setting(NULL, ft_char_to_vec(data[2])))
		return (TRUE);
	else if (!ft_strncmp(data[0], "L", 2) && value_data_check(data[1], VEC)
		&& (0.0 <= ft_strtod(data[2], 0) && ft_strtod(data[2], 0) <= 1.0)
		&& value_data_check(data[3], RGB))
		return (TRUE);
	else if (!ft_strncmp(data[0], "sp", 3) && value_data_check(data[1], VEC)
		&& ft_strtod(data[2], 0) > 0.0 && value_data_check(data[3], RGB))
		return (TRUE);
	else if (!ft_strncmp(data[0], "pl", 3) && value_data_check(data[1], VEC)
		&& value_data_check(data[3], RGB) && value_data_check(data[2], O_VEC))
		return (TRUE);
	else if (!ft_strncmp(data[0], "cy", 3) && value_data_check(data[1], VEC)
		&& ft_strtod(data[3], 0) > 0.0 && ft_strtod(data[4], 0) > 0.0
		&& value_data_check(data[5], RGB) && value_data_check(data[2], O_VEC))
		return (TRUE);
	return (FALSE);
}

static t_bool	string_check(char **data)
{
	int	i;
	int	j;

	i = 1;
	while (data[i])
	{
		j = 0;
		if (data[i][j] && (data[i][j] == '+' || data[i][j] == '-'))
			j++;
		while (data[i][j] && data[i][j] >= '0' && data[i][j] <= '9')
		{
			while (data[i][j] && data[i][j] >= '0' && data[i][j] <= '9')
				j++;
			if (data[i][j] && (data[i][j] == ',' || data[i][j] == '.'))
				j++;
			if (data[i][j] && (data[i][j] == '+' || data[i][j] == '-'))
				j++;
		}
		if (data[i][j])
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static t_bool	detect_rt_type(char **data, int *flag)
{
	if (object_data_check(data[0], flag, split_size(data)))
	{
		if (detect_value_type(data))
		{
			if (string_check(data))
			{
				split_free(data);
				return (TRUE);
			}
		}
	}
	return (FALSE);
}

t_bool	file_data_check(int fd)
{
	int		i;
	int		flag;
	char	**file_data;
	char	**object_data;

	i = -1;
	file_data = minirt_data(fd);
	while (file_data[++i])
	{
		object_data = ft_split(file_data[i], ' ');
		if (!object_data[0])
			split_free(object_data);
		else if (detect_rt_type(object_data, &flag))
			continue ;
		else
		{
			split_free(file_data);
			split_free(object_data);
			return (FALSE);
		}
	}
	split_free(file_data);
	if (flag)
		return (TRUE);
	return (FALSE);
}
