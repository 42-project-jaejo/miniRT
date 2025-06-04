/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsch <seungsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 22:50:59 by jaejo             #+#    #+#             */
/*   Updated: 2025/06/04 19:18:15 by seungsch         ###   ########.fr       */
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

static double	discriminant_check(t_object *world, t_ray *ray)
{
	t_vec3	oc;
	double	half_b;
	double	discriminant;
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
	double	a;

	oc = two_vec_minus(ray->orig, ((t_sphere *)(world->element))->center);
	a = square_vec(ray->dir);
	half_b = vec_dot(oc, ray->dir);
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
	double		sqrtd;
	double		root;
	t_sphere	*sp;

	sp = world->element;
	discriminant = discriminant_check(world, ray);
	if (discriminant < 0)
		return (FALSE);
	if (!rec_sphere(world, ray, rec, discriminant))
		return (FALSE);
	return (TRUE);
}
