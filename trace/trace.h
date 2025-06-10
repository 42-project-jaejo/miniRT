/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 19:36:51 by jaejo             #+#    #+#             */
/*   Updated: 2025/06/09 22:48:30 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRACE_H
# define TRACE_H

# include "../types.h"
# include "../vec/vec_utils.h"

/* hit_circle.c */
t_bool			hit_top_circle(t_object *world, t_ray *ray, t_hit_record *rec);
t_bool			hit_btm_circle(t_object *world, t_ray *ray, t_hit_record *rec);
/* hit_cylinder.c */
t_bool			hit_cylinder(t_object *world, t_ray *ray, t_hit_record *rec);
/* hit_plane.c */
t_bool			hit_plane(t_object *world, t_ray *ray, t_hit_record *rec);
/* hit_sphere.c */
t_bool			hit_sphere(t_object *world, t_ray *ray, t_hit_record *rec);
/* hit_utils.c */
void			set_face_normal(t_ray *r, t_hit_record *rec);
t_vec3			two_vec_projection(t_vec_point3 vec, t_vec3 normal);
/* hit.c */
t_bool			hit(t_object *obj, t_ray *ray, t_hit_record *rec);
t_bool			hit_obj(t_object *obj, t_ray *ray, t_hit_record *rec);
/* trace.c */
t_vec_point3	ray_at(t_ray *ray, double t);
t_ray			ray_init(t_vec_point3 orig, t_vec3 dir);
t_ray			ray_primary(t_camera *cam, double u, double v);
t_color3		ray_color(t_scene *scene);
/* phong_lighting.c */
t_color3		phong_lighting(t_scene *scene);

#endif