/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsch <seungsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 20:00:23 by jaejo             #+#    #+#             */
/*   Updated: 2025/06/17 01:36:14 by seungsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./scene.h"

static void	mlx_create(t_mlx *data, int withd, int heigh)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, withd, heigh, "mini_rt");
	data->img = mlx_new_image(data->mlx, withd, heigh);
	data->img_addr = mlx_get_data_addr(data->img, &data->bpp, &data->width,
			&data->endian);
}

static t_canvas	canvas(int width, int height)
{
	t_canvas	canvas;

	canvas.width = width;
	canvas.height = height;
	canvas.aspect_ratio = (double)width / (double)height;
	return (canvas);
}

static void	scene_data_init(t_scene *scene, char *data, \
	char **data_split, int fd)
{
	t_object	*world;

	world = NULL;
	while (data)
	{
		free(data);
		if (!ft_strncmp(data_split[0], "C", 2))
			scene->camera = ft_camera_init(&scene->canvas, data_split);
		else if (!ft_strncmp(data_split[0], "L", 2))
			scene->light = ft_light_intit(data_split);
		else if (!ft_strncmp(data_split[0], "A", 2))
			scene->ambient = vec_mult(ft_trance_rgb \
				(ft_char_to_vec(data_split[2])), ft_strtod(data_split[1], 0));
		else if (!ft_strncmp(data_split[0], "cy", 2))
			object_add(&world, ft_cy_init(data_split));
		else if (!ft_strncmp(data_split[0], "pl", 2))
			object_add(&world, ft_pl_init(data_split));
		else if (!ft_strncmp(data_split[0], "sp", 3))
			object_add(&world, ft_sp_init(data_split));
		split_free(data_split);
		data = get_next_line(fd);
		if (data)
			data_split = ft_split(data, ' ');
	}
	scene->world = world;
}

void	scene_init(t_scene *scene, char *file, t_mlx *mlx_data)
{
	int			fd;
	char		*data;
	char		**data_split;

	fd = open(file, O_RDONLY);
	scene->canvas = canvas(1280, 900);
	mlx_create(mlx_data, scene->canvas.width, scene->canvas.height);
	data = get_next_line(fd);
	data_split = ft_split(data, ' ');
	scene_data_init(scene, data, data_split, fd);
	scene->now = &scene->camera;
	scene->object_name = "Camera";
	scene->rotate_dir = "Left";
}
