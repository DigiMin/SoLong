/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:18:38 by honnguye          #+#    #+#             */
/*   Updated: 2025/01/17 11:52:54 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H
# include "ft_printf.h"
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

typedef enum e_error
{
	INSTANCE_NOT_TOUCHED = -1,
	SUCCESS,
	FAILURE,
	MALLOC,
	OPEN,
	READ,
	INIT_FAILED,
	WRONG_EXTENSION,
	WRONG_MAP_SIZE,
	NOT_RECTANGULAR,
	NOT_FRAMED,
	WRONG_CHARS,
	NOT_PLAYABLE,
	NOT_NEAR,
	MLX_FAILURE,
	MLX_DRAW_FAILURE
}					t_error;

typedef enum e_axes
{
	X,
	Y
}					t_axes;

typedef enum e_anim_spec
{
	PLAYER_R,
	PLAYER_L,
	PLAYER_MR,
	PLAYER_ML,
	PLAYER_DEAD,
	ENEMY_CNTDWN,
	ENEMY_EXPLSN,
	ENEMY_NOT_SPAWNABLE
}					t_anim_spec;

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
	mlx_image_t		*space;
	mlx_image_t		*collectable;
	mlx_image_t		*wall;
	mlx_image_t		**numbers;
	mlx_t			*mlx;
	t_map			*map;
	t_game_anim		*anim;
	t_anim_spec		last_anim_dir;
	int				can_move;
}					t_graphics;

// init graphics
int					ft_init_graphics(t_graphics *graphics, char *path);
int					ft_check_extension(char *path);
void				error(void);

// helpers
t_coord				*ft_coord_new(int x, int y);
t_coord				*ft_coord_last(t_coord *lst);
void				ft_coords_clear(t_coord **lst);
void				ft_coord_add_back(t_coord **lst, t_coord *new);
t_coord				*ft_get_nth_coord(t_coord *lst, int n);
char				*ft_itoa(int n);
char				*ft_multi_strjoin(int count, ...);

// map load validate
t_map				*ft_init_map(char *path);
int					ft_map_parser(t_map *map);
void				ft_free_map(int height, t_map *map);
// flood-fill funtions
void				ft_free_matrix(char **arr, int height);
int					ft_is_playable(t_map *map);

// draw utilities, load png
mlx_image_t			*ft_draw_asset(mlx_t *mlx, char *path, t_coord *asset);
mlx_image_t			*ft_draw_exit(mlx_t *mlx, char *path, t_coord *asset);
mlx_image_t			*ft_draw_number(t_graphics *graphics, int number);
mlx_image_t			*ft_load_png(mlx_t *mlx, char *path);

// load graphics
t_game_anim			*ft_init_player_anim(t_graphics *graphics);
t_anim				*ft_set_anim_img(t_graphics *graphics, mlx_image_t **asset,
						char *path, t_coord *coord);
int					ft_set_map_img(t_graphics *graphics, t_map *map);
int					ft_allocate_aimg(t_graphics *graphics);
void				ft_switch_display(t_anim *asset);
int					ft_add_enemy(t_map *map);
int					ft_spawn_enemies(t_map *map);

// enemy spawn
mlx_image_t			**ft_set_enemy_img(t_graphics *graphics, char *path,
						mlx_image_t **asset);
t_anim				*ft_init_enemy_anim(mlx_image_t **asset);

// enemy display

int					ft_alloc_enemy_anim_arr(t_game_anim *anim, int count);
int					ft_set_enemy(t_graphics *graphics, t_game_anim *anim);
int					ft_set_all_enemy_img(t_graphics *graphics);
void				ft_init_anim_img(t_anim *anim);
int					ft_init_all_enemy_anim(t_graphics *graphics,
						t_game_anim *anim, int i);

// main hook - movement restrictions
void				ft_hook(void *param);

// Player appearing to walk behind the tower
int					ft_switch_exit_z(void *param);

// player animations
void				ft_animate(void *param, t_anim_spec c);
t_anim				*ft_spec_anim(t_game_anim *anim, t_anim_spec spec,
						int instance);
void				ft_move_player(t_graphics *graphics, t_axes dia, int pix);
int					ft_collect(void *param);
int					ft_can_exit(void *param);
int					ft_enable_anim(t_game_anim *anim, t_anim_spec spec);

// enemy actions
void				ft_animate_enemy(t_graphics *graphics, t_anim_spec spec,
						int i);
int					ft_enemy_touched(void *param);
void				ft_switch_enemy_display(t_graphics *graphics, t_anim *asset,
						int i);
int					ft_enable_enemy_anim(t_graphics *graphics, t_anim_spec spec,
						int i);
void				ft_disable_enemy_instance(t_game_anim *anim,
						t_anim_spec spec, int i);
void				ft_disable_all_enemy_anim(t_graphics *graphics,
						t_game_anim *anim);
int					ft_is_enemy_near(t_graphics *graphics);
void				ft_explode(t_graphics *graphics, int i);

int					ft_get_max_enemy_count(t_map *map);
int					ft_get_random_spawn_index(t_map *map);
int					ft_is_enemy_spawnable(t_map *map, t_coord *coord);
int					ft_not_around_player(t_map *map, t_coord *coord);

// MOVES
void				ft_idle(t_graphics *graphics);
void				ft_move_left(t_graphics *graphics);
void				ft_move_right(t_graphics *graphics);
void				ft_move_up(t_graphics *graphics);
void				ft_move_down(t_graphics *graphics);

// display move count
void				ft_draw_numbers(t_graphics *graphics);
t_anim				**ft_set_counter(t_graphics *graphics);
void				ft_switch_counter(t_anim **counter, int moves);

#endif