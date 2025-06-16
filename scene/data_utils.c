/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsch <seungsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 21:16:25 by jaejo             #+#    #+#             */
/*   Updated: 2025/06/17 03:18:17 by seungsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./scene.h"

t_vec3	ft_char_to_vec(char *data)
{
	t_vec3	vec;
	char	**split;

	split = ft_split(data, ',');
	vec.x = ft_strtod(split[0], 0);
	vec.y = ft_strtod(split[1], 0);
	vec.z = ft_strtod(split[2], 0);
	split_free(split);
	return (vec);
}

t_vec3	ft_trance_rgb(t_vec3 rgb)
{
	t_vec3	trance_rgb;

	trance_rgb.x = rgb.x / 255.0;
	trance_rgb.y = rgb.y / 255.0;
	trance_rgb.z = rgb.z / 255.0;
	return (trance_rgb);
}

t_bool	cam_direction_setting(t_camera *cam, t_vec3 cam_dir)
{
	if ((cam_dir.x && !cam_dir.y && !cam_dir.z) || \
		(!cam_dir.x && !cam_dir.y && cam_dir.z))
	{
		if (cam)
			cam->vec_up = vec3(0, 1, 0);
		return (TRUE);
	}
	else if (!cam_dir.x && cam_dir.y && !cam_dir.z)
	{
		if (cam)
			cam->vec_up = vec3(0, 0, 1);
		return (TRUE);
	}
	return (FALSE);
}
