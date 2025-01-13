/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:18:38 by honnguye          #+#    #+#             */
/*   Updated: 2025/01/13 14:30:48 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>
# include <MLX42/MLX42.h>
# include "get_next_line.h"

#define MAX_WIDTH 30
#define MAX_HEIGHT 16

#define IMG_SIZE 4
#define HALF_SIZE 32
#define OFFSET 24
#define OSET 44

#define PLAYER_SPEED 64
#define ANIM_COUNT 6
#define ANIM_SPEED 9

typedef struct t_coord {
	int x;
	int y;
	struct t_coord *next;
} t_coord;

typedef struct t_map {
	int 	height;
	int 	width;
	char 	**terrain;
	char	**visited;
	int 	start_c;
	t_coord *start;
	int 	exit_c;
	t_coord *exit;
	int 	space_c;
	t_coord *spaces;
	int 	collectible_c;
	t_coord *collectibles;
	int 	wall_c;
	t_coord *walls;
	int 	enemy_c;
	t_coord *enemy;
	int 	collected;
	int		move_c;
} t_map;

typedef struct t_anim {
	int anim_count;
	int anim_frame;
	int anim_speed;
	int sleep;
	int enabled;
	mlx_image_t **anim_images;
} t_anim;

typedef struct t_game_anim {
	t_anim *player_r;
	t_anim *player_l;
	t_anim *player_mr;
	t_anim *player_ml;
	t_anim *player_dead;
	t_anim **enemy_cntdwn;
	t_anim **enemy_explsn;
	t_anim **numbers;
	int32_t z_exit;
	int *enemy_loops;
} t_game_anim;

typedef struct t_graphics {
	mlx_image_t **player_l;
	mlx_image_t **player_r;
	mlx_image_t **player_ml;
	mlx_image_t **player_mr;
	mlx_image_t **player_dead;
	mlx_image_t *enemy;
	mlx_image_t **enemy_cntdwn;
	mlx_image_t **enemy_explsn;
	mlx_image_t *exit;
	mlx_image_t *space;
	mlx_image_t *collectable;
	mlx_image_t *wall;
	mlx_image_t **numbers;
	mlx_t *mlx;
	t_map *map;
	t_game_anim *anim;
	char last_key;
	int	can_move;
} t_graphics;

// helpers
t_coord	*ft_coord_new(int x, int y);
t_coord	*ft_coord_last(t_coord *lst);
void	ft_coords_clear(t_coord **lst);
void	ft_coord_add_back(t_coord **lst, t_coord *new);
t_coord	*ft_get_nth_coord(t_coord *lst, int n);
void	ft_coord_del_one(t_coord **lst, int n);
char	*ft_itoa(int n);
int	ft_get_random_spawn_index(t_map *map);


// map load validate
t_map	*ft_init_map(char *path);
t_map	*ft_map_parser(char *path);
void 	ft_free_map(int height, t_map *map);
// flood-fill funtions
void 	ft_free_matrix(char **arr, int height);
int		ft_is_playable(t_map *map);

// load graphics
char	*ft_multi_strjoin(int count, ...);
int	ft_allocate_aimg(t_graphics *graphics);
int	ft_set_map_img(t_graphics *graphics, t_map *map);
t_anim	*ft_set_anim_img(t_graphics *graphics, mlx_image_t **asset, char *path, t_coord *coord);
t_game_anim *ft_init_game_anim(t_graphics *graphics);
void 	ft_switch_display(t_anim *asset);
void	ft_spawn_enemies(t_graphics *graphics, char *path);

// graphics corrections
int	ft_switch_exit_z(void *param);

// draw functions
mlx_image_t		*ft_draw_asset(mlx_t *mlx, char *path, t_coord *asset);
mlx_image_t		*ft_draw_exit(mlx_t *mlx, char *path, t_coord *asset);
mlx_image_t		*ft_draw_enemy(mlx_t *mlx, char *path, t_coord *asset, mlx_image_t *enemy);
mlx_image_t		*ft_load_png(mlx_t *mlx, char *path);


void ft_animate(void *param, char c);
t_anim *ft_spec_anim(t_game_anim *anim, char spec, int instance);
void ft_move_player(t_graphics *graphics, char dia, int pix);
void ft_hook(void* param);
int	ft_is_space(t_graphics *graphics, int xm, int ym, char dia);
int	ft_collect(void* param);
int	ft_can_exit(void *param);

// enemy actions
int	ft_enemy_touched(void *param);
mlx_image_t **ft_set_anim_enemy_img(t_graphics *graphics, char *path, mlx_image_t **asset);
void ft_switch_enemy_display(t_graphics *graphics, t_anim *asset, int instance);
int	ft_enable_enemy_anim(t_graphics *graphics, t_game_anim *anim, char spec, int instance);
void ft_animate_enemy(t_graphics *graphics, char spec, int instance);
t_anim	*ft_set_anim_enemy(t_graphics *graphics, mlx_image_t **asset, char *path);
void ft_disable_enemy_instance(t_graphics *graphics, t_game_anim *anim, char spec, int instance);
void ft_disable_all_enemy_anim(t_graphics *graphics, t_game_anim *anim);
int	ft_is_player_near(t_graphics *graphics);
// int ft_set_multiple_anim_instances(t_graphics *graphics, mlx_image_t **animation, t_coord *coord);

// display move count
mlx_image_t **ft_draw_numbers(t_graphics *graphics);
t_anim **ft_set_counter(t_graphics *graphics);
void ft_switch_counter(t_anim **counter, int moves);

#endif