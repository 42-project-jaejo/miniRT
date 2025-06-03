/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 20:06:21 by jaejo             #+#    #+#             */
/*   Updated: 2025/04/21 23:03:47 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*temp;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	temp = (char *)malloc (sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (temp == 0)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		temp[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		temp[i + j] = s2[j];
		j++;
	}
	temp[i + j] = '\0';
	return (temp);
}
