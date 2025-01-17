/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_game_hook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:22:47 by honnguye          #+#    #+#             */
/*   Updated: 2025/01/17 11:51:13 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

void	ft_enemy_handler(t_graphics *graphics);
void	ft_explode(t_graphics *graphics, int i);

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

void	ft_enemy_handler(t_graphics *graphics)
{
	int	instance;
	int	i;

	if (graphics->map->enemy_c)
	{
		instance = ft_enemy_touched(graphics);
		if (instance >= 0)
			graphics->enemy->instances[instance].enabled = false;
	}
	i = 0;
	while (i < graphics->map->enemy_c)
	{
		if (ft_is_enemy_near(graphics) && graphics->anim->enemy_loops[i] == 4)
			graphics->can_move = 0;
		ft_explode(graphics, i);
		i++;
	}
}

void	ft_explode(t_graphics *graphics, int i)
{
	if (graphics->anim->enemy_loops[i] > 0
		&& graphics->anim->enemy_loops[i] < 4)
		ft_animate_enemy(graphics, ENEMY_CNTDWN, i);
	if (graphics->anim->enemy_loops[i] == 4)
	{
		ft_disable_enemy_instance(graphics->anim, ENEMY_CNTDWN, i);
		ft_animate_enemy(graphics, ENEMY_EXPLSN, i);
	}
	if (graphics->anim->enemy_loops[i] == 5)
	{
		ft_disable_enemy_instance(graphics->anim, ENEMY_EXPLSN, i);
		graphics->anim->enemy_loops[i] = 10;
	}
}

