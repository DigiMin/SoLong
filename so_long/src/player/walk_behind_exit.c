/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walk_behind_exit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 10:05:09 by honnguye          #+#    #+#             */
/*   Updated: 2025/01/17 10:06:08 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"


int	ft_switch_exit_z(void *param)
{
	t_graphics		*graphics;
	mlx_instance_t	*player;
	mlx_image_t		*exit;

	graphics = param;
	player = graphics->player_r[0]->instances;
	exit = graphics->exit;
	if (player->x > exit->instances[0].x - IMG_SIZE
		&& player->x < exit->instances[0].x + IMG_SIZE && player->y
		- HALF_SIZE > exit->instances[0].y - IMG_SIZE && player->y
		+ OSET < exit->instances[0].y + IMG_SIZE + HALF_SIZE)
	{
		mlx_set_instance_depth(graphics->exit->instances,
			graphics->player_dead[ANIM_COUNT - 1]->instances[0].z + 1);
		return (SUCCESS);
	}
	if (graphics->exit->instances->z == graphics->player_dead[ANIM_COUNT - 1]->instances[0].z + 1)
		mlx_set_instance_depth(graphics->exit->instances,
			graphics->anim->z_exit);
	return (SUCCESS);
}