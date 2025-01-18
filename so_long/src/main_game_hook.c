/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_game_hook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:22:47 by honnguye          #+#    #+#             */
/*   Updated: 2025/01/18 10:03:15 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

void	ft_hook(void *param)
{
	t_graphics	*graphics;

	graphics = param;
	if (mlx_is_key_down(graphics->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(graphics->mlx);
	ft_enemy_handler(graphics);
	if (!graphics->can_move)
	{
		ft_animate(graphics->anim, PLAYER_DEAD);
		return ;
	}
	ft_idle(graphics);
	ft_move_left(graphics);
	ft_move_right(graphics);
	ft_move_up(graphics);
	ft_move_down(graphics);
	ft_collect(param);
	if (ft_can_exit(param) == SUCCESS)
	{
		mlx_terminate(graphics->mlx);
		exit(EXIT_SUCCESS);
	}
}
