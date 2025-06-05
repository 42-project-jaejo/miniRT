/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsch <seungsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 01:14:28 by seungsch          #+#    #+#             */
/*   Updated: 2025/06/04 19:33:00 by seungsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./trace.h"

t_bool	hit_plane(t_object *world, t_ray *ray, t_hit_record *rec)
{
	t_vec3	p;
	t_plane	*pl;
	double	denom;
	double	t;

	pl = world->element;
	denom = vec_dot(pl->normal, ray->dir);
	if (fabs(denom) < EPSILON)
		return (FALSE);
	p = two_vec_minus(pl->point, ray->orig);
	t = vec_dot(p, pl->normal) / denom;
	if (t < rec->tmin || rec->tmax < t)
		return (FALSE);
	rec->t = t;
	rec->p = ray_at(ray, t);
	rec->normal = pl->normal;
	set_face_normal(ray, rec);
	rec->albedo = world->albedo;
	return (TRUE);
}
