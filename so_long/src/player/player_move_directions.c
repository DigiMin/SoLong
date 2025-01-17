/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 10:06:31 by honnguye          #+#    #+#             */
/*   Updated: 2025/01/17 10:07:30 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

void	ft_idle(t_graphics *graphics)
{
	if (graphics->last_anim_dir == PLAYER_ML)
		ft_animate(graphics->anim, PLAYER_L);
	else if (graphics->last_anim_dir == PLAYER_MR)
		ft_animate(graphics->anim, PLAYER_R);
}

void	ft_move_left(t_graphics *graphics)
{
	if (mlx_is_key_down(graphics->mlx, MLX_KEY_A)
		|| mlx_is_key_down(graphics->mlx, MLX_KEY_LEFT))
	{
		graphics->last_anim_dir = PLAYER_ML;
		ft_animate(graphics->anim, PLAYER_ML);
		ft_move_player(graphics, X, -PLAYER_SPEED);
	}
}

void	ft_move_right(t_graphics *graphics)
{
	if (mlx_is_key_down(graphics->mlx, MLX_KEY_D)
		|| mlx_is_key_down(graphics->mlx, MLX_KEY_RIGHT))
	{
		graphics->last_anim_dir = PLAYER_MR;
		ft_animate(graphics->anim, PLAYER_MR);
		ft_move_player(graphics, X, +PLAYER_SPEED);
	}
}

void	ft_move_up(t_graphics *graphics)
{
	if (mlx_is_key_down(graphics->mlx, MLX_KEY_W)
		|| mlx_is_key_down(graphics->mlx, MLX_KEY_UP))
		ft_move_player(graphics, Y, -PLAYER_SPEED);
}

void	ft_move_down(t_graphics *graphics)
{
	if (mlx_is_key_down(graphics->mlx, MLX_KEY_S)
		|| mlx_is_key_down(graphics->mlx, MLX_KEY_DOWN))
		ft_move_player(graphics, Y, +PLAYER_SPEED);
}