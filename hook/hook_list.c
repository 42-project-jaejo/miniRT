/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 20:13:10 by jaejo             #+#    #+#             */
/*   Updated: 2025/06/06 22:28:09 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./hook.h"

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
	put_string(data);	
}

void    now_hook(t_scene *data, int keycode)
{
	static int i = -1;
	int			j;
	t_object	*temp;

	j = 0;
	temp = data->world;
	if (now_hook_utils(data, keycode))
		;
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
	moving_hook(keycode, data);
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