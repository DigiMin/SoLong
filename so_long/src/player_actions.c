/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 22:35:48 by honnguye          #+#    #+#             */
/*   Updated: 2025/01/09 10:37:29 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

int	ft_can_exit(void *param)
{
	t_graphics	*graphics = param;
	mlx_instance_t *player = graphics->player_r[0]->instances;
	mlx_image_t *exit = graphics->exit;

	if (player->x - OSET > exit->instances[0].x - IMG_SIZE && player->x + OSET < exit->instances[0].x + IMG_SIZE \
	&& player->y - HALF_SIZE > exit->instances[0].y && player->y + OSET < exit->instances[0].y + IMG_SIZE * 2 \
	&& graphics->map->collected == graphics->map->collectible_c)
		return (1);
	return (0);
}

int	ft_collect(void* param)
{
	t_graphics	*graphics = param;
	mlx_instance_t *player = graphics->player_r[0]->instances;
	mlx_image_t *collectable = graphics->collectable;

	int	i = 0;
	while (i < graphics->map->collectible_c)
	{
		if (player->x - OSET > collectable->instances[i].x - IMG_SIZE && player->x + OSET < collectable->instances[i].x + IMG_SIZE \
		&& player->y - HALF_SIZE > collectable->instances[i].y - IMG_SIZE && player->y + OSET < collectable->instances[i].y + IMG_SIZE \
		&& collectable->instances[i].enabled == true)
			return (graphics->map->collected++, printf("Collected: %d\n", graphics->map->collected), collectable->instances[i].enabled = false, 1);
		i++;
	}
	return (0);
}


