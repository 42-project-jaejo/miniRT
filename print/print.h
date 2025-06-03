/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:45:26 by jaejo             #+#    #+#             */
/*   Updated: 2025/06/02 23:20:02 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# include <stdio.h>
# include "../types.h"

int     write_color(t_color3 pixel_color);
void    print_image(t_scene *scene, t_mlx *data);
void    my_mlx_pixel_put(t_mlx *data, int x, int y, int color);

#endif