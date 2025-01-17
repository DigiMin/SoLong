/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 20:08:31 by honnguye          #+#    #+#             */
/*   Updated: 2024/10/25 11:13:29 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_wstr(char *c)
{
	int		len;
	char	*n;

	if (c != NULL)
	{
		len = ft_strlen(c);
		if (!*c)
			return (len);
		write(STDOUT_FILENO, c, len);
	}
	else
	{
		n = "(null)";
		len = ft_strlen(n);
		write(STDOUT_FILENO, n, len);
	}
	return (len);
}

// int main(void)
// {
// 	char *str = "Hello World";
// 	int count = ft_wstr(str);
// 	printf("\n%d\n", count);
// 	int count1 = ft_wstr(NULL);
// 	printf("\n%d\n", count1);
// }