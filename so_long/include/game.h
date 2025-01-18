/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 09:37:11 by honnguye          #+#    #+#             */
/*   Updated: 2025/01/18 10:37:24 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H
# include "ft_printf.h"
# include "game_enums.h"
# include "game_structs.h"
# include "get_next_line.h"
# include <MLX42/MLX42.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define NAME "Whole New World"
# define MAX_WIDTH 30
# define MAX_HEIGHT 16

# define IMG_SIZE 64
# define HALF_SIZE 32
# define OFFSET 24
# define OSET 44

# define PLAYER_SPEED 4
# define ANIM_COUNT 6
# define ANIM_SPEED 9

// ----------------GAME LOOP---------------

void		ft_hook(void *param);

// -------------INIT/SET DATA--------------

// map
t_map		*ft_init_map(char *path);
void		ft_init_map_vals(t_map *map);
int			ft_appnd_coord(int x, int y, t_map *map);
int			ft_appnd_spaces(int x, int y, t_map *map);
void		ft_count_assets(int x, int y, t_map *map);

// sprites
int			ft_alloc_player_imgs(t_graphics *graphics);
int			ft_alloc_enemy_anim_arr(t_game_anim *anim, int count);
void		ft_init_anim_img(t_anim *anim);
t_anim		*ft_init_enemy_anim(mlx_image_t **asset);
int			ft_init_all_enemy_anim(t_graphics *graphics, t_game_anim *anim,
				int i);

// counter
t_anim		**ft_set_counter(t_graphics *graphics);

// graphics
int			ft_init_graphics(t_graphics *graphics, char *path);

// ----------------MLX DRAW----------------

// draw image paths
int			ft_set_map_img(t_graphics *graphics, t_map *map);
void		ft_draw_numbers(t_graphics *graphics);
int			ft_set_all_enemy_img(t_graphics *graphics);
int			ft_set_enemy(t_graphics *graphics, t_game_anim *anim);
t_game_anim	*ft_set_player_anim(t_graphics *graphics);

// mlx image to window
mlx_image_t	**ft_draw_enemies(t_graphics *graphics, char *path,
				mlx_image_t **asset);
mlx_image_t	*ft_draw_asset(mlx_t *mlx, char *path, t_coord *asset);
mlx_image_t	*ft_draw_asset(mlx_t *mlx, char *path, t_coord *asset);
mlx_image_t	*ft_draw_exit(mlx_t *mlx, char *path, t_coord *asset);
mlx_image_t	*ft_draw_number(t_graphics *graphics, char *path);
t_anim		*ft_draw_player(t_graphics *graphics, mlx_image_t **asset,
				char *path, t_coord *coord);

// mlx texture to mlx image
mlx_image_t	*ft_load_png(mlx_t *mlx, char *path);

// --------------MAP PARSING---------------

// map validation
int			ft_check_extension(char *path);
int			ft_map_parser(t_map *map);

// flood-fill function
int			ft_is_playable(t_map *map);

// ---------------ANIMATION----------------

// universal animation helpers
t_anim		*ft_spec_anim(t_game_anim *anim, t_anim_spec spec, int instance);
void		ft_animate(void *param, t_anim_spec spec);
void		ft_switch_display(t_anim *asset);

// player animation - more in player actions
int			ft_enable_anim(t_game_anim *anim, t_anim_spec spec);

// enemy animation - more in enemy actions
void		ft_animate_enemy(t_graphics *graphics, t_anim_spec spec, int i);
int			ft_enable_enemy_anim(t_graphics *graphics, t_anim_spec spec, int i);
void		ft_disable_all_enemy_anim(t_graphics *graphics, t_game_anim *anim);
void		ft_disable_enemy_instance(t_game_anim *anim, t_anim_spec spec,
				int i);
void		ft_switch_enemy_display(t_graphics *graphics, t_anim *asset,
				int ins);

// -------------PLAYER ACTIONS-------------

// player movement
void		ft_move_player(t_graphics *graphics, t_axes dia, int pix);
void		ft_idle(t_graphics *graphics);
void		ft_move_left(t_graphics *graphics);
void		ft_move_right(t_graphics *graphics);
void		ft_move_up(t_graphics *graphics);
void		ft_move_down(t_graphics *graphics);

// movement counter update
void		ft_switch_counter(t_anim **counter, int moves);

// walk behind/in front of tower
int			ft_switch_exit_z(void *param);

// actions
int			ft_collect(void *param);
int			ft_can_exit(void *param);

// -------------ENEMY ACTIONS--------------

// enemy random spawn
int			ft_add_enemy(t_map *map);
int			ft_spawn_enemies(t_map *map);
int			ft_get_max_enemy_count(t_map *map);
int			ft_get_random_spawn_index(t_map *map);
int			ft_is_enemy_spawnable(t_map *map, t_coord *coord);
int			ft_not_around_player(t_map *map, t_coord *coord);

// enemy actions
void		ft_enemy_handler(t_graphics *graphics);
int			ft_enemy_touched(void *param);
void		ft_explode(t_graphics *graphics, int i);
int			ft_is_exploding(t_graphics *graphics);

// -----------MEMORY MANAGEMENT------------
void		ft_free_map(int height, t_map *map);
void		ft_free_matrix(char **arr, int height);

// -------------ERROR HANDLING-------------
char		*ft_error_map(t_error err);
char		*ft_error_str(t_error err);

// -----------HELPERS/UTILITIES------------

// coord helpers
void		ft_coord_add_back(t_coord **lst, t_coord *new);
void		ft_coords_clear(t_coord **lst);
t_coord		*ft_coord_last(t_coord *lst);
t_coord		*ft_coord_new(int x, int y);
t_coord		*ft_get_nth_coord(t_coord *lst, int n);

// multi string join
char		*ft_multi_strjoin(int count, ...);

#endif