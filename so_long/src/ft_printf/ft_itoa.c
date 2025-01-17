/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 09:46:41 by honnguye          #+#    #+#             */
/*   Updated: 2024/10/24 11:57:19 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_intstrlen(int n);
static int	ft_uintstrlen(unsigned int n);

// based on linux manual a limit to an int is -2147483647
// but putting -2147483648 in doesn't give an error, so it should be considered
char	*ft_itoa(int n)
{
	char		*out;
	int			i;
	long long	num;

	num = n;
	i = ft_intstrlen(n);
	out = malloc(sizeof(char) * (i + 1));
	if (!out)
		return (NULL);
	out[i] = '\0';
	if (n < 0)
		num *= -1;
	while (i > 0)
	{
		out[--i] = (num % 10) + 48;
		num /= 10;
		if (n < 0 && i == 1)
			out[--i] = '-';
	}
	return (out);
}

char	*ft_uitoa(unsigned int n)
{
	char	*out;
	int		i;

	i = ft_uintstrlen(n);
	out = (char *)malloc((i + 1) * sizeof(char));
	if (!out)
		return (NULL);
	out[i] = '\0';
	while (i > 0)
	{
		out[--i] = (n % 10) + 48;
		n /= 10;
	}
	return (out);
}

static int	ft_intstrlen(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (++i);
	if (n < -999999999)
		return (11);
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n >= 1)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static int	ft_uintstrlen(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (++i);
	while (n >= 1)
	{
		n /= 10;
		i++;
	}
	return (i);
}

// int	main(void)
// {
// 	char *num_2 = ft_itoa(-2147483648);
// 	char *num_1 = ft_itoa(-1234567);
// 	char *num0 = ft_itoa(0);
// 	char *num1 = ft_itoa(1234567);
// 	char *num2 = ft_itoa(2147483647);
// 	// char *notint = ft_itoa(2147483648);
// 	printf("MIN negative:%s|end\n", num_2);
// 	printf("negative:%s|end\n", num_1);
// 	printf("zero:%s|end\n", num0);
// 	printf("positive:%s|end\n", num1);
// 	printf("MAX positive:%s|end\n", num2);
// 	// printf("MAX positive + 1:%s|end\n", notint);
// 	free(num_2);
// 	free(num_1);
// 	free(num0);
// 	free(num1);
// 	free(num2);
// }