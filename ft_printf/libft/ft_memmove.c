/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 18:00:46 by jaejo             #+#    #+#             */
/*   Updated: 2024/10/06 19:16:49 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dst;
	unsigned char	*src2;

	dst = (unsigned char *)dest;
	src2 = (unsigned char *)src;
	if (dest == src || n == 0)
		return (dest);
	if (dest < src)
	{
		i = 0;
		while (i < n)
		{
			dst[i] = src2[i];
			i++;
		}
	}
	else
	{
		i = n;
		while (i--)
			dst[i] = src2[i];
	}
	return (dst);
}
