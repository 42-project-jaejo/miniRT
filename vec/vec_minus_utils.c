/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_minus_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo < jaejo@student.42gyeongsan.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:51:52 by jaejo             #+#    #+#             */
/*   Updated: 2025/05/23 19:01:29 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./vec_utils.h"

t_vec3	two_vec_minus(t_vec3 vec, t_vec3 vec2)
{
	vec.x -= vec2.x;
	vec.y -= vec2.y;
	vec.z -= vec2.z;
	return (vec);
}

t_vec3	vec_minus(t_vec3 vec, double x, double y, double z)
{
	vec.x -= x;
	vec.y -= y;
	vec.z -= z;
	return (vec);
}
