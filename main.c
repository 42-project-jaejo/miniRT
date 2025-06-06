/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsch <seungsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:26:53 by jaejo             #+#    #+#             */
/*   Updated: 2025/06/06 19:06:46 by seungsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	x_hook(t_mlx *c_data)
{
	if (c_data->img)
		mlx_destroy_image(c_data->mlx, c_data->img);
	mlx_destroy_window(c_data->mlx, c_data->win);
	mlx_destroy_display(c_data->mlx);
	free(c_data->mlx);
	exit(0);
	return (0);
}

int	key_hook(int keycode, t_mlx *c_data)
{
	if (keycode == KEY_ESC)
		x_hook(c_data);
	return (0);
}

int	main(int ac, char **av)
{
	t_scene	scene;
	t_mlx	data;

	file_init(&scene, ac, av[1], &data);
	print_image(&scene, &data);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_hook(data.win, 17, 0, x_hook, &data);
	mlx_loop(data.mlx);
	return (0);
}
