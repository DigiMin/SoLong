/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walk_behind_exit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 10:05:09 by honnguye          #+#    #+#             */
/*   Updated: 2025/01/21 12:00:30 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

void	ft_switch_exit_z(t_graphics **graphics)
{
	mlx_instance_t	*player;
	mlx_image_t		*exit;

	player = (*graphics)->player_dead[ANIM_COUNT - 1]->instances;
	if ((*graphics)->exit_open->enabled)
		exit = (*graphics)->exit_open;
	else if ((*graphics)->exit->enabled)
		exit = (*graphics)->exit;
	if (player->x > exit->instances[0].x - IMG_SIZE
		&& player->x < exit->instances[0].x + IMG_SIZE && player->y
		- HALF_SIZE > exit->instances[0].y - IMG_SIZE && player->y
		+ OSET < exit->instances[0].y + IMG_SIZE + HALF_SIZE)
		mlx_set_instance_depth(exit->instances, player[0].z + 1);
	else
		mlx_set_instance_depth(exit->instances, (*graphics)->anim->z_exit);
}

void	ft_switch_exit_display(t_graphics **graphics)
{
	if ((*graphics)->map->collected == (*graphics)->map->collectible_c)
	{
		(*graphics)->exit_open->enabled = true;
		(*graphics)->exit->enabled = false;
	}
}
