/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_mult_div_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo < jaejo@student.42gyeongsan.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:42:55 by jaejo             #+#    #+#             */
/*   Updated: 2025/05/23 19:14:22 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./vec_utils.h"

double	square_vec(t_vec3 vec)
{
	return (vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}

t_vec3	vec_mult(t_vec3 vec, double t)
{
	vec.x *= t;
	vec.y *= t;
	vec.z *= t;
	return (vec);
}

t_vec3	two_vec_mult(t_vec3 vec, t_vec3 vec2)
{
	vec.x *= vec2.x;
	vec.y *= vec2.y;
	vec.z *= vec2.z;
	return (vec);
}

t_vec3	vec_div(t_vec3 vec, double t)
{
	vec.x *= 1 / t;
	vec.y *= 1 / t;
	vec.z *= 1 / t;
	return (vec);
}
