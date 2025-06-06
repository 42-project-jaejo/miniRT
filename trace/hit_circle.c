/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_circle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsch <seungsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 00:46:05 by seungsch          #+#    #+#             */
/*   Updated: 2025/06/06 19:07:05 by seungsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./trace.h"

t_bool	hit_top_circle(t_object *world, t_ray *ray, t_hit_record *rec)
{
	t_vec3		p;
	t_vec3		top_center;
	t_cylinder	*cycle;
	double		denom;
	double		t;

	cycle = world->element;
	denom = vec_dot(cycle->normal, ray->dir);
	top_center = two_vec_plus(cycle->center, vec_mult(cycle->normal,
				cycle->height / 2));
	if (fabs(denom) < EPSILON)
		return (FALSE);
	t = vec_dot(two_vec_minus(top_center, ray->orig), cycle->normal) / denom;
	if (t < rec->tmin || rec->tmax < t)
		return (FALSE);
	p = ray_at(ray, t);
	if (vec_length(two_vec_minus(p, top_center)) > cycle->radius)
		return (FALSE);
	rec->t = t;
	rec->p = p;
	rec->normal = cycle->normal;
	set_face_normal(ray, rec);
	rec->albedo = world->albedo;
	return (TRUE);
}

t_bool	hit_btm_circle(t_object *world, t_ray *ray, t_hit_record *rec)
{
	t_vec3 p;
	t_vec3 top_center;
	t_cylinder *cycle;
	double denom;
	double t;

	cycle = world->element;
	denom = vec_dot(cycle->normal, ray->dir);
	top_center = two_vec_minus(cycle->center, vec_mult(cycle->normal,
				cycle->height / 2));
	if (fabs(denom) < EPSILON)
		return (FALSE);
	t = vec_dot(two_vec_minus(top_center, ray->orig), cycle->normal) / denom;
	if (t < rec->tmin || rec->tmax < t)
		return (FALSE);
	p = ray_at(ray, t);
	if (vec_length(two_vec_minus(p, top_center)) > cycle->radius)
		return (FALSE);
	rec->t = t;
	rec->p = p;
	rec->normal = vec_mult(cycle->normal, -1);
	set_face_normal(ray, rec);
	rec->albedo = world->albedo;
	return (TRUE);
}