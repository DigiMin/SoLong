/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_restrictions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:22:47 by honnguye          #+#    #+#             */
/*   Updated: 2025/01/15 23:32:58 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

int		ft_set_pimage_coord(t_graphics *graphics, int x, int y);

void	ft_move_player(t_graphics *graphics, t_axes dia, int pix)
{
	int	xm;
	int	ym;

	ym = graphics->player_r[0]->instances[0].y;
	xm = graphics->player_r[0]->instances[0].x;
	if (dia == X)
		xm += pix;
	else if (dia == Y)
	{
		ft_animate(graphics->anim, graphics->last_anim_dir);
		ym += pix;
	}
	if (!ft_is_space(graphics, xm, ym))
		return ;
	ft_switch_exit_z(graphics);
	ft_set_pimage_coord(graphics, xm, ym);
	graphics->map->move_c++;
	ft_switch_counter(graphics->anim->numbers, graphics->map->move_c);
	printf("Move count: %d\n", graphics->map->move_c);
}

int	ft_set_pimage_coord(t_graphics *graphics, int x, int y)
{
	int	i;

	i = 0;
	while (i < ANIM_COUNT)
	{
		graphics->player_r[i]->instances[0].x = x;
		graphics->player_r[i]->instances[0].y = y;
		graphics->player_l[i]->instances[0].x = x;
		graphics->player_l[i]->instances[0].y = y;
		graphics->player_mr[i]->instances[0].x = x;
		graphics->player_mr[i]->instances[0].y = y;
		graphics->player_ml[i]->instances[0].x = x;
		graphics->player_ml[i]->instances[0].y = y;
		graphics->player_dead[i]->instances[0].x = x;
		graphics->player_dead[i]->instances[0].y = y;
		i++;
	}
	return (1);
}

int	ft_is_space(t_graphics *graphics, int xm, int ym)
{
	int	x[2];
	int	y[2];

	x[0] = (xm + OFFSET) / IMG_SIZE;
	y[0] = (ym + OSET) / IMG_SIZE;
	x[1] = (xm + IMG_SIZE - OFFSET) / IMG_SIZE;
	y[1] = (ym + IMG_SIZE - 1) / IMG_SIZE;
	if (graphics->map->visited[y[0]][x[0]] != '0'
		&& graphics->map->visited[y[1]][x[1]] != '0'
		&& graphics->map->visited[y[1]][x[0]] != '0'
		&& graphics->map->visited[y[0]][x[1]] != '0')
		return (1);
	return (0);
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
		if (ft_is_player_near(graphics) != SUCCESS && graphics->anim->enemy_loops[i] == 4)
		{
			graphics->can_move = 0;
		}
		if (graphics->anim->enemy_loops[i] > 0
			&& graphics->anim->enemy_loops[i] < 4)
		{
			ft_animate_enemy(graphics, ENEMY_CNTDWN, i);
		}
		else if (graphics->anim->enemy_loops[i] == 4)
		{
			ft_disable_enemy_instance(graphics->anim, ENEMY_CNTDWN, i);
			ft_animate_enemy(graphics, ENEMY_EXPLSN, i);
		}
		else if (graphics->anim->enemy_loops[i] == 5)
		{
			ft_disable_enemy_instance(graphics->anim, ENEMY_EXPLSN, i);
			graphics->anim->enemy_loops[i] = 10;
		}
		i++;
	}
}

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
	if (graphics->last_anim_dir == PLAYER_ML)
		ft_animate(graphics->anim, PLAYER_L);
	else if (graphics->last_anim_dir == PLAYER_MR)
		ft_animate(graphics->anim, PLAYER_R);
	if (mlx_is_key_down(graphics->mlx, MLX_KEY_W)
		|| mlx_is_key_down(graphics->mlx, MLX_KEY_UP))
		ft_move_player(graphics, Y, -PLAYER_SPEED);
	if (mlx_is_key_down(graphics->mlx, MLX_KEY_S)
		|| mlx_is_key_down(graphics->mlx, MLX_KEY_DOWN))
	{
		ft_move_player(graphics, Y, +PLAYER_SPEED);
	}
	if (mlx_is_key_down(graphics->mlx, MLX_KEY_A)
		|| mlx_is_key_down(graphics->mlx, MLX_KEY_LEFT))
	{
		graphics->last_anim_dir = PLAYER_ML;
		ft_animate(graphics->anim, PLAYER_ML);
		ft_move_player(graphics, X, -PLAYER_SPEED);
	}
	if (mlx_is_key_down(graphics->mlx, MLX_KEY_D)
		|| mlx_is_key_down(graphics->mlx, MLX_KEY_RIGHT))
	{
		graphics->last_anim_dir = PLAYER_MR;
		ft_animate(graphics->anim, PLAYER_MR);
		ft_move_player(graphics, X, +PLAYER_SPEED);
	}
	ft_collect(param);
	if (ft_can_exit(param))
	{
		mlx_terminate(graphics->mlx);
		exit(EXIT_SUCCESS);
	}
}
