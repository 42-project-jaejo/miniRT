/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:26:53 by jaejo             #+#    #+#             */
/*   Updated: 2025/06/10 20:39:20 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int ac, char **av)
{
	t_scene	scene;

	file_init(&scene, ac, av[1], &scene.mlx_data);
	print_image(&scene, &scene.mlx_data);
	mlx_put_image_to_window(scene.mlx_data.mlx, scene.mlx_data.win, \
		scene.mlx_data.img, 0, 0);
	put_string(&scene);
	mlx_key_hook(scene.mlx_data.win, key_hook, &scene);
	mlx_hook(scene.mlx_data.win, 17, 0, x_hook, &scene);
	mlx_loop(scene.mlx_data.mlx);
	return (0);
}
