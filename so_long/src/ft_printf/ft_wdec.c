/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wdec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 08:45:46 by honnguye          #+#    #+#             */
/*   Updated: 2024/10/24 12:00:59 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_wdec(int n)
{
	int		len;
	char	*num;

	num = ft_itoa(n);
	if (!num)
		return (0);
	len = ft_strlen(num);
	ft_wstr(num);
	free(num);
	return (len);
}

int	ft_wudec(unsigned int n)
{
	int		len;
	char	*num;

	num = ft_uitoa(n);
	if (!num)
		return (0);
	len = ft_strlen(num);
	ft_wstr(num);
	free(num);
	return (len);
}

// int main(void)
// {
//     int n = -2147483648;
//     int ret;
//     ret = ft_wdec(n);
//     printf("%d", ret);
// }