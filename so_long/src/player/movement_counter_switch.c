/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_counter_switch.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:59:43 by honnguye          #+#    #+#             */
/*   Updated: 2025/01/18 09:34:21 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

void	ft_switch_counter(t_anim **counter, int moves)
{
	int	i;
	int	j;
	int	count;

	i = 5;
	count = moves;
	while (i >= 0)
	{
		j = 0;
		counter[i]->anim_frame = count % 10;
		while (j < 10)
		{
			if (j == counter[i]->anim_frame)
			{
				counter[i]->anim_images[j]->instances[i].enabled = true;
			}
			else
				counter[i]->anim_images[j]->instances[i].enabled = false;
			j++;
		}
		count /= 10;
		i--;
	}
}
