/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 20:13:33 by jaejo             #+#    #+#             */
/*   Updated: 2025/06/09 21:32:32 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOK_H
# define HOOK_H

# include "../types.h"
# include "../free/free.h"
# include "../vec/vec_utils.h"
# include "../print/print.h"
# include "../minilibx-linux/mlx.h"

/* hool_list.c */
int		x_hook(t_scene *data);
int		key_hook(int keycode, t_scene *data);
/* hook_utils.c */
void	put_string(t_scene *data);
void	object_moving(t_scene *data, int key);
void	moving_origin(t_vec3 *origin, int key);
void	data_change(t_scene *data, int key);
t_bool	now_hook_utils(t_scene *data, int keycode);
/* hook_rotate.c */
void	camera_rotate(t_scene *data, int key, double radian);
t_vec3	rotate_xyz(t_vec3 vec, double radian, int key);

#endif