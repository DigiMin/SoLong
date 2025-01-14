/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:58:16 by honnguye          #+#    #+#             */
/*   Updated: 2025/01/14 17:18:00 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

int			ft_enable_anim(t_game_anim *anim, e_anim_spec spec);

void	ft_animate(void *param, e_anim_spec spec)
{
	t_game_anim	*anim;
	t_anim		*sprite;

	anim = param;
	sprite = ft_spec_anim(anim, spec, 0);
	ft_enable_anim(anim, spec);
	sprite->enabled = 1;
	if (sprite->sleep == sprite->anim_speed)
	{
		if (sprite->anim_frame == sprite->anim_count - 1)
			sprite->anim_frame = 0;
		sprite->anim_frame++;
		sprite->sleep = 0;
	}
	sprite->sleep++;
	ft_switch_display(sprite);
}

t_anim	*ft_spec_anim(t_game_anim *anim, e_anim_spec spec, int instance)
{
	if (spec == PLAYER_R)
		return (anim->player_r);
	else if (spec == PLAYER_L)
		return (anim->player_l);
	else if (spec == PLAYER_MR)
		return (anim->player_mr);
	else if (spec == PLAYER_ML)
		return (anim->player_ml);
	else if (spec == PLAYER_DEAD)
		return (anim->player_dead);
	else if (spec == ENEMY_CNTDWN)
		return (anim->enemy_cntdwn[instance]);
	else if (spec == ENEMY_EXPLSN)
		return (anim->enemy_explsn[instance]);
	return (NULL);
}

int	ft_enable_anim(t_game_anim *anim, e_anim_spec spec)
{
	anim->player_r->enabled = 0;
	anim->player_l->enabled = 0;
	anim->player_mr->enabled = 0;
	anim->player_ml->enabled = 0;
	anim->player_dead->enabled = 0;
	if (spec == PLAYER_R)
		anim->player_r->enabled = 1;
	else if (spec == PLAYER_L)
		anim->player_l->enabled = 1;
	else if (spec == PLAYER_MR)
		anim->player_mr->enabled = 1;
	else if (spec == PLAYER_ML)
		anim->player_ml->enabled = 1;
	else if (spec == PLAYER_DEAD)
		anim->player_dead->enabled = 1;
	ft_switch_display(anim->player_r);
	ft_switch_display(anim->player_l);
	ft_switch_display(anim->player_mr);
	ft_switch_display(anim->player_ml);
	ft_switch_display(anim->player_dead);
	return (1);
}

t_game_anim	*ft_init_game_anim(t_graphics *graphics)
{
	t_game_anim	*anim;
	int			i;

	if (!ft_allocate_aimg(graphics))
		return (NULL);
	anim = malloc(sizeof(t_game_anim));
	if (!anim)
		return (NULL);
	anim->numbers = ft_set_counter(graphics);
	printf("Numbers loaded\n");
	anim->enemy_cntdwn = malloc(sizeof(t_anim *) * graphics->map->enemy_c);
	anim->enemy_explsn = malloc(sizeof(t_anim *) * graphics->map->enemy_c);
	anim->enemy_loops = malloc(sizeof(int) * graphics->map->enemy_c);
	i = 0;
	graphics->enemy_cntdwn = ft_set_enemy_img(graphics,
			"./graphics/Enemy/Enemy", graphics->enemy_cntdwn);
	graphics->enemy_explsn = ft_set_enemy_img(graphics,
			"./graphics/Effects/Explosion", graphics->enemy_explsn);
	while (i < graphics->map->enemy_c)
	{
		anim->enemy_cntdwn[i] = ft_set_enemy_anim(graphics->enemy_cntdwn);
		anim->enemy_explsn[i] = ft_set_enemy_anim(graphics->enemy_explsn);
		anim->enemy_loops[i] = 0;
		i++;
	}
	printf("Enemies loaded\n");
	ft_disable_all_enemy_anim(graphics, anim);
	printf("Enemies disabled\n");
	anim->player_r = ft_set_anim_img(graphics, graphics->player_r,
			"./graphics/Warrior/Warrior_r", graphics->map->start);
	anim->player_l = ft_set_anim_img(graphics, graphics->player_l,
			"./graphics/Warrior/Warrior_l", graphics->map->start);
	anim->player_mr = ft_set_anim_img(graphics, graphics->player_mr,
			"./graphics/Warrior/Warrior_rmove", graphics->map->start);
	anim->player_ml = ft_set_anim_img(graphics, graphics->player_ml,
			"./graphics/Warrior/Warrior_lmove", graphics->map->start);
	anim->player_dead = ft_set_anim_img(graphics, graphics->player_dead,
			"./graphics/Warrior/Warrior_dead", graphics->map->start);
	printf("Player loaded\n");
	anim->player_r->enabled = 1;
	return (anim);
}

t_anim	*ft_set_anim_img(t_graphics *graphics, mlx_image_t **asset, char *path,
		t_coord *coord)
{
	int		i;
	t_anim	*anim;
	char	*c;

	anim = malloc(sizeof(t_anim));
	if (!anim)
		return (NULL);
	i = 0;
	anim->anim_count = ANIM_COUNT;
	anim->anim_frame = 0;
	anim->sleep = 0;
	anim->anim_speed = ANIM_SPEED;
	anim->enabled = 0;
	while (i < ANIM_COUNT)
	{
		c = ft_itoa(i);
		asset[i] = ft_draw_asset(graphics->mlx, ft_multi_strjoin(3, path, c,
					".png"), coord);
		free(c);
		i++;
	}
	anim->anim_images = asset;
	ft_switch_display(anim);
	return (anim);
}

/*

	* @brief Switches the display of each animation based on which anim_frame is active
 *		- if the animation is not enabled, all images are disabled
 *
 * @param asset The animation structure
 *
 * @return void
 */
void	ft_switch_display(t_anim *asset)
{
	int	i;

	i = 0;
	if (!asset->enabled)
	{
		while (i < asset->anim_count)
		{
			asset->anim_images[i]->enabled = false;
			i++;
		}
		return ;
	}
	i = 0;
	while (i < asset->anim_count)
	{
		if (i == asset->anim_frame)
		{
			asset->anim_images[i]->enabled = true;
		}
		else
		{
			asset->anim_images[i]->enabled = false;
		}
		i++;
	}
}
