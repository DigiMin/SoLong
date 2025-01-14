/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 22:28:40 by honnguye          #+#    #+#             */
/*   Updated: 2025/01/14 19:06:03 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

int	ft_enemy_touched(void *param)
{
	t_graphics		*graphics;
	mlx_instance_t	*player;
	mlx_instance_t	*enemy;
	int				i;

	graphics = param;
	player = graphics->player_r[0]->instances;
	enemy = graphics->enemy->instances;
	i = 0;
	while (i < graphics->map->enemy_c)
	{
		if (player->x - OSET > enemy[i].x - IMG_SIZE && player->x
			+ OSET < enemy[i].x + IMG_SIZE && player->y - HALF_SIZE > enemy[i].y
			- IMG_SIZE && player->y + OSET < enemy[i].y + IMG_SIZE)
		{
			if (graphics->anim->enemy_loops[i] == 0)
				graphics->anim->enemy_loops[i] = 1;
			return (i);
		}
		i++;
	}
	return (-1);
}

int	ft_is_player_near(t_graphics *graphics)
{
	mlx_instance_t	*player;
	mlx_instance_t	*enemy;
	int				i;

	player = graphics->player_r[0]->instances;
	enemy = graphics->enemy->instances;
	i = 0;
	while (i < graphics->map->enemy_c)
	{
		if (player->x - OSET > enemy[i].x - (IMG_SIZE * 1.3) && 
			player->x + OSET < enemy[i].x + (IMG_SIZE * 1.3) && 
			player->y - HALF_SIZE > enemy[i].y - (IMG_SIZE * 1.3) && 
			player->y + OSET < enemy[i].y + (IMG_SIZE * 1.3) &&
			graphics->anim->enemy_loops[i] == 4)
			return (1);
		i++;
	}
	return (0);
}

t_anim	*ft_set_enemy_anim(mlx_image_t **asset)
{
	int		i;
	t_anim	*anim;

	anim = malloc(sizeof(t_anim));
	if (!anim)
		return (NULL);
	i = 0;
	anim->anim_count = ANIM_COUNT;
	anim->anim_frame = 0;
	anim->sleep = 0;
	anim->anim_speed = ANIM_SPEED;
	anim->enabled = 1;
	anim->anim_images = asset;
	return (anim);
}

mlx_image_t	**ft_set_enemy_img(t_graphics *graphics, char *path,
		mlx_image_t **asset)
{
	int			i;
	char		*c;
	mlx_image_t	**enemy;

	if (!graphics->map->enemy_c)
		return (NULL);
	i = 0;
	enemy = asset;
	while (i < ANIM_COUNT)
	{
		c = ft_itoa(i);
		enemy[i] = ft_draw_asset(graphics->mlx, ft_multi_strjoin(3, path, c,
					".png"), graphics->map->enemy);
		free(c);
		i++;
	}
	return (enemy);
}

void	ft_animate_enemy(t_graphics *graphics, e_anim_spec spec, int instance)
{
	t_game_anim	*anim;
	t_anim		*sprite;

	anim = graphics->anim;
	sprite = ft_spec_anim(anim, spec, instance);
	ft_enable_enemy_anim(graphics, spec, instance);
	if (sprite->sleep == sprite->anim_speed)
	{
		if (sprite->anim_frame == sprite->anim_count - 1)
		{
			sprite->anim_frame = 0;
			anim->enemy_loops[instance]++;
		}
		sprite->anim_frame++;
		sprite->sleep = 0;
	}
	sprite->sleep++;
	ft_switch_enemy_display(graphics, sprite, instance);
}

int	ft_enable_enemy_anim(t_graphics *graphics, e_anim_spec spec, int instance)
{
	t_game_anim	*anim;

	anim = graphics->anim;
	if (spec == ENEMY_CNTDWN)
	{
		ft_switch_enemy_display(graphics, anim->enemy_cntdwn[instance],
			instance);
	}
	else if (spec == ENEMY_EXPLSN)
	{
		ft_switch_enemy_display(graphics, anim->enemy_explsn[instance],
			instance);
	}
	return (1);
}

void	ft_disable_all_enemy_anim(t_graphics *graphics, t_game_anim *anim)
{
	int	i;

	i = 0;
	while (i < graphics->map->enemy_c)
	{
		ft_disable_enemy_instance(anim, ENEMY_CNTDWN, i);
		ft_disable_enemy_instance(anim, ENEMY_EXPLSN, i);
		i++;
	}
}

void	ft_disable_enemy_instance(t_game_anim *anim, e_anim_spec spec, int i)
{
	int	j;

	j = 0;
	printf("Trying to disable enemy instance\n");
	printf("Instance: %d\n", i);
	while (j < ANIM_COUNT)
	{
		if (spec == ENEMY_CNTDWN)
			anim->enemy_cntdwn[i]->anim_images[j]->instances[i].enabled = false;
		else if (spec == ENEMY_EXPLSN)
			anim->enemy_explsn[i]->anim_images[j]->instances[i].enabled = false;
		j++;
	}
	printf("Enemy instance disabled\n");
}

void	ft_switch_enemy_display(t_graphics *graphics, t_anim *asset, int ins)
{
	int	i;
	int	j;

	i = 0;
	while (i < ANIM_COUNT)
	{
		j = 0;
		while (j < graphics->map->enemy_c)
		{
			if (i == asset->anim_frame && j == ins)
				asset->anim_images[i]->instances[j].enabled = true;
			else if (i != asset->anim_frame && j == ins)
				asset->anim_images[i]->instances[j].enabled = false;
			j++;
		}
		i++;
	}
}
