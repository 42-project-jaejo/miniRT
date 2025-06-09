/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 22:50:59 by jaejo             #+#    #+#             */
/*   Updated: 2025/06/10 00:16:26 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./trace.h"

static double	discriminant_check(t_object *world, t_ray *ray)
{
	t_vec3	oc;
	double	half_b;
	double	c;
	double	a;

	oc = two_vec_minus(ray->orig, ((t_sphere *)(world->element))->center);
	a = square_vec(ray->dir);
	half_b = vec_dot(oc, ray->dir);
	c = square_vec(oc) - ((t_sphere *)(world->element))->radius2;
	return (half_b * half_b - a * c);
}

static t_bool	rec_sphere(t_object *world, t_ray *ray, t_hit_record *rec,
		double discriminant)
{
	t_vec3	oc;
	double	sqrtd;
	double	half_b;
	double	root;

	oc = two_vec_minus(ray->orig, ((t_sphere *)(world->element))->center);
	half_b = vec_dot(oc, ray->dir);
	sqrtd = sqrt(discriminant);
	root = (-half_b - sqrtd) / square_vec(ray->dir);
	if (root < rec->tmin || rec->tmax < root)
	{
		root = (-half_b + sqrtd) / square_vec(ray->dir);
		if (root < rec->tmin || rec->tmax < root)
			return (FALSE);
	}
	rec->t = root;
	rec->p = ray_at(ray, root);
	rec->normal = vec_div(two_vec_minus(rec->p,
				((t_sphere *)(world->element))->center),
			((t_sphere *)(world->element))->radius);
	set_face_normal(ray, rec);
	rec->albedo = world->albedo;
	return (TRUE);
}

t_bool	hit_sphere(t_object *world, t_ray *ray, t_hit_record *rec)
{
	double		discriminant;
	t_sphere	*sp;

	sp = world->element;
	discriminant = discriminant_check(world, ray);
	if (discriminant < 0)
		return (FALSE);
	if (!rec_sphere(world, ray, rec, discriminant))
		return (FALSE);
	return (TRUE);
}
