/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:07:25 by jaejo             #+#    #+#             */
/*   Updated: 2024/10/15 21:04:12 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(char const *s, char c)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (*s)
	{
		if (*s == c)
			flag = 0;
		else if (flag == 0)
		{
			i++;
			flag = 1;
		}
		s++;
	}
	return (i);
}

static char	*ft_word(const char *s, char c)
{
	while (*s == c && *s)
		s++;
	return ((char *)s);
}

static int	ft_len(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static void	*ft_free(void **temp, int i)
{
	while (i)
	{
		free(temp[i - 1]);
		i--;
	}
	free(temp);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**temp;
	int		i;
	int		j;
	int		a;

	j = 0;
	a = ft_count(s, c);
	temp = (char **)malloc (sizeof(char *) * (a + 1));
	if (temp == NULL)
		return (NULL);
	temp[a] = NULL;
	while (j < a)
	{
		s = ft_word(s, c);
		i = ft_len(s, c);
		temp[j] = (char *)malloc (sizeof(char) * (i + 1));
		if (temp[j] == NULL)
			return (ft_free((void **)temp, j));
		temp[j][i] = '\0';
		i = 0;
		while (*(s) != c && *s)
			temp[j][i++] = *(s)++;
		j++;
	}
	return (temp);
}
