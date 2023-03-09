/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehubert <jehubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:20:37 by jehubert          #+#    #+#             */
/*   Updated: 2023/03/09 17:00:04 by jehubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	linelen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

char	*gnl_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	char	*scpy;

	scpy = &((char *)s)[start];
	if (len > gnl_strlen(scpy))
		len = gnl_strlen(scpy);
	sub = malloc((len + 1));
	if (!sub)
		return (NULL);
	gnl_strlcpy(sub, scpy, len + 1);
	return (sub);
}

char	*buf(int fd)
{
	char	*buf;
	int		size;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	size = read(fd, buf, BUFFER_SIZE);
	if (size < 1)
	{
		free(buf);
		return (NULL);
	}
	buf[size] = '\0';
	return (buf);
}

char	*cleanline(char *line)
{
	size_t	i;
	char	*new;

	i = 0;
	while (line[i] != '\n' && line[i])
		i++;
	if (i == gnl_strlen(line) || !line[i + 1])
	{
		free(line);
		return (NULL);
	}
	i++;
	new = gnl_substr(line, i, gnl_strlen(line) - i);
	if (!new)
	{
		free(line);
		return (NULL);
	}
	free(line);
	return (new);
}

char	*get_next_line(int fd, char *lim)
{
	static char	*line[4096];
	char		*buffer;
	int			i;

	if (fd < 0)
		return (NULL);
	if (line[fd])
		line[fd] = cleanline(line[fd]);
	buffer = NULL;
	while (gnl_strchr(line[fd], '\n') < 0)
	{
		buffer = buf(fd);
		if (!buffer)
			break ;
		line[fd] = gnl_strjoin(line[fd], buffer);
		if (!line[fd])
			return (NULL);
	}
	i = linelen(line[fd]);
	if (i < 0 || *line[fd] == '\0'
		|| !ft_strncmp(line[fd], lim, ft_strlen(line[fd]) - 1))
		return (free(line[fd]), NULL);
	return (gnl_substr(line[fd], 0, i + 1));
}
