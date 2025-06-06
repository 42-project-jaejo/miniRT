/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 20:13:10 by jaejo             #+#    #+#             */
/*   Updated: 2025/06/06 19:36:38 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./hook.h"

void   moving_origin(t_vec3 *origin, int key)
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
	}
	else if (obj->type == PL)
	{
		pl = (t_plane *)obj->element;
		moving_origin(&pl->point, key);
	}
	else if (obj->type == CY)
	{
		cy = (t_cylinder *)obj->element;
		moving_origin(&cy->center, key);
	}
}

void    data_change(t_scene *data, int key)
{
	t_light		*temp;
	
	if (data->now == &data->camera)
	{
		moving_origin(&data->camera.orig, key);
		data->camera.left_bottom = two_vec_minus(two_vec_minus(two_vec_minus(data->camera.orig,
			 vec_div(data->camera.horizontal, 2)), vec_div(data->camera.vertical, 2)),
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

int	x_hook(t_scene *data)
{
	if (data->mlx_data.img)
		mlx_destroy_image(data->mlx_data.mlx, data->mlx_data.img);
	mlx_destroy_window(data->mlx_data.mlx, data->mlx_data.win);
	mlx_destroy_display(data->mlx_data.mlx);
	free(data->mlx_data.mlx);
	list_free(data->world);
	free(data->light->element);
	free(data->light);
	exit(0);
	return (0);
}

void    moving_hook(int key, t_scene *data)
{
	mlx_destroy_image(data->mlx_data.mlx, data->mlx_data.img);
	data_change(data, key);
	data->mlx_data.img = mlx_new_image(data->mlx_data.mlx, 1920, 1080);
	data->mlx_data.img_addr = mlx_get_data_addr(data->mlx_data.img, \
		&data->mlx_data.bpp, &data->mlx_data.width, &data->mlx_data.endian);
	print_image(data, &data->mlx_data);
	mlx_put_image_to_window(data->mlx_data.mlx, data->mlx_data.win, \
		data->mlx_data.img, 0, 0);
}

void    now_hook(t_scene *data, int keycode)
{
	static int i = -1;
	int			j;
	t_object	*temp;

	j = 0;
	temp = data->world;
	if (keycode == ONE)
		data->now = &data->camera;
	else if (keycode == TWO)
		data->now = data->light;
	else if (keycode == THREE)
	{
		i++;
		while (temp && i > j++)
			temp = temp->next;
		if (temp)
			data->now = temp;
		else
		{
			data->now = data->world;
			i = 0;
		}
	}
}

int	key_hook(int keycode, t_scene *data)
{
	if (keycode == KEY_ESC)
		x_hook(data);
	else if (keycode == ONE || keycode == TWO || keycode == THREE)
		now_hook(data, keycode);
	else if (keycode == KEY_DOWN || keycode == KEY_UP || \
			keycode == KEY_RIGHT || keycode == KEY_LEFT || \
			keycode == KEY_GO || keycode == KEY_BACK)
		moving_hook(keycode, data);
	return (0);
}