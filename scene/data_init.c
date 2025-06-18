/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsch <seungsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 20:11:06 by jaejo             #+#    #+#             */
/*   Updated: 2025/06/18 18:57:17 by seungsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./scene.h"

t_object	*ft_light_intit(char **data)
{
	double			brightness_ratio;
	t_light			*lights;
	t_object		*obj;
	t_color3		color;
	t_vec_point3	point;

	brightness_ratio = ft_strtod(data[2], 0);
	point = ft_char_to_vec(data[1]);
	color = ft_char_to_vec(data[3]);
	color = ft_trance_rgb(color);
	lights = light_point(point, color, brightness_ratio);
	obj = object_init(LIGHT_POINT, lights, color3(0, 0, 0));
	return (obj);
}

t_object	*ft_sp_init(char **data)
{
	t_object	*sp;
	t_vec3		center;
	t_color3	color;
	double		r;

	r = ft_strtod(data[2], 0);
	color = ft_char_to_vec(data[3]);
	center = ft_char_to_vec(data[1]);
	color = ft_trance_rgb(color);
	sp = object_init(SP, sphere_init(center, r), color);
	return (sp);
}

t_object	*ft_pl_init(char **data)
{
	t_object		*obj;
	t_vec_point3	center;
	t_vec3			normal;
	t_color3		color;

	normal = vec_normalize(ft_char_to_vec(data[2]));
	color = ft_char_to_vec(data[3]);
	center = ft_char_to_vec(data[1]);
	color = ft_trance_rgb(color);
	obj = object_init(PL, plane_init(center, normal), color);
	return (obj);
}

t_object	*ft_cy_init(char **data)
{
	t_object	*obj;
	t_vec3		center;
	t_color3	color;
	t_vec3		normal;

	color = ft_char_to_vec(data[5]);
	center = ft_char_to_vec(data[1]);
	normal = vec_normalize(ft_char_to_vec(data[2]));
	color = ft_trance_rgb(color);
	obj = object_init(CY, cylinder_init(center, normal, ft_strtod(data[4], 0),
				ft_strtod(data[3], 0)), color);
	return (obj);
}

t_camera	ft_camera_init(t_canvas *canvas, char **data)
{
	t_camera	cam;
	t_vec3		u;
	t_vec3		v;

	cam.focal_len = 1.0;
	cam.cam_dir = ft_char_to_vec(data[2]);
	cam_direction_setting(&cam, cam.cam_dir);
	u = vec_unit(vec_cross(cam.cam_dir, cam.vec_up));
	v = vec_cross(cam.cam_dir, u);
	cam.fov = ft_strtod(data[3], 0) * (M_PI / 180.0);
	cam.orig = ft_char_to_vec(data[1]);
	cam.viewport_h = tan(cam.fov / 2) * cam.focal_len;
	cam.viewport_w = cam.viewport_h * canvas->aspect_ratio;
	cam.horizontal = vec_mult(u, cam.viewport_w);
	cam.vertical = vec_mult(vec_mult(v, -1), cam.viewport_h);
	cam.left_bottom = two_vec_minus(two_vec_minus(two_vec_minus(cam.orig, \
					vec_div(cam.horizontal, 2)), vec_div(cam.vertical, 2)), \
			vec_mult(cam.cam_dir, -cam.focal_len));
	return (cam);
}
