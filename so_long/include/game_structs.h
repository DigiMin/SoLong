/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_structs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 09:41:29 by honnguye          #+#    #+#             */
/*   Updated: 2025/01/21 12:03:17 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_STRUCTS_H
# define GAME_STRUCTS_H
# include "game_enums.h"
# include <MLX42/MLX42.h>

typedef struct s_coord
{
	int				x;
	int				y;
	struct s_coord	*next;
}					t_coord;

typedef struct s_map
{
	int				height;
	int				width;
	char			**terrain;
	char			**visited;
	int				start_c;
	t_coord			*start;
	int				exit_c;
	t_coord			*exit;
	int				space_c;
	t_coord			*spaces;
	int				collectible_c;
	t_coord			*collectibles;
	int				wall_c;
	t_coord			*walls;
	int				enemy_c;
	t_coord			*enemy;
	int				collected;
	int				move_c;
}					t_map;

typedef struct s_anim
{
	int				anim_count;
	int				anim_frame;
	int				anim_speed;
	int				sleep;
	int				enabled;
	mlx_image_t		**anim_images;
}					t_anim;

typedef struct s_game_anim
{
	t_anim			*player_r;
	t_anim			*player_l;
	t_anim			*player_mr;
	t_anim			*player_ml;
	t_anim			*player_dead;
	t_anim			**enemy_cntdwn;
	t_anim			**enemy_explsn;
	t_anim			**numbers;
	int32_t			z_exit;
	int				*enemy_loops;
}					t_game_anim;

typedef struct s_graphics
{
	mlx_image_t		**player_l;
	mlx_image_t		**player_r;
	mlx_image_t		**player_ml;
	mlx_image_t		**player_mr;
	mlx_image_t		**player_dead;
	mlx_image_t		*enemy;
	mlx_image_t		**enemy_cntdwn;
	mlx_image_t		**enemy_explsn;
	mlx_image_t		*exit;
	mlx_image_t		*exit_open;
	mlx_image_t		*space;
	mlx_image_t		*collectable;
	mlx_image_t		*wall;
	mlx_image_t		**numbers;
	mlx_image_t		*num_bckgrnd;
	mlx_image_t		*cngrts;
	mlx_image_t		*failed;
	mlx_t			*mlx;
	t_map			*map;
	t_game_anim		*anim;
	t_anim_spec		last_anim_dir;
	int				can_move;
}					t_graphics;

#endif