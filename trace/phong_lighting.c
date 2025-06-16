/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_lighting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsch <seungsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 22:23:55 by jaejo             #+#    #+#             */
/*   Updated: 2025/06/17 02:49:50 by seungsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./trace.h"

static t_bool	in_shadow(t_object *objs, t_ray light_ray, double light_len)
{
	t_hit_record	rec;

	rec.tmin = 0;
	rec.normal = vec3(0, 0, 0);
	rec.tmax = light_len;
	if (hit(objs, &light_ray, &rec))
		return (TRUE);
	return (FALSE);
}

static t_bool	make_shadow(t_scene *scene, t_vec3 light_dir)
{
	double		light_len;
	t_ray		light_ray;

	light_len = vec_length(light_dir);
	light_ray = ray_init(two_vec_plus(scene->rec.p, vec_mult(scene->rec.normal,
					EPSILON)), light_dir);
	if (in_shadow(scene->world, light_ray, light_len))
		return (TRUE);
	else
		return (FALSE);
}

static t_color3	make_specular(t_scene *scene, t_light *light, t_vec3 light_dir)
{
	t_color3	specular;
	t_vec3		view_dir;
	t_vec3		reflect_dir;
	double		spec;
	double		ksn;

	view_dir = vec_unit(vec_mult(scene->ray.dir, -1));
	reflect_dir = two_vec_minus(vec_mult(light_dir, -1), \
	vec_mult(scene->rec.normal, vec_dot(vec_mult(light_dir, -1), \
	scene->rec.normal) * 2));
	ksn = 64;
	spec = pow(fmax(vec_dot(view_dir, reflect_dir), 0.0), ksn);
	specular = vec_mult(vec_mult(light->light_color, 0.5), spec);
	return (specular);
}

static t_color3	point_light_get(t_scene *scene, t_light *light)
{
	t_color3	diffuse;
	t_vec3		light_dir;
	double		kd;
	t_color3	specular;
	double		brightness;

	light_dir = two_vec_minus(light->origin, scene->rec.p);
	if (make_shadow(scene, light_dir))
		return (color3(0, 0, 0));
	light_dir = vec_unit(light_dir);
	kd = fmax(vec_dot(scene->rec.normal, light_dir), 0.0);
	diffuse = vec_mult(light->light_color, kd);
	specular = make_specular(scene, light, light_dir);
	brightness = light->bright_ratio * LUMEN;
	return (vec_mult(two_vec_plus(diffuse, specular), brightness));
}

t_color3	phong_lighting(t_scene *scene)
{
	t_color3	light_color;
	t_object	*lights;

	light_color = color3(0, 0, 0);
	lights = scene->light;
	while (lights)
	{
		if (lights->type == LIGHT_POINT)
			light_color = two_vec_plus(light_color, point_light_get(scene,
						lights->element));
		lights = lights->next;
	}
	light_color = two_vec_plus(light_color, scene->ambient);
	return (vec_min(two_vec_mult(light_color, scene->rec.albedo), color3(1, 1,
				1)));
}
