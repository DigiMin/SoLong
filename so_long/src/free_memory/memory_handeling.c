/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_handeling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 09:39:56 by honnguye          #+#    #+#             */
/*   Updated: 2025/01/20 11:04:28 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

//bool mlx_freen(int32_t count, ...)
//bool mlx_error(mlx_errno_t val)
//void mlx_delete_texture(mlx_texture_t* texture)
//void mlx_terminate(mlx_t* mlx)

// ==190716== 48 bytes in 1 blocks are definitely lost in loss record 1,819 of 2,239
// ==190716==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
// ==190716==    by 0x405EB3: ft_alloc_player_imgs (structs_malloc.c:32)
// ==190716==    by 0x402D54: ft_set_player_anim (player_draw.c:19)
// ==190716==    by 0x40652C: ft_init_graphics (graphics_init.c:33)
// ==190716==    by 0x403F3E: main (so_long.c:27)

// Frees the map array
void ft_free_map(int height, t_map **map)
{
    if (!map)
        return;
    if ((*map)->terrain)
        ft_free_matrix((*map)->terrain, height);
    if ((*map)->visited)
        ft_free_matrix((*map)->visited, height);
    if ((*map)->start)
        ft_free_coords(&(*map)->start);
    if ((*map)->exit)
        ft_free_coords(&(*map)->exit);
    if ((*map)->spaces) {
        printf("IN FREE MAP, map: %p\n", map);
        printf("*map pointer %p\n", *map);
        printf("IN FREE MAP map->spaces: %p\n", (*map)->spaces);
        ft_free_coords(&(*map)->spaces);
    }
    if ((*map)->collectibles)
        ft_free_coords(&(*map)->collectibles);
    if ((*map)->walls)
        ft_free_coords(&(*map)->walls);
    if ((*map)->enemy)
        ft_free_coords(&(*map)->enemy);
    free((*map));
    (*map) = NULL;
}

void ft_free_game_anim(t_graphics **graphics, t_game_anim *anim)
{
    if (!anim)
        return;
    if (anim->player_l)
    {
        free(anim->player_l);
        anim->player_l = NULL;
    }
    if (anim->player_r)
    {
        free(anim->player_r);
        anim->player_r = NULL;
    }
    if (anim->player_ml)
    {
        free(anim->player_ml);
        anim->player_ml = NULL;
    }
    if (anim->player_mr)
    {
        free(anim->player_mr);
        anim->player_mr = NULL;
    }
    if (anim->player_dead)
    {
        free(anim->player_dead);
        anim->player_dead = NULL;
    }
    ft_free_anim_array(anim->enemy_cntdwn, (*graphics)->map->enemy_c);
    ft_free_anim_array(anim->enemy_explsn, (*graphics)->map->enemy_c);
    ft_free_anim_array(anim->numbers, ANIM_COUNT);
    free(anim->enemy_loops);
    anim->enemy_loops = NULL;
    free(anim);
    anim = NULL;
}

void ft_free_graphics(t_graphics **graphics)
{
    if (!graphics)
        return;
    if ((*graphics)->anim)
        ft_free_game_anim(graphics, (*graphics)->anim);
    (*graphics)->anim = NULL;
    if ((*graphics)->map)
        ft_free_map((*graphics)->map->height, &(*graphics)->map);
    (*graphics)->map = NULL;
    if ((*graphics)->mlx)
        mlx_terminate((*graphics)->mlx);
    (*graphics)->mlx = NULL;
}

