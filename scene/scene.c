/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 20:00:23 by jaejo             #+#    #+#             */
/*   Updated: 2025/06/02 23:13:46 by jaejo            ###   ########.fr       */
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

t_camera	camera(t_canvas *canvas, t_vec_point3 orig)
{
	t_camera	cam;
	double		focal_len;
	double		viewport_height;

	viewport_height = 2.0;
	focal_len = 1.0;
	cam.orig = orig;
	cam.viewport_h = viewport_height;
	cam.viewport_w = viewport_height * canvas->aspect_ratio;
	cam.focal_len = focal_len;
	cam.horizontal = vec3(cam.viewport_w, 0, 0);
	cam.vertical = vec3(0, cam.viewport_h, 0);
	cam.left_bottom = two_vec_minus(two_vec_minus(two_vec_minus(cam.orig, \
		vec_div(cam.horizontal, 2)), vec_div(cam.vertical, 2)), \
		vec3(0, 0, focal_len));
	return (cam);
}

void	scene_init(t_scene *scene, int	fd, t_mlx *data)
{
	t_object	*world;
	t_object	*lights;
	double		ka;

	(void)fd;
	mlx_create(data);
	scene->canvas = canvas(1920, 1080);
	scene->camera = camera(&scene->canvas, vec_point3(0, 0, 1));
	world = object_init(SP, sphere_init(vec_point3(-2, 0, -5), 2), color3(0.5, 0, 0));
    object_add(&world, object_init(SP, sphere_init(vec_point3(2, 0, -5), 2), color3(0, 0.5, 0)));
    object_add(&world, object_init(SP, sphere_init(vec_point3(0, -1000, 0), 990), color3(1, 1, 1)));
	scene->world = world;
	lights = object_init(LIGHT_POINT, light_point(vec_point3(0, 5, 0), color3(1, 1, 1), 0.5), color3(0, 0, 0));
	scene->light = lights;
	ka = 0.1;
	scene->ambient = vec_mult(color3(1, 1, 1), ka);
}
