/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 21:16:25 by jaejo             #+#    #+#             */
/*   Updated: 2025/06/03 21:17:12 by jaejo            ###   ########.fr       */
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