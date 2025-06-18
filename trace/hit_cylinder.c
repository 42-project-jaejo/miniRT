/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsch <seungsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 19:51:10 by seungsch          #+#    #+#             */
/*   Updated: 2025/06/17 03:42:31 by seungsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./trace.h"

static t_vec3	get_normal(t_cylinder *cylinder, t_hit_record *rec)
{
	t_vec3	normal;
	t_vec3	cp;
	double	m;

	cp = two_vec_minus(rec->p, cylinder->center);
	m = vec_dot(cp, cylinder->normal);
	if (fabs(m + cylinder->height / 2) < EPSILON)
		normal = vec_mult(cylinder->normal, -1);
	else if (fabs(m - cylinder->height / 2) < EPSILON)
		normal = cylinder->normal;
	else
		normal = vec_unit(two_vec_minus(cp, vec_mult(cylinder->normal, m)));
	return (normal);
}

static t_bool	check_height(t_cylinder *cylinder, t_ray *ray, double root)
{
	if ((cylinder->height / 2) < vec_dot(two_vec_minus(ray_at(ray, root),
				cylinder->center), cylinder->normal) || -(cylinder->height
			/ 2) > vec_dot(two_vec_minus(ray_at(ray, root), cylinder->center),
			cylinder->normal))
		return (FALSE);
	return (TRUE);
}

static double	discriminant(t_cylinder *cylinder, t_ray *ray,
		t_hit_record *rec, double *root)
{
	t_vec3	oc;
	double	a;
	double	b;
	double	c;

	oc = two_vec_minus(ray->orig, cylinder->center);
	a = square_vec(two_vec_minus(ray->dir, vec_mult(cylinder->normal,
					vec_dot(ray->dir, cylinder->normal))));
	b = vec_dot(two_vec_minus(ray->dir, vec_mult(cylinder->normal,
					vec_dot(ray->dir, cylinder->normal))), two_vec_minus(oc,
				vec_mult(cylinder->normal, vec_dot(oc, cylinder->normal))));
	c = square_vec(two_vec_minus(oc, vec_mult(cylinder->normal, vec_dot(oc,
						cylinder->normal)))) - cylinder->radius2;
	if (b * b - a * c < 0)
		return (FALSE);
	*root = (-b - sqrt(b * b - a * c)) / a;
	if (*root < rec->tmin || rec->tmax < *root)
	{
		*root = (-b + sqrt(b * b - a * c)) / a;
		if (*root < rec->tmin || rec->tmax < *root)
			return (FALSE);
	}
	if (!check_height(cylinder, ray, *root))
		return (FALSE);
	return (TRUE);
}

static t_bool	hit_center_cylinder(t_object *world, t_ray *ray,
		t_hit_record *rec)
{
	t_cylinder	*cylinder;
	double		root;

	cylinder = world->element;
	if (!discriminant(cylinder, ray, rec, &root))
		return (FALSE);
	if (root > rec->t)
		return (FALSE);
	rec->t = root;
	rec->p = ray_at(ray, root);
	rec->normal = get_normal(cylinder, rec);
	set_face_normal(ray, rec);
	rec->albedo = world->albedo;
	return (TRUE);
}

t_bool	hit_cylinder(t_object *world, t_ray *ray, t_hit_record *rec)
{
	int	flag;

	flag = 0;
	rec->t = INFINITY;
	if (hit_center_cylinder(world, ray, rec))
		flag = 1;
	if (hit_top_circle(world, ray, rec))
		flag = 1;
	if (hit_btm_circle(world, ray, rec))
		flag = 1;
	if (flag == 1)
		return (TRUE);
	return (FALSE);
}
