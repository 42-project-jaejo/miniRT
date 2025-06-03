/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 22:50:59 by jaejo             #+#    #+#             */
/*   Updated: 2025/05/28 00:14:21 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./trace.h"

static void    set_face_normal(t_ray *r, t_hit_record *rec)
{
	rec->front_face = vec_dot(r->dir, rec->normal) < 0;
	if (rec->front_face)
		rec->normal = rec->normal;
	else
		rec->normal = vec_mult(rec->normal, -1);
}

t_bool	hit_sphere(t_object *world, t_ray *ray, t_hit_record *rec)
{
	t_vec3	oc;
	double	a;
	double	half_b;
	double	c;
	double	discriminant;
	double	sqrtd;
	double	root;
	t_sphere *sp;

	sp = world->element;
	oc = two_vec_minus(ray->orig, sp->center);
	a = square_vec(ray->dir);
	half_b = vec_dot(oc, ray->dir);
	c = square_vec(oc) - sp->radius2;
	discriminant = half_b * half_b - a * c;
	if (discriminant < 0)
		return (FALSE);
	sqrtd = sqrt(discriminant);
	root = (-half_b - sqrtd) / a;
	if (root < rec->tmin || rec->tmax < root)
	{
		root = (-half_b + sqrtd) / a;
		if (root < rec->tmin || rec->tmax < root)
			return (FALSE);
	}
	rec->t = root;
	rec->p = ray_at(ray, root);
	rec->normal = vec_div(two_vec_minus(rec->p, sp->center), sp->radius);
	set_face_normal(ray, rec);
	rec->albedo = world->albedo;
	return (TRUE);
}
