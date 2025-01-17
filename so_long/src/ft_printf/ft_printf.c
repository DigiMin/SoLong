/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:28:50 by honnguye          #+#    #+#             */
/*   Updated: 2025/01/17 11:11:20 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_specifier_handeler(char format, va_list a);

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	ssize_t	ret;
	ssize_t	spec_ret;

	ret = 0;
	va_start(ap, format);
	if (!format)
		return (ret);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			spec_ret = ft_specifier_handeler(*format, ap);
			if (spec_ret == -1)
				return (spec_ret);
			else
				ret += spec_ret;
		}
		else
			ret += ft_wchar(*format);
		format++;
	}
	va_end(ap);
	return (ret);
}

static int	ft_specifier_handeler(char format, va_list a)
{
	size_t	ret;

	ret = 0;
	if (format == 'c')
		ret += ft_wchar((char)va_arg(a, int));
	else if (format == 's')
		ret += ft_wstr(va_arg(a, char *));
	else if (format == 'd' || format == 'i')
		ret += ft_wdec(va_arg(a, int));
	else if (format == 'u')
		ret += ft_wudec(va_arg(a, unsigned int));
	else if (format == 'p')
		ret += ft_wphex(va_arg(a, void *), 'x');
	else if (format == 'x' || format == 'X')
		ret += ft_wuihex(va_arg(a, unsigned long), format);
	else if (format == '%')
		ret += ft_wchar('%');
	else
		return (-1);
	return (ret);
}

// TODO: flags init function
// TODO_OPT: Error handling
// printf returns -1 if error
// or number of characters written in the terminal or undefined
// d = printf("%-2147483649c|end\n", c);
// printf("%d\n", d); 
// it just returns -1 it handles maximum -2147483647 
// returning of printf counter when exceeding an return int is undefined
// FLAGS:
// minus must be right after the % sign
// int	main(void)
// {
// 	char *str = "Hwllo BLA BAR BUZ";
// 	char c = 'H';
// 	int	ret;
// 	ft_printf("The string is: %s, the char is: %c\n", str, c);
// 	ft_printf("\nCHAR TESTS\n");
// 	ret = printf("%c\n", '0');
// 	printf("RETRUN VAL: %u\n", ret);
// 	ret = ft_printf("%c\n", '0');
// 	printf("RETRUN VAL: %u\n", ret);
// 	ret = printf(" %c\n", '0' - 256);
// 	printf("RETRUN VAL: %u\n", ret);
// 	ret = ft_printf(" %c\n", '0' - 256);
// 	printf("RETRUN VAL: %u\n", ret);
// 	ret = printf(" %c %c %c \n", '0', 0, '1');
// 	printf("RETRUN VAL: %u\n", ret);
// 	ret = ft_printf(" %c %c %c \n", '0', 0, '1');
// 	printf("RETRUN VAL: %u\n", ret);
// 	ret = printf(" %c %c %c \n", '2', '1', 0);
// 	printf("RETRUN VAL: %u\n", ret);
// 	ret = ft_printf(" %c %c %c \n", '2', '1', 0);
// 	printf("RETRUN VAL: %u\n", ret);
// 	ret = printf(" %c %c %c \n", 0, '1', '2');
// 	printf("RETRUN VAL: %u\n", ret);
// 	ret = ft_printf(" %c %c %c \n", 0, '1', '2');
// 	printf("RETRUN VAL: %u\n", ret);
// 	ft_printf("\nSTRING TESTS\n");
// 	ret = printf("%s|empty\n", "");
// 	printf("RETRUN VAL: %u\n", ret);
// 	ret = ft_printf("%s|empty\n", "");
// 	printf("RETRUN VAL: %u\n", ret);
// 	ret = printf(" %s|empty\n", "");
// 	printf("RETRUN VAL: %u\n", ret);
// 	ret = ft_printf(" %s|empty\n", "");
// 	printf("RETRUN VAL: %u\n", ret);
// 	ret = printf(" %s %s %s %s %s\n", " - ", "", "4", "", str);
// 	printf("RETRUN VAL: %u\n", ret);
// 	ret = ft_printf(" %s %s %s %s %s\n", " - ", "", "4", "", str);
// 	printf("RETRUN VAL: %u\n", ret);
// 	ret = printf(" NULL %s NULL \n", NULL);
// 	// NULL (null) NULL 
// 	printf("RETRUN VAL: %u\n", ret);
// 	ret = ft_printf(" NULL %s NULL \n", NULL);
// 	printf("RETRUN VAL: %u\n", ret);
// 	ft_printf("\nINT AND UINT TESTS\n");
// 	ret = printf(" %d %d %d %d %d %d %d\n", \
// INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
// 	printf("RETRUN VAL: %u\n", ret);
// 	ret = ft_printf(" %d %d %d %d %d %d %d\n", \
// INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
// 	printf("RETRUN VAL: %u\n", ret);
// 	ret = printf(" %i %i %i %i %i %i %i\n", \
// INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
// 	printf("RETRUN VAL: %u\n", ret);
// 	ret = ft_printf(" %i %i %i %i %i %i %i\n", \
// INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
// 	printf("RETRUN VAL: %u\n", ret);
// 	ret = printf("Value of ul: %u\n", UINT_MAX);
// 	printf("RETRUN VAL: %u\n", ret);
// 	ret = ft_printf("Value of ul: %u\n", UINT_MAX);
// 	printf("RETRUN VAL: %u\n", ret);
// 	ret = printf("Value of ul: %u\n", INT_MIN);
// 	printf("RETRUN VAL: %u\n", ret);
// 	ret = ft_printf("Value of ul: %u\n", INT_MIN);
// 	printf("RETRUN VAL: %u\n", ret);
// 	ret = printf(" %u %u %u %u %u %u %u\n", \
// INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
// 	printf("RETRUN VAL: %u\n", ret);
// 	ret = ft_printf(" %u %u %u %u %u %u %u\n", \
// INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
// 	printf("RETRUN VAL: %u\n", ret);
// 	ft_printf("\nPOINTER TESTS\n");
// 	ret = printf(" %p %p \n", -1, 10);
// 	printf("RETRUN VAL: %u\n", ret);
// 	ret = ft_printf(" %p %p \n", -1, 10);
// 	printf("RETRUN VAL: %u\n", ret);
// 	ret = printf(" %p %p \n", NULL, NULL);
// 	printf("RETRUN VAL: %u\n", ret);
// 	ret = ft_printf(" %p %p \n", NULL, NULL);
// 	printf("RETRUN VAL: %u\n", ret);
// 	ret = printf(" %p %p \n", 0, 0);
// 	printf("RETRUN VAL: %u\n", ret);
// 	ret = ft_printf(" %p %p \n", 0, 0);
// 	printf("RETRUN VAL: %u\n", ret);
// 	ret = printf("Pointer: %p\n", str);
// 	printf("RETRUN VAL: %u\n", ret);
// 	ret = ft_printf("Pointer: %p\n", str);
// 	printf("RETRUN VAL: %u\n", ret);
// 	ret = printf("Pointer: %p\n", &c);
// 	printf("RETRUN VAL: %u\n", ret);
// 	ret = ft_printf("Pointer: %p\n", &c);
// 	printf("RETRUN VAL: %u\n", ret);
// 	ft_printf("\nHEX TESTS\n");
// 	ret = printf(" %x \n", 0);
// 	printf("RETRUN VAL: %u\n", ret);
// 	ret = ft_printf(" %x \n", 0);
// 	printf("RETRUN VAL: %u\n", ret);
// 	ret = printf(" %x \n", LONG_MAX);
// 	printf("RETRUN VAL: %u\n", ret);
// 	ret = ft_printf(" %x \n", LONG_MAX);
// 	printf("RETRUN VAL: %u\n", ret);
// 	ret = printf(" %x \n", LONG_MIN);
// 	printf("RETRUN VAL: %u\n", ret);
// 	ret = ft_printf(" %x \n", LONG_MIN);
// 	printf("RETRUN VAL: %u\n", ret);
// 	ret = printf(" %x \n", ULONG_MAX);
// 	printf("RETRUN VAL: %u\n", ret);
// 	ret = ft_printf(" %x \n", ULONG_MAX);
// 	printf("RETRUN VAL: %u\n", ret);
// 	ret = printf(" %x \n", 9223372036854775807LL);
// 	printf("RETRUN VAL: %u\n", ret);
// 	ret = ft_printf(" %x \n", 9223372036854775807LL);
// 	printf("RETRUN VAL: %u\n", ret);
// 	ret = printf(" %x %x %x %x %x %x %x\n", \
// INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
// 	printf("RETRUN VAL: %u\n", ret);
// 	ret = ft_printf(" %x %x %x %x %x %x %x\n", \
// INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
// 	printf("RETRUN VAL: %u\n", ret);
// 	ret = printf("HEX: %X\n", INT_MIN);
// 	printf("RETRUN VAL: %u\n", ret);
// 	ret = ft_printf("HEX: %X\n", INT_MIN);	
// 	printf("RETRUN VAL: %u\n", ret);
// 	ret = printf("hex: %x\n", INT_MIN);
// 	printf("RETRUN VAL: %u\n", ret);
// 	ret = ft_printf("hex: %x\n", INT_MIN);
// 	printf("RETRUN VAL: %u\n", ret);
// 	ret = printf("HEX: %X\n", UINT_MAX);
// 	printf("RETRUN VAL: %u\n", ret);
// 	ret = ft_printf("HEX: %X\n", UINT_MAX);	
// 	printf("RETRUN VAL: %u\n", ret);
// 	ret = printf("hex: %x\n", UINT_MAX);
// 	printf("RETRUN VAL: %u\n", ret);
// 	ret = ft_printf("hex: %x\n", UINT_MAX);
// 	printf("RETRUN VAL: %u\n", ret);
// 	ft_printf("\n'%%' TESTS\n");
// 	ret = printf(" %%%% \n");
// 	printf("RETRUN VAL: %u\n", ret);
// 	ret = ft_printf(" %%%% \n");
// 	printf("RETRUN VAL: %u\n", ret);
// 	ret = printf("%%\n");
// 	printf("RETRUN VAL: %u\n", ret);
// 	ret = ft_printf("%%\n");
// 	printf("RETRUN VAL: %u\n", ret);
// 	ret = printf("%% %%\n");
// 	printf("RETRUN VAL: %u\n", ret);
// 	ret = ft_printf("%% %%\n");
// 	printf("RETRUN VAL: %u\n", ret);
// 	ft_printf("\nWHAT THE HEX TESTS\n");
// 	ret = printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% \
// %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n",\
//  'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", \
// -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
// 	printf("RETRUN VAL: %u\n", ret);
// 	ret = ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% \
// %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n",\
//  'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", \
// -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
// 	printf("RETRUN VAL: %u\n", ret);
// }
