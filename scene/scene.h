/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 19:58:13 by jaejo             #+#    #+#             */
/*   Updated: 2025/06/02 23:13:19 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include <fcntl.h>
# include <stdio.h>
# include "../types.h"
# include "../vec/vec_utils.h"
# include "../minilibx-linux/mlx.h"

/* file_check_utils.c */
int			split_size(char **split);
char		**minirt_data(int fd);
double		ft_strtod(char *str, int i);
t_bool		object_data_check(char *data, int *flag, int size);
/* file_data_check.c */
t_bool		file_data_check(int fd);
/* file_init.c */
void		file_init(t_scene *scene, int ac, char *file, t_mlx *data);
/* scene.c */
void		scene_init(t_scene *scene, int	fd, t_mlx *data);
t_canvas	canvas(int width, int height);
t_camera	camera(t_canvas *canvas, t_vec_point3 origin);
/* object_create.c */
t_sphere	*sphere_init(t_vec_point3 center, double radius);
t_object	*object_init(t_object_type type, void *element, t_color3 albedo);
t_light     *light_point(t_vec_point3 light_origin, t_color3 light_color, double bright_ratio);
/* object_utils.c */
void        object_add(t_object **list, t_object *new);
t_object    *object_last(t_object *list);

#endif