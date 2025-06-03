/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsch <seungsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 21:16:25 by jaejo             #+#    #+#             */
/*   Updated: 2025/06/04 00:33:28 by seungsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./scene.h"

t_vec3	ft_char_to_vec(char *data)
{
	t_vec3	vec;
	char	**split;

	split = ft_split(data, ',');
	vec.x = ft_strtod(split[0], 0);
	vec.y = ft_strtod(split[1], 0);
	vec.z = ft_strtod(split[2], 0);
	split_free(split);
	return (vec);
}
