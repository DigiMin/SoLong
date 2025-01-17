/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:40:56 by honnguye          #+#    #+#             */
/*   Updated: 2025/01/17 11:42:28 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

void	ft_draw_numbers(t_graphics *graphics)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		graphics->numbers[i] = ft_draw_number(graphics, i);
		i++;
	}
}