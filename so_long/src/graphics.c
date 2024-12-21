/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:25:49 by honnguye          #+#    #+#             */
/*   Updated: 2024/12/18 11:17:37 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

t_anim *ft_set_images(t_graphics *graphics, t_map *map)
{
	char *gold = "./graphics/Resources/Shroom.png";
	char *water = "./graphics/Terrain/Water.png";
	char *grass = "./graphics/Terrain/Grass_full.png";
	char *tower = "./graphics/Resources/Tower_Blue_64.png";
	char *warrior0 = "./graphics/Warrior/Warrior_r0.png";
	char *warrior1 = "./graphics/Warrior/Warrior_r1.png";
	char *warrior2 = "./graphics/Warrior/Warrior_r2.png";
	char *warrior3 = "./graphics/Warrior/Warrior_r3.png";
	char *warrior4 = "./graphics/Warrior/Warrior_r4.png";
	char *warrior5 = "./graphics/Warrior/Warrior_r5.png";

	graphics->player = malloc(sizeof(mlx_image_t *) * 6);
	graphics->wall = ft_draw_asset(graphics->mlx, water, map->walls);
	graphics->space = ft_draw_asset(graphics->mlx, grass, map->spaces);
	graphics->collectable = ft_draw_asset(graphics->mlx, gold, map->collectibles);
	graphics->exit = ft_draw_exit(graphics->mlx, tower, map->exit);

	t_anim *anim = malloc(sizeof(t_anim));
	anim->anim_count = 6;
	anim->anim_frame = 0;
	anim->sleep = 0;
	anim->action = 'i';
	anim->direction = 'r';
	anim->anim_images = graphics->player;

	graphics->player[0] = ft_draw_asset(graphics->mlx, warrior0, map->start);
	graphics->player[1] = ft_draw_asset(graphics->mlx, warrior1, map->start);
	graphics->player[2] = ft_draw_asset(graphics->mlx, warrior2, map->start);
	graphics->player[3] = ft_draw_asset(graphics->mlx, warrior3, map->start);
	graphics->player[4] = ft_draw_asset(graphics->mlx, warrior4, map->start);
	graphics->player[5] = ft_draw_asset(graphics->mlx, warrior5, map->start);
	ft_switch_display(anim);
	return (anim);
}


void ft_switch_display(t_anim *asset)
{
	int	i;

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

// /// @brief Joins two strings, need to be freed
// /// @param s1 starting string
// /// @param s2 string to concatenate
// /// @return a pointer to the new string
// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	char	*new;
// 	size_t	len1;
// 	size_t	len2;

// 	len1 = ft_strlen(s1);
// 	len2 = ft_strlen(s2);
// 	new = malloc((len1 + len2 + 1) * sizeof(char));
// 	if (!new)
// 		return (NULL);
// 	new[len1 + len2] = '\0';
// 	while (len2 > 0)
// 	{
// 		len2--;
// 		new[len1 + len2] = s2[len2];
// 	}
// 	while (len1 > 0)
// 	{
// 		len1--;
// 		new[len1] = s1[len1];
// 	}
// 	return (new);
// }




