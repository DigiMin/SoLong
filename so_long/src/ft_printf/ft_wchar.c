/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 17:25:05 by honnguye          #+#    #+#             */
/*   Updated: 2024/10/25 09:54:49 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_wchar(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}

// int	main(void)
// {
// 	char c = 'A';
// 	char *b = "Hello";
// 	char *a = NULL;
// 	char n = '\n';
// 	int d = ft_wchar(&c);
// 	write(1, &n, 1);
// 	printf("%d\n", d);
// 	int e = ft_wchar(b);
// 	write(1, &n, 1);
// 	printf("%d\n", e);
// 	int f = ft_wchar(a);
// 	write(1, &n, 1);
// 	printf("%d\n", f);
// 	return EXIT_SUCCESS;
// }

// int	main(void)
// {
// 	char c = 'A';
// 	char *str = "Hello";
// 	int d;
// 	// possible char flags:
// 	d = printf("%c|end\n", c);
// 	printf("Return Value %d\n", d); 
// 	d = printf("%.c|end\n", c);
// 	printf("Return Value %d\n", d); 
// 	d = printf("%-10c|end\n", c);
// 	printf("Return Value %d\n", d); 
// 	d = printf("%-10.c|end\n", c);
// 	printf("Return Value %d\n", d); 
// 	d = printf("%10.c|end\n", c);
// 	printf("Return Value %d\n", d); 
// 	d = printf("%10c|end\n", c);
// 	printf("Return Value %d\n", d); 
// 	d = printf("%10c|end\n", str[2]);
// 	printf("Return Value %d\n", d); 
// 	// it just returns -1 it handles maximum 2147483647 flag
// 	// returning of printf counter when exceeding an return int is undefined
// 	d = printf("%-2147483649c|end\n", c);
// 	printf("%d\n", d); 
// 	// warnings of undefined behaviors:
// 	// printf("%0c|end\n", c);
// 	// printf("%.10c|end\n", c);
// 	// printf("%010c\n", c);
// 	// printf("%#10c\n", c);
// 	// printf("% c\n", c);
// 	// printf("%+c\n", c);
// 	// printf("% 10c\n", c);
// }