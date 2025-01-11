/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 08:50:54 by honnguye          #+#    #+#             */
/*   Updated: 2024/12/08 22:12:26 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Finds a character in the string
// returns a pointer that points to the char c
char	*ft_chrstr(char *str, char c)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == c)
			return (str);
		str++;
	}
	return (NULL);
}

// returns the length until character is found, character included
// or null terminator is found, terminator excluded
size_t	ft_gnl_strlen(char *str, char c)
{
	size_t	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i])
	{
		if (str[i] == c)
			return (++i);
		i++;
	}
	return (i);
}

// while src exist copy it to dst
// do not null terminate
size_t	ft_gnl_strcpy(char *dst, char *src)
{
	size_t	i;

	i = 0;
	if (!src || !dst)
		return (i);
	while (src[i])
	{
		dst[i] = src[i];
		if (src[i] == '\n')
			return (++i);
		i++;
	}
	return (i);
}

// If there is nothing in the buffer just return
// else copy the remainder string after newline to the beginning
void	ft_buffer_handler(char *buff)
{
	size_t	start;
	size_t	i;

	if (!*buff)
		return ;
	start = ft_gnl_strlen(buff, '\n');
	i = 0;
	while (start <= BUFFER_SIZE)
		buff[i++] = buff[start++];
}

// set the n bytes to zero
void	ft_bzero(char *s, size_t n)
{
	size_t	i;

	i = 0;
	if (!s || !n)
		return ;
	while (i < n)
	{
		s[i] = '\0';
		i++;
	}
}
