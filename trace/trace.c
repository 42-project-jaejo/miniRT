/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo < jaejo@student.42gyeongsan.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 19:38:20 by jaejo             #+#    #+#             */
/*   Updated: 2025/05/28 18:46:49 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./trace.h"

t_ray	ray_init(t_vec_point3 orig, t_vec3 dir)
{
	t_ray	ray;

	ray.orig = orig;
	ray.dir = vec_unit(dir);
	return (ray);
}

t_vec_point3	ray_at(t_ray *ray, double t)
{
	t_vec_point3	at;

	at = two_vec_plus(ray->orig, vec_mult(ray->dir, t));
	return (at);
}

t_ray	ray_primary(t_camera *cam, double u, double v)
{
	t_ray	ray;

	ray.orig = cam->orig;
	ray.dir = vec_unit(two_vec_minus(two_vec_plus \
		(two_vec_plus(cam->left_bottom, vec_mult(cam->horizontal, u)), \
		vec_mult(cam->vertical, v)), cam->orig));
	return (ray);
}

t_bool	hit_obj(t_object *world, t_ray *ray, t_hit_record *rec)
{
	t_bool	hit_result;

	hit_result = FALSE;
	if (world->type == SP)
		hit_result = hit_sphere(world, ray, rec);
	return (hit_result);
}

t_bool	hit(t_object *world, t_ray *ray, t_hit_record *rec)
{
	t_bool			hit_anything;
	t_hit_record	temp_rec;

	temp_rec = *rec;
	hit_anything = FALSE;
	while (world)
	{
		if (hit_obj(world, ray, &temp_rec))
		{
			hit_anything = TRUE;
			temp_rec.tmax = temp_rec.t;
			*rec = temp_rec;
		}
		world = world->next;
	}
	return (hit_anything);
}

static t_hit_record record_init(void)
{
    t_hit_record    record;

    record.tmin = EPSILON;
    record.tmax = INFINITY;
    return (record);
}

t_color3	ray_color(t_scene *scene)
{
	double			t;
	// t_vec3			n;

	scene->rec = record_init();
	if (hit(scene->world, &scene->ray, &scene->rec))
        return (phong_lighting(scene));
	else
	{
		t = 0.5 * (scene->ray.dir.y + 1.0);
		return (two_vec_plus(vec_mult(color3(1, 1, 1), 1.0 - t), \
		vec_mult(color3(0.5, 0.7, 1.0), t)));
	}
}
