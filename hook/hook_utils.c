/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 22:18:54 by jaejo             #+#    #+#             */
/*   Updated: 2025/06/09 21:56:13 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./hook.h"

void	put_string(t_scene *data)
{
	mlx_string_put(data->mlx_data.mlx, data->mlx_data.win, 50, 50, 0, \
		"Note");
	mlx_string_put(data->mlx_data.mlx, data->mlx_data.win, 50, 70, 0, \
		"Move up: key bord up            Object chaging Camera: 1");
	mlx_string_put(data->mlx_data.mlx, data->mlx_data.win, 50, 90, 0, \
		"Move down: key bord down        Object chaging Light: 2");
	mlx_string_put(data->mlx_data.mlx, data->mlx_data.win, 50, 110, 0, \
		"Move left: key bord left        Object chaging: 3");
	mlx_string_put(data->mlx_data.mlx, data->mlx_data.win, 50, 130, 0, \
		"Move right: key bord right      Rotate Direction Change: 4");
	mlx_string_put(data->mlx_data.mlx, data->mlx_data.win, 50, 150, 0, \
		"Move front: U                   Rotate X Axis: X");
	mlx_string_put(data->mlx_data.mlx, data->mlx_data.win, 50, 170, 0, \
		"Move back: D                    Rotate Y Axis: Y");
	mlx_string_put(data->mlx_data.mlx, data->mlx_data.win, 50, 190, 0, \
		"current object:                 Rotate Z Axis: Z");
	mlx_string_put(data->mlx_data.mlx, data->mlx_data.win, 145, 190, 0, \
		data->object_name);
	mlx_string_put(data->mlx_data.mlx, data->mlx_data.win, 242, 210, 0, \
		"Rotate Direction: ");
	mlx_string_put(data->mlx_data.mlx, data->mlx_data.win, 347, 210, 0, \
		data->rotate_dir);
}

void	moving_origin(t_vec3 *origin, int key)
{
	if (key == KEY_DOWN)
		origin->y = origin->y - 1.0;
	else if (key == KEY_UP)
		origin->y = origin->y + 1.0;
	else if (key == KEY_LEFT)
		origin->x = origin->x + 1.0;
	else if (key == KEY_RIGHT)
		origin->x = origin->x - 1.0;
	else if (key == KEY_GO)
		origin->z = origin->z + 1.0;
	else if (key == KEY_BACK)
		origin->z = origin->z - 1.0;
}

void	object_moving(t_scene *data, int key)
{
	t_object	*obj;
	t_sphere	*sp;
	t_plane		*pl;
	t_cylinder	*cy;

	obj = (t_object *)data->now;
	if (obj->type == SP)
	{
		sp = (t_sphere *)obj->element;
		moving_origin(&sp->center, key);
		data->object_name = "SP";
	}
	else if (obj->type == PL)
	{
		pl = (t_plane *)obj->element;
		moving_origin(&pl->point, key);
		data->object_name = "PL";
	}
	else if (obj->type == CY)
	{
		cy = (t_cylinder *)obj->element;
		moving_origin(&cy->center, key);
		data->object_name = "CY";
	}
}

void	data_change(t_scene *data, int key)
{
	t_light	*temp;

	if (data->now == &data->camera)
	{
		moving_origin(&data->camera.orig, key);
		data->camera.left_bottom = two_vec_minus(two_vec_minus \
			(two_vec_minus(data->camera.orig, \
				vec_div(data->camera.horizontal, 2)), \
				vec_div(data->camera.vertical, 2)), \
				vec_mult(data->camera.cam_dir, -data->camera.focal_len));
	}
	else if (data->now == data->light)
	{
		temp = data->light->element;
		moving_origin(&temp->origin, key);
	}
	else
		object_moving(data, key);
}

t_bool	now_hook_utils(t_scene *data, int keycode)
{
	static int	i = 0;

	if (keycode == ONE)
	{
		data->now = &data->camera;
		data->object_name = "Camera";
		return (TRUE);
	}
	else if (keycode == TWO)
	{
		data->now = data->light;
		data->object_name = "Light";
		return (TRUE);
	}
	else if (keycode == FOUR)
	{
		if (i++ == 0)
			data->rotate_dir = "Right";
		else
		{
			data->rotate_dir = "Left";
			i = 0;
		}
	}
	return (FALSE);
}
