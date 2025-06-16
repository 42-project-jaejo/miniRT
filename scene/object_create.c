/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsch <seungsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 17:19:48 by jaejo             #+#    #+#             */
/*   Updated: 2025/06/17 02:06:51 by seungsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./scene.h"

t_object	*object_init(t_object_type type, void *element, t_color3 albedo)
{
	t_object	*new;

	new = (t_object *)malloc(sizeof(t_object));
	if (!new)
		return (NULL);
	new->type = type;
	new->element = element;
	new->albedo = albedo;
	new->next = NULL;
	return (new);
}

t_sphere	*sphere_init(t_vec_point3 center, double radius)
{
	t_sphere	*sp;

	sp = (t_sphere *)malloc(sizeof(t_sphere));
	if (!sp)
		return (sp);
	sp->center = center;
	sp->radius = radius / 2;
	sp->radius2 = sp->radius * sp->radius;
	return (sp);
}

t_light	*light_point(t_vec_point3 light_origin, t_color3 light_color,
		double bright_ratio)
{
	t_light	*light;

	light = (t_light *)malloc(sizeof(t_light));
	if (!light)
		return (NULL);
	light->origin = light_origin;
	light->light_color = light_color;
	light->bright_ratio = bright_ratio;
	return (light);
}

t_plane	*plane_init(t_vec_point3 point, t_vec3 dir)
{
	t_plane	*pl;

	pl = (t_plane *)malloc(sizeof(t_plane));
	if (!pl)
		return (NULL);
	pl->point = point;
	pl->normal = dir;
	return (pl);
}

t_cylinder	*cylinder_init(t_vec_point3 center, t_vec3 normal, double height,
		double radius)
{
	t_cylinder	*cy;

	cy = (t_cylinder *)malloc(sizeof(t_cylinder));
	if (!cy)
		return (cy);
	cy->normal = normal;
	cy->center = center;
	cy->height = height;
	cy->radius = radius / 2;
	cy->radius2 = cy->radius * cy->radius;
	return (cy);
}
