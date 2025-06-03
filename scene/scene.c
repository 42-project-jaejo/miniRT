/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsch <seungsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 20:00:23 by jaejo             #+#    #+#             */
/*   Updated: 2025/06/03 23:12:05 by seungsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./scene.h"

void	mlx_create(t_mlx *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window (data->mlx, 1920, 1080, "mini_rt"); 
	data->img = mlx_new_image(data->mlx, 1920, 1080);
	data->img_addr = mlx_get_data_addr(data->img, &data->bpp, \
											&data->width, &data->endian);
}

t_canvas	canvas(int width, int height)
{
	t_canvas	canvas;

	canvas.width = width;
	canvas.height = height;
	canvas.aspect_ratio = (double)width / (double)height;
	return (canvas);
}

void	scene_init(t_scene *scene, int	fd, t_mlx *mlx_data)
{
	t_object	*world;
	t_object	*lights;
	char		*data;
	char		**data_split;
	double		R = cos(M_PI / 4);

	mlx_create(mlx_data);
	scene->canvas = canvas(1920, 1080);
	data = get_next_line(fd);
	data_split = ft_split(data, ' ');
	while (data)
	{
		free(data);
		if (!ft_strncmp(data_split[0], "C", 2))
			scene->camera = ft_camera_init(&scene->canvas, data_split);
		else if (!ft_strncmp(data_split[0], "L", 2))
			scene->light = ft_light_intit(data_split);
		else if (!ft_strncmp(data_split[0], "A", 2))
			scene->ambient = vec_mult(ft_char_to_vec(data_split[2]), ft_strtod(data_split[1], 0));
		else if (!ft_strncmp(data_split[0], "cy", 2))
			object_add(&world, ft_cy_init(data_split));
		else if (!ft_strncmp(data_split[0], "pl", 2))
			object_add(&world, ft_pl_init(data_split));
		else if (!ft_strncmp(data_split[0], "sp", 3))
			object_add(&world, ft_sp_init(data_split));
		split_free(data_split);
		data = get_next_line(fd);
		if (!data)
			break ;
		data_split = ft_split(data, ' ');
	}
	scene->world = world;
}
