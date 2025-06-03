/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsch <seungsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 23:15:15 by jaejo             #+#    #+#             */
/*   Updated: 2025/06/04 00:25:52 by seungsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../trace/trace.h"
#include "./print.h"

void	print_image(t_scene *scene, t_mlx *data)
{
	int			i;
	int			j;
	double		u;
	double		v;
	t_color3	pixel_color;

	j = scene->canvas.height - 1;
	while (j >= 0)
	{
		i = 0;
		while (i < scene->canvas.width)
		{
			u = (double)i / (scene->canvas.width - 1);
			v = (double)j / (scene->canvas.height - 1);
			scene->ray = ray_primary(&scene->camera, u, v);
			pixel_color = ray_color(scene);
			my_mlx_pixel_put(data, i, scene->canvas.height - j,
				write_color(pixel_color));
			++i;
		}
		--j;
	}
}
