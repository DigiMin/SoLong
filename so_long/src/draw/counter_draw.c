/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:40:56 by honnguye          #+#    #+#             */
/*   Updated: 2025/01/20 10:49:59 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

void	ft_draw_numbers(t_graphics **graphics)
{
	char	*c;
	char	*full_path;
	int		i;

	i = 0;
	while (i < 10)
	{
		c = ft_itoa(i);
		full_path = ft_multi_strjoin(3, "./graphics/UI/", c, ".png");
		(*graphics)->numbers[i] = ft_draw_number(graphics, full_path);
		free(c);
		free(full_path);
		i++;
	}
}
