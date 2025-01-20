/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_con_tohex_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 08:57:35 by honnguye          #+#    #+#             */
/*   Updated: 2025/01/18 23:53:46 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	ft_loworcap(char x);
static int	ft_hex_len(unsigned long n);

// This function takes an unsigned long integer
// Returns an array of chars in hexadecimal wo prefix
// Terminates the string with null char
// Need to be freed
char	*ft_ultohex_a(unsigned long num, char x)
{
	char	*buff;
	int		i;
	int		len;
	int		bt;

	len = ft_hex_len(num);
	buff = (char *)malloc(sizeof(char) * (len + 1));
	if (!buff)
		return (NULL);
	i = len + 1;
	buff[i] = '\0';
	while (i > 0)
	{
		i--;
		bt = num & 0xF;
		if (bt < 10)
			buff[i] = '0' + bt;
		else
			buff[i] = ft_loworcap(x) + (bt - 10);
		num >>= 4;
	}
	return (buff);
}

static int	ft_hex_len(unsigned long n)
{
    int	len;

    len = 1;
    while (n >= 16)
    {
        n = n / 16;
        len++;
    }
    return (len);
}

// This function takes a pointer as an argument
// Returns a converted pointer to unsigned long
unsigned long	ft_ptoul(void *p)
{
	unsigned long	num;

	num = (unsigned long) p;
	return (num);
}

// Determines in which format to store the hex
// Lower or capital case
static char	ft_loworcap(char x)
{
	if (x == 'x')
		return ('a');
	else
		return ('A');
}
