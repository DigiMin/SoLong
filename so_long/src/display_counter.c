/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_counter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:59:43 by honnguye          #+#    #+#             */
/*   Updated: 2025/01/13 10:36:29 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

mlx_image_t **ft_draw_numbers(t_graphics *graphics)
{
	int i;
	int j;
	int x;
	char *c;

	i = 0;
	while (i < 10)
	{
		c = ft_itoa(i);
		graphics->numbers[i] = ft_load_png(graphics->mlx, ft_multi_strjoin(3, "./graphics/UI/", c, ".png"));
		free(c);
		printf("Number: %d\n", i);
		j = 0;
		x = (graphics->map->width - 3) * 64;
		while (j < 6)
		{
			printf("Instance: %d\n", j);
			mlx_image_to_window(graphics->mlx, graphics->numbers[i], x, 0);
			x += HALF_SIZE;
			j++;
		}
		i++;
	}
	return (graphics->numbers);
}

t_anim **ft_set_counter(t_graphics *graphics)
{
	t_anim **counter;
	mlx_image_t **numbers;
	int i;

	numbers = ft_draw_numbers(graphics);
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
		counter[i]->anim_images = numbers;
		i++;
	}
	ft_switch_counter(counter, graphics->map->move_c);
	return (counter);
}

void ft_switch_counter(t_anim **counter, int moves)
{
	int i;
	int j;
	int count;

	i = 5;
	count = moves;
	while (i >= 0)
	{
		j = 0;
		counter[i]->anim_frame = count % 10;
		printf("Counter[%d]: %d\n", i, counter[i]->anim_frame);
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
