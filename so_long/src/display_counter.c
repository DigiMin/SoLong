/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_counter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:59:43 by honnguye          #+#    #+#             */
/*   Updated: 2025/01/13 22:54:17 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

mlx_image_t *ft_draw_number(t_graphics *graphics, int number);

void	ft_draw_numbers(t_graphics *graphics)
{
	int i;

	i = 0;
	while (i < 10)
	{
		graphics->numbers[i] = ft_draw_number(graphics, i);
		i++;
	}
}

mlx_image_t *ft_draw_number(t_graphics *graphics, int number)
{
	char *c;
	int i;
	int x;
	mlx_image_t *img;

	c = ft_itoa(number);
	img = ft_load_png(graphics->mlx, ft_multi_strjoin(3, "./graphics/UI/", c, ".png"));
	if (!img)
		return (NULL);
	free(c);
	x = (graphics->map->width - 3) * 64;
	i = 0;
	while (i < 6)
	{
		mlx_image_to_window(graphics->mlx, img, x, 0);
		x += HALF_SIZE;
		i++;
	}
	return (img);
}

t_anim **ft_set_counter(t_graphics *graphics)
{
	t_anim **counter;
	int i;

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
