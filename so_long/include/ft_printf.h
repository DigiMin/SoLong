/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:19:05 by honnguye          #+#    #+#             */
/*   Updated: 2025/01/18 23:49:03 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

int				ft_printf(const char *format, ...);
int				ft_strlen(char *c);
int				ft_wchar(char c);
int				ft_wstr(char *c);
char			*ft_itoa(int n);
char			*ft_uitoa(unsigned int n);
int				ft_wdec(int n);
int				ft_wudec(unsigned int n);
int				ft_wuihex(unsigned int n, char x);
int				ft_wphex(void *p, char x);
unsigned long	ft_ptoul(void *p);
char			*ft_ultohex_a(unsigned long num, char x);

#endif