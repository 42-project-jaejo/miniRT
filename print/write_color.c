/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:50:50 by jaejo             #+#    #+#             */
/*   Updated: 2025/06/04 21:07:47 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./print.h"

static int	create_trgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img_addr + (y * data->width + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int	write_color(t_color3 pixel_color)
{
	int	r;
	int	g;
	int	b;

	r = (int)(255.999 * pixel_color.x);
	g = (int)(255.999 * pixel_color.y);
	b = (int)(255.999 * pixel_color.z);
	return (create_trgb(r, g, b));
}
