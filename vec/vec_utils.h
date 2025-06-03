/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo < jaejo@student.42gyeongsan.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 21:21:00 by jaejo             #+#    #+#             */
/*   Updated: 2025/05/29 16:56:37 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_UTILS_H
# define VEC_UTILS_H

# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include "../types.h"

void			vec_set(t_vec3 *vec, double x, double y, double z);
double			square_vec(t_vec3 vec);
double			vec_length(t_vec3 vec);
double			vec_dot(t_vec3 vec, t_vec3 vec2);
t_vec3			vec_unit(t_vec3 vec);
t_vec3			vec_div(t_vec3 vec, double t);
t_vec3			vec_mult(t_vec3 vec, double t);
t_vec3			vec_min(t_vec3 vec1, t_vec3 vec2);
t_vec3			vec_cross(t_vec3 vec, t_vec3 vec2);
t_vec3			vec3(double x, double y, double z);
t_vec3			two_vec_mult(t_vec3 vec, t_vec3 vec2);
t_vec3			two_vec_plus(t_vec3 vec, t_vec3 vec2);
t_vec3			two_vec_minus(t_vec3 vec, t_vec3 vec2);
t_vec3			vec_plus(t_vec3 vec, double x, double y, double z);
t_vec3			vec_minus(t_vec3 vec, double x, double y, double z);
t_vec_point3	vec_point3(double x, double y, double z);
t_vec_point3	color3(double r, double g, double b);

#endif