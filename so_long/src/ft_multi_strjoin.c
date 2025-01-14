/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multi_strjoin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:59:28 by honnguye          #+#    #+#             */
/*   Updated: 2025/01/14 19:07:59 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

static char	*ft_strjoin(char *s1, char *s2);

/*
 * @brief Joins multiple strings together into a single string. The result needs to be freed after use.
 * 
 * This function uses `va_list` to handle a variable number of string arguments. The exact number of strings 
 * to join must be provided in the `count` parameter. If the provided count is incorrect undefined behavior may occur.
 * 
 * @param count The exact number of strings to join.
 * @param ...   A variable number of string arguments to join together.
 * 
 * @return A new string containing all the joined strings, or `NULL` if memory allocation fails or if both strings have
 *         `NULL` value.
 */
char	*ft_multi_strjoin(int count, ...)
{
	char	*new;
	char	*str;
	va_list	ap;

	va_start(ap, count);
	if (!count)
		return (NULL);
	if (count == 1)
		return (va_end(ap), va_arg(ap, char*));
	new = NULL;
	while (count)
	{
		str = va_arg(ap, char *);
		new = ft_strjoin(new, str);
		count--;
	}
	if (!new)
		return (va_end(ap), NULL);
	return (va_end(ap), new);
}

/*
 * @brief Joins two strings together into a new string. The result needs to be freed after use.
 * 
 * If memory allocation fails, the function returns `NULL`. If the first string (`s1`) exists, 
 * it will be freed before returning the new joined string. The resulting string is always null-terminated.
 * 
 * @param s1 The first string to join, may be `NULL`.
 * @param s2 The second string to join, may also be `NULL`.
 * 
 * @return A new string containing the result of joining `s1` and `s2`, or `NULL` if memory allocation fails.
 */
static char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	size_t	len1;
	size_t	len2;

	len1 = ft_gnl_strlen(s1, '\0');
	len2 = ft_gnl_strlen(s2, '\0');
	new = malloc((len1 + len2 + 1) * sizeof(char));
	if (!new && s1)
		return (free(s1), NULL);
	if (!new)
		return (NULL);
	new[len1 + len2] = '\0';
	while (s2 && len2 > 0)
	{
		len2--;
		new[len1 + len2] = s2[len2];
	}
	while (s1 && len1 > 0)
	{
		len1--;
		new[len1] = s1[len1];
	}
	if (s1)
		free(s1);
	return (new);
}
