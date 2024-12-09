/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 20:01:08 by honnguye          #+#    #+#             */
/*   Updated: 2024/12/08 22:24:47 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <sys/stat.h>
# include <fcntl.h>

# ifdef BUFFER_SIZE
#  if BUFFER_SIZE < 1
#   error "Your BUFFER_SIZE must not be less than 1"
#  elif BUFFER_SIZE > 100000000
#   error "Your BUFFER_SIZE is too big, the program would not work properly"
#  endif
# else
#  define BUFFER_SIZE 12
# endif

# ifdef MAX_FD
#  if MAX_FD < 3
#   error "Your redefinition of FD must be at least 3"
#  elif MAX_FD > 1024
#   error "your redefinition of FD must not exceed the 1024 limit"
#  endif
# else
#  define MAX_FD 24
# endif

char	*get_next_line(int fd);
char	*ft_chrstr(char *str, char c);
size_t	ft_gnl_strlen(char *str, char c);
char	*ft_gnl_append(char *src, char *apnd_str);
void	ft_buffer_handler(char *buff);
size_t	ft_gnl_strcpy(char *dst, char *src);
char	*ft_read_line(char *line, char *buffer, int fd);
void	ft_bzero(char *s, size_t n);

#endif