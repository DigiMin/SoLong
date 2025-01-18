/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:40:56 by honnguye          #+#    #+#             */
/*   Updated: 2025/01/18 09:29:33 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

void	ft_draw_numbers(t_graphics *graphics)
{
	char	*c;
	int		i;

	i = 0;
	while (i < 10)
	{
		c = ft_itoa(i);
		graphics->numbers[i] = ft_draw_number(graphics, ft_multi_strjoin(3,
					"./graphics/UI/", c, ".png"));
		free(c);
		i++;
	}
}
