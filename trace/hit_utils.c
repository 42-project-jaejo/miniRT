/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsch <seungsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 19:54:49 by seungsch          #+#    #+#             */
/*   Updated: 2025/06/06 18:27:47 by seungsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./trace.h"

void	set_face_normal(t_ray *r, t_hit_record *rec)
{
	rec->front_face = vec_dot(r->dir, rec->normal) < 0;
	if (rec->front_face)
		rec->normal = rec->normal;
	else
		rec->normal = vec_mult(rec->normal, -1);
}

t_vec3	two_vec_projection(t_vec_point3 vec, t_vec3 normal)
{
	return (vec_mult(normal, vec_dot(vec, normal)));
}
