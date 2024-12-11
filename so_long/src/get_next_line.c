/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 20:02:47 by honnguye          #+#    #+#             */
/*   Updated: 2024/12/09 13:37:37 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	char		*n;
	static char	heads[MAX_FD][BUFFER_SIZE + 1];

	if (fd < 0 || fd >= MAX_FD)
		return (NULL);
	line = NULL;
	n = ft_chrstr(&heads[fd][0], '\n');
	if (heads[fd][0])
	{
		line = ft_gnl_append(line, &heads[fd][0]);
		if (!line)
			return (NULL);
		ft_buffer_handler(&heads[fd][0]);
	}
	if (!n)
	{
		line = ft_read_line(line, &heads[fd][0], fd);
		if (!line)
			return (NULL);
	}
	return (line);
}

char	*ft_read_line(char *line, char *buffer, int fd)
{
	ssize_t	bread;
	char	*n;

	bread = 1;
	n = NULL;
	while (!n && bread)
	{
		ft_bzero(buffer, BUFFER_SIZE + 1);
		bread = read(fd, buffer, BUFFER_SIZE);
		if (bread == 0)
			return (line);
		if (line && bread < 0)
		{
			free(line);
			line = NULL;
		}
		if (bread < 0)
			return (line);
		n = ft_chrstr(buffer, '\n');
		line = ft_gnl_append(line, buffer);
		if (!line)
			return (NULL);
	}
	ft_buffer_handler(buffer);
	return (line);
}

// append the string to the source string
// frees the source string
// returns the whole string until newline(included) due to ft_gnl_strlen
// or until null terminator(excluded)
char	*ft_gnl_append(char *src, char *apnd_str)
{
	char	*out;
	size_t	len;
	size_t	lsrc;

	if (!apnd_str && !src)
		return (NULL);
	lsrc = ft_gnl_strlen(src, '\n');
	len = lsrc + ft_gnl_strlen(apnd_str, '\n');
	out = (char *)malloc(sizeof(char) * (len + 1));
	if (!out)
	{
		if (src)
			free(src);
		return (NULL);
	}
	if (src)
		ft_gnl_strcpy(out, src);
	if (apnd_str)
		ft_gnl_strcpy(&out[lsrc], apnd_str);
	out[len] = '\0';
	if (src)
		free(src);
	return (out);
}
