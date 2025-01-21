/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_game_hook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:22:47 by honnguye          #+#    #+#             */
/*   Updated: 2025/01/21 10:44:36 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

void	ft_hook(void *param)
{
	t_graphics	*graphics;

	graphics = param;
	if (mlx_is_key_down(graphics->mlx, MLX_KEY_ESCAPE))
		ft_terminate_game(&graphics, SUCCESS);
	ft_enemy_handler(graphics);
	if (!graphics->can_move || graphics->map->move_c == 999999)
	{
		ft_animate(graphics->anim, PLAYER_DEAD);
		return ;
	}
	ft_idle(graphics);
	ft_move_left(graphics);
	ft_move_right(graphics);
	ft_move_up(graphics);
	ft_move_down(graphics);
	ft_collect(graphics);
	if (ft_can_exit(graphics) == SUCCESS)
		ft_terminate_game(&graphics, SUCCESS);
}
