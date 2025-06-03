/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsch <seungsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:45:26 by jaejo             #+#    #+#             */
/*   Updated: 2025/06/04 00:25:55 by seungsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# include "../types.h"
# include <stdio.h>

int		write_color(t_color3 pixel_color);
void	print_image(t_scene *scene, t_mlx *data);
void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color);

#endif