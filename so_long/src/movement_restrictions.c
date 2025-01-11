/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_restrictions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:22:47 by honnguye          #+#    #+#             */
/*   Updated: 2025/01/11 22:33:22 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

int ft_set_pimage_coord(t_graphics *graphics, int x, int y);

void ft_move_player(t_graphics *graphics, char dia, int pix)
{
	int xm;
	int ym;

	ym = graphics->player_r[0]->instances[0].y;
	xm = graphics->player_r[0]->instances[0].x;
	if (dia == 'x')
		xm += pix;
	else if (dia == 'y')
		ym += pix;
	if (!ft_is_space(graphics, xm, ym, dia))
		return ;
	ft_switch_exit_z(graphics);
	printf("Tower z index: %d\n", graphics->exit->instances[0].z);
	ft_set_pimage_coord(graphics, xm, ym);
	graphics->map->move_c++;
	printf("Move count: %d\n", graphics->map->move_c);
}

int ft_set_pimage_coord(t_graphics *graphics, int x, int y)
{
	int i;

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

int	ft_is_space(t_graphics *graphics, int xm, int ym, char dia)
{
	mlx_instance_t *player = graphics->player_r[0]->instances;
	// mlx_image_t *space = graphics->space;
	int	x[2];
	int	y[2];

	x[0] = (xm + OFFSET) / IMG_SIZE;
	y[0] = (ym + OSET) / IMG_SIZE;
	x[1] = (xm + IMG_SIZE - OFFSET) / IMG_SIZE;
	y[1] = (ym + IMG_SIZE - 1) / IMG_SIZE;
	if (graphics->map->visited[y[0]][x[0]] != '0' &&\
	 graphics->map->visited[y[1]][x[1]] != '0' &&\
	  graphics->map->visited[y[1]][x[0]] != '0' &&\
	   graphics->map->visited[y[0]][x[1]] != '0')
		return (1);
	return (0);
}

void ft_hook(void* param)
{
	t_graphics *graphics = param;
	int instance;
	int i;

	if (mlx_is_key_down(graphics->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(graphics->mlx);
	instance = ft_enemy_touched(param);
	if (instance >= 0)
	{
		printf("Enemy touched: %d\n", instance);
		graphics->enemy->instances[instance].enabled = false;
	}
	i = 0;
	while (i < graphics->map->enemy_c)
	{
		// printf("Enemy loops[%d]: %d\n", i, graphics->anim->enemy_loops[i]);
		if (graphics->anim->enemy_loops[i] > 0 && graphics->anim->enemy_loops[i] < 4)
			ft_animate_enemy(graphics, 'c', i);
		else if (graphics->anim->enemy_loops[i] == 4)
		{
			graphics->anim->enemy_cntdwn[i]->enabled = 0;
			// ft_switch_enemy_display(graphics, graphics->anim->enemy_cntdwn[i], i);
			printf("ANIM DISABLED\n");
			ft_animate_enemy(graphics, 'b', i);
		}
		else if (graphics->anim->enemy_loops[i] == 5)
		{
			graphics->anim->enemy_explsn[i]->enabled = 0;
			graphics->anim->enemy_loops[i] = 10;
			ft_switch_enemy_display(graphics, graphics->anim->enemy_explsn[i], i);
		}
		i++;
		// ft_animate(graphics->anim, 'x');
		// graphics->can_move = 0;
	}
	if (!graphics->can_move)
		return ;
	if (graphics->last_key == 'a')
		ft_animate(graphics->anim, 'l');
	else if (graphics->last_key == 'd')
		ft_animate(graphics->anim, 'r');
	if (mlx_is_key_down(graphics->mlx, MLX_KEY_W) || mlx_is_key_down(graphics->mlx, MLX_KEY_UP))
	{
		ft_animate(graphics->anim, graphics->last_key);
		ft_move_player(graphics, 'y', -PLAYER_SPEED);
	}
	if (mlx_is_key_down(graphics->mlx, MLX_KEY_S) || mlx_is_key_down(graphics->mlx, MLX_KEY_DOWN))
	{
		ft_animate(graphics->anim, graphics->last_key);
		ft_move_player(graphics, 'y', +PLAYER_SPEED);
	}
	if (mlx_is_key_down(graphics->mlx, MLX_KEY_A) || mlx_is_key_down(graphics->mlx, MLX_KEY_LEFT))
	{
		graphics->last_key = 'a';
		ft_animate(graphics->anim, 'a');
		ft_move_player(graphics, 'x', -PLAYER_SPEED);
	}
	if (mlx_is_key_down(graphics->mlx, MLX_KEY_D) || mlx_is_key_down(graphics->mlx, MLX_KEY_RIGHT))
	{
		graphics->last_key = 'd';
		ft_animate(graphics->anim, 'd');
		ft_move_player(graphics, 'x', +PLAYER_SPEED);
	}
	ft_collect(param);
	if (ft_can_exit(param))
	{
		mlx_terminate(graphics->mlx);
		exit(EXIT_SUCCESS);
	}
}
