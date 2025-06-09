/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 20:15:25 by jaejo             #+#    #+#             */
/*   Updated: 2025/06/10 00:22:30 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./hook.h"

t_vec3	rotate_xyz(t_vec3 vec, double radian, int key)
{
	t_vec3	new_vec;

	if (key == X)
	{
		new_vec.x = vec.x;
		new_vec.y = vec.y * cos(radian) - vec.z * sin(radian);
		new_vec.z = vec.y * sin(radian) + vec.z * cos(radian);
	}
	else if (key == Y)
	{
		new_vec.x = vec.x * cos(radian) + vec.z * sin(radian);
		new_vec.y = vec.y;
		new_vec.z = -vec.x * sin(radian) + vec.z * cos(radian);
	}
	else
	{
		new_vec.x = vec.x * cos(radian) - vec.y * sin(radian);
		new_vec.y = vec.x * sin(radian) + vec.y * cos(radian);
		new_vec.z = vec.z;
	}
	return (new_vec);
}

void	camera_rotate(t_scene *data, int key, double radian)
{
	t_vec3			u;
	t_vec3			v;

	data->camera.cam_dir = rotate_xyz(data->camera.cam_dir, radian, key);
	data->camera.vec_up = rotate_xyz(data->camera.vec_up, radian, key);
	u = vec_unit(vec_cross(data->camera.cam_dir, data->camera.vec_up));
	v = vec_cross(data->camera.cam_dir, u);
	data->camera.horizontal = vec_mult(u, data->camera.viewport_w);
	data->camera.vertical = vec_mult(vec_mult(v, -1), data->camera.viewport_h);
	data->camera.left_bottom = two_vec_minus(two_vec_minus \
		(two_vec_minus(data->camera.orig, vec_div(data->camera.horizontal, 2)), \
		vec_div(data->camera.vertical, 2)), \
		vec_mult(data->camera.cam_dir, -data->camera.focal_len));
}
