/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 17:19:48 by jaejo             #+#    #+#             */
/*   Updated: 2025/05/28 00:10:11 by jaejo            ###   ########.fr       */
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
	sp->radius = radius;
	sp->radius2 = radius * radius;
	return (sp);
}

t_light	*light_point(t_vec_point3 light_origin, t_color3 light_color, double bright_ratio)
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
