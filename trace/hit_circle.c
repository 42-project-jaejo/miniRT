/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_circle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsch <seungsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 00:46:05 by seungsch          #+#    #+#             */
/*   Updated: 2025/06/18 18:59:39 by seungsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./trace.h"

static t_bool	rec_cycle(t_object *world, t_ray *ray, t_hit_record *rec,
		double t)
{
	t_cylinder	*cycle;
	t_vec3		p;
	t_vec3		normal;

	p = ray_at(ray, t);
	cycle = world->element;
	if (t > rec->t)
		return (FALSE);
	rec->t = t;
	rec->p = p;
	normal = vec_unit(cycle->normal);
	if (vec_dot(rec->normal, cycle->normal) < 0.0)
		normal = vec_mult(normal, -1);
	rec->normal = normal;
	set_face_normal(ray, rec);
	rec->albedo = world->albedo;
	return (TRUE);
}

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
	if (!rec_cycle(world, ray, rec, t))
		return (FALSE);
	return (TRUE);
}

t_bool	hit_btm_circle(t_object *world, t_ray *ray, t_hit_record *rec)
{
	t_vec3		p;
	t_vec3		top_center;
	t_cylinder	*cycle;
	double		denom;
	double		t;

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
	if (t > rec->t)
		return (FALSE);
	if (!rec_cycle(world, ray, rec, t))
		return (FALSE);
	return (TRUE);
}
