/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsch <seungsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 19:58:13 by jaejo             #+#    #+#             */
/*   Updated: 2025/06/17 03:17:57 by seungsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "../minilibx-linux/mlx.h"
# include "../types.h"
# include "../free/free.h"
# include "../vec/vec_utils.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

/* file_check_utils.c */
int			split_size(char **split);
char		**minirt_data(int fd);
double		ft_strtod(char *str, int i);
t_bool		object_data_check(char *data, int *flag, int size);
/* file_data_check.c */
t_bool		file_data_check(int fd);
/* file_init.c */
void		file_init(t_scene *scene, int ac, char *file, t_mlx *data);
/* data_init.c */
t_object	*ft_sp_init(char **data);
t_object	*ft_cy_init(char **data);
t_object	*ft_pl_init(char **data);
t_object	*ft_light_intit(char **data);
t_camera	ft_camera_init(t_canvas *canvas, char **data);
/* data_utils.c */
t_vec3		ft_char_to_vec(char *data);
t_vec3		ft_trance_rgb(t_vec3 rgb);
t_bool		cam_direction_setting(t_camera *cam, t_vec3 cam_dir);
/* scene.c */
void		scene_init(t_scene *scene, char *file, t_mlx *mlx_data);
/* object_create.c */
t_sphere	*sphere_init(t_vec_point3 center, double radius);
t_plane		*plane_init(t_vec_point3 point, t_vec3 dir);
t_object	*object_init(t_object_type type, void *element, t_color3 albedo);
t_cylinder	*cylinder_init(t_vec_point3 center, t_vec3 normal, double radius,
				double height);
t_light		*light_point(t_vec_point3 light_origin, t_color3 light_color,
				double bright_ratio);
/* object_utils.c */
void		object_add(t_object **list, t_object *new);
t_object	*object_last(t_object *list);

#endif