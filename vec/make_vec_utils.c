/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_vec_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 21:25:55 by jaejo             #+#    #+#             */
/*   Updated: 2025/06/03 21:15:21 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./vec_utils.h"

t_vec3	vec3(double x, double y, double z)
{
	t_vec3	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

t_vec_point3	vec_point3(double x, double y, double z)
{
	t_vec_point3	point;

	point.x = x;
	point.y = y;
	point.z = z;
	return (point);
}

t_vec_point3	color3(double r, double g, double b)
{
	t_color3	color;

	color.x = r;
	color.y = g;
	color.z = b;
	return (color);
}

void	vec_set(t_vec3 *vec, double x, double y, double z)
{
	vec->x = x;
	vec->y = y;
	vec->z = z;
}
