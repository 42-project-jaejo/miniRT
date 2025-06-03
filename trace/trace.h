/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo < jaejo@student.42gyeongsan.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 19:36:51 by jaejo             #+#    #+#             */
/*   Updated: 2025/05/29 16:58:58 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRACE_H
# define TRACE_H

# include "../types.h"
# include "../vec/vec_utils.h"

t_ray			ray_init(t_vec_point3 orig, t_vec3 dir);
t_ray			ray_primary(t_camera *cam, double u, double v);
t_color3        ray_color(t_scene *scene);
t_color3	    point_light_get(t_scene *scene, t_light *light);
t_vec_point3	ray_at(t_ray *ray, double t);
t_bool          hit(t_object *obj, t_ray *ray, t_hit_record *rec);
t_bool          hit_obj(t_object *obj, t_ray *ray, t_hit_record *rec);
t_bool			hit_sphere(t_object *world, t_ray *ray, t_hit_record *rec);
t_color3        phong_lighting(t_scene *scene);

#endif