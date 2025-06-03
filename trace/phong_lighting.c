/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_lighting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo < jaejo@student.42gyeongsan.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 22:23:55 by jaejo             #+#    #+#             */
/*   Updated: 2025/05/29 16:30:55 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./trace.h"

t_vec3		reflect(t_vec3 v, t_vec3 n)
{
	return (two_vec_minus(v, vec_mult(n, vec_dot(v, n) * 2)));
}

t_bool	in_shadow(t_object *objs, t_ray light_ray, double light_len)
{
	t_hit_record	rec;

	rec.tmin = 0;
	rec.tmax = light_len;
	if (hit(objs, &light_ray, &rec))
		return (TRUE);
	return (FALSE);
}

t_color3	point_light_get(t_scene *scene, t_light *light)
{
//기본 
	t_color3	diffuse;
	t_vec3		light_dir;
	double		kd;
//1
	double		light_len;
	t_ray		light_ray;
// 2	
	t_color3	specular;
	t_vec3		view_dir;
	t_vec3		reflect_dir;
	double		spec;
	double		ksn;
	double		ks;
	double		brightness;

//1 (그림자)
	light_dir = two_vec_minus(light->origin, scene->rec.p);
	light_len = vec_length(light_dir);
	light_ray = ray_init(two_vec_plus(scene->rec.p, vec_mult(scene->rec.normal, EPSILON)), light_dir);
	if (in_shadow(scene->world, light_ray, light_len))
		return (color3(0, 0, 0));
	light_dir = vec_unit(light_dir);
// 기본
	// light_dir = vec_unit(two_vec_minus(light->origin, scene->rec.p));
	kd = fmax(vec_dot(scene->rec.normal, light_dir), 0.0);
	diffuse = vec_mult(light->light_color, kd);
// 2 (물체의 빛 반사 부분)	
	view_dir = vec_unit(vec_mult(scene->ray.dir, -1));
	reflect_dir = reflect(vec_mult(light_dir, -1), scene->rec.normal);
	ksn = 64;
	ks = 0.5;
	spec = pow(fmax(vec_dot(view_dir, reflect_dir), 0.0), ksn);
	specular = vec_mult(vec_mult(light->light_color, ks), spec);
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
			light_color = two_vec_plus(light_color, point_light_get(scene, lights->element));
		lights = lights->next;
	}
	light_color = two_vec_plus(light_color, scene->ambient);
	return (vec_min(two_vec_mult(light_color, scene->rec.albedo), color3(1, 1, 1)));
}