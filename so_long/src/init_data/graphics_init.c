/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:25:49 by honnguye          #+#    #+#             */
/*   Updated: 2025/01/18 08:43:52 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

int	ft_init_graphics(t_graphics *graphics, char *path)
{
	graphics->map = ft_init_map(path);
	if (!graphics->map)
		return (INIT_FAILED);
	if (ft_map_parser(graphics->map) != SUCCESS)
	{
		// ft_free_map(graphics->map->height, graphics->map);
		return (INIT_FAILED);
	}
	graphics->mlx = mlx_init(graphics->map->width * IMG_SIZE,
			graphics->map->height * IMG_SIZE, NAME, false);
	if (!graphics->mlx)
	{
		mlx_terminate(graphics->mlx);
		return (MLX_FAILURE);
	}
	ft_set_map_img(graphics, graphics->map);
	graphics->anim = ft_set_player_anim(graphics);
	graphics->map->collected = 0;
	graphics->can_move = 1;
	graphics->last_anim_dir = PLAYER_MR;
	graphics->anim->z_exit = graphics->exit->instances[0].z;
	return (SUCCESS);
}
