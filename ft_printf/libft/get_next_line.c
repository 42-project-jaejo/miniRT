/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:52:29 by jaejo             #+#    #+#             */
/*   Updated: 2025/04/16 18:03:20 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_gnl_join(char *s1, char *s2)
{
	char	*temp;
	int		i;
	int		j;

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
	if (s1)
		free(s1);
	return (temp);
}

static char	*ft_only_read(int fd, char *buf, char *backup, int *i)
{
	while (1)
	{
		*i = read(fd, buf, BUFFER_SIZE);
		if (*i == -1)
			return (free(backup), free(buf), NULL);
		if (*i == 0)
			break ;
		buf[*i] = '\0';
		backup = ft_gnl_join(backup, buf);
		if (!backup)
			return (NULL);
		if (ft_gnlcheck(backup))
			break ;
	}
	return (backup);
}

static char	*ft_line(char *backup)
{
	int		i;
	char	*line;

	i = 0;
	line = (char *)malloc(sizeof(char) * ft_gnlnlen(backup) + 1);
	if (!line)
		return (free(backup), NULL);
	while (backup[i] && backup[i] != '\n')
	{
		line[i] = backup[i];
		i++;
	}
	if (backup[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	if (line[0] == '\0')
		return (free(line), NULL);
	return (line);
}

static char	*ft_backup(char *str, int *readlen)
{
	int		i;
	int		j;
	char	*temp;

	j = 0;
	i = ft_gnlcheck(str);
	if ((*readlen == 0 && !*str) || i == 0)
		return (free(str), NULL);
	if (!str)
		return (NULL);
	temp = (char *)malloc(sizeof(char) * ft_strlen(&str[i]) + 1);
	if (!temp)
		return (NULL);
	while (str[i + j])
	{
		temp[j] = str[i + j];
		j++;
	}
	temp[j] = '\0';
	free(str);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	int			readlen;
	char		*buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	if (!backup)
	{
		backup = (char *)malloc(sizeof(char));
		*backup = '\0';
	}
	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	backup = ft_only_read(fd, buf, backup, &readlen);
	if (!backup)
		return (NULL);
	free(buf);
	line = ft_line(backup);
	if (!line)
		return (free(backup), backup = NULL, NULL);
	backup = ft_backup(backup, &readlen);
	return (line);
}
