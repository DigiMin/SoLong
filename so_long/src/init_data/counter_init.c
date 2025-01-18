/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:45:22 by honnguye          #+#    #+#             */
/*   Updated: 2025/01/18 08:32:30 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

t_anim	**ft_set_counter(t_graphics *graphics)
{
	t_anim	**counter;
	int		i;

	ft_draw_numbers(graphics);
	counter = malloc(sizeof(t_anim *) * 6);
	if (!counter)
		return (NULL);
	i = 0;
	while (i < 6)
	{
		counter[i] = malloc(sizeof(t_anim));
		if (!counter[i])
			return (NULL);
		counter[i]->anim_count = 10;
		counter[i]->anim_frame = 0;
		counter[i]->anim_speed = 0;
		counter[i]->sleep = 0;
		counter[i]->enabled = 1;
		counter[i]->anim_images = graphics->numbers;
		i++;
	}
	ft_switch_counter(counter, graphics->map->move_c);
	return (counter);
}
