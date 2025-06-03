/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 23:04:26 by jaejo             #+#    #+#             */
/*   Updated: 2024/10/05 23:41:37 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*temp;
	size_t	i;

	i = 0;
	if (!s || !f)
		return (0);
	temp = (char *)malloc (sizeof(char) * (ft_strlen(s) + 1));
	if (temp == 0)
		return (NULL);
	while (s[i])
	{
		temp[i] = f(i, s[i]);
		i++;
	}
	temp[i] = '\0';
	return (temp);
}
