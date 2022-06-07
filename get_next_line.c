/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapanciu <dapanciu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 16:09:20 by dapanciu          #+#    #+#             */
/*   Updated: 2022/06/07 14:43:20 by dapanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>

static char	*ft_cut_line(char *line)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
	{
		free(line);
		return (NULL);
	}
	temp = (char *)malloc(sizeof(char) * (ft_strlen(line) - i + 1));
	if (!temp)
		return (NULL);
	i++;
	j = 0;
	while (line[i])
		temp[j++] = line[i++];
	temp[j] = '\0';
	free(line);
	return (temp);
}

static char *ft_read(int fd, char *str, char *buffer)
{
	ssize_t	line;

	line = 1;
	while (line > 0)
	{
		line = read(fd, buffer, BUFFER_SIZE);
		if (line == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[line] = '\0';
		str = ft_strjoin(str, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (str);
}

static char	*ft_get_line(char *line)
{
	int		i;
	char	*temp;

	i = 0;
	if (!line[i])
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	temp = (char *)malloc(sizeof(char) * (i + 2));
	if (!temp)
		return (NULL);
	i = -1;
	while (line[++i] && line[i] != '\n')
		temp[i] = line[i];
	if (line[i] == '\n')
	{
		temp[i] = line[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char *get_next_line(int fd)
{   
	static char *line_save[4096];
	char        *line;
	char        *buffer;

	if (BUFFER_SIZE <= 0)
		return (NULL); 
	if (fd < 0 || fd > 1024)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	line_save[fd] = ft_read(fd, line_save[fd], buffer);
	if (!line_save[fd])
		return (NULL);
	line = ft_get_line(line_save[fd]);
	line_save[fd] = ft_cut_line(line_save[fd]);
	free(buffer);
	return (line);
}