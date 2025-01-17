/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_whex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:17:44 by honnguye          #+#    #+#             */
/*   Updated: 2024/10/26 12:34:07 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_whex_prefix(char x);
static int	ft_nullp_handler(void);

// This function takes an unsigned long
// and a char which determines the case of the printed hex
// Calls a conversion function, and print prefix function
// Return value is the count of chars printed
int	ft_wuihex(unsigned int n, char x)
{
	char	*hexul;
	int		i;
	int		len;

	i = 0;
	if (!n)
		return (ft_wchar('0'));
	hexul = ft_ultohex_a(n, x);
	if (!hexul)
		return (i);
	while (hexul[i] == '0')
		i++;
	len = ft_wstr(&hexul[i]);
	free(hexul);
	return (len);
}

int	ft_wphex(void *p, char x)
{
	char	*hexul;
	int		i;
	int		len;

	i = 0;
	if (!p)
		return (ft_nullp_handler());
	hexul = ft_ultohex_a(ft_ptoul(p), x);
	if (!hexul)
		return (i);
	while (hexul[i] == '0')
		i++;
	len = ft_whex_prefix(x) + ft_wstr(&hexul[i]);
	free(hexul);
	return (len);
}

static int	ft_nullp_handler(void)
{
	char	*n;

	n = "(nil)";
	ft_wstr(n);
	return (ft_strlen(n));
}

static int	ft_whex_prefix(char x)
{
	if (x != 'x' && x != 'X')
		return (0);
	ft_wchar('0');
	if (x == 'x')
		ft_wchar('x');
	else
		ft_wchar('X');
	return (2);
}
