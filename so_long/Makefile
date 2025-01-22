CC		= cc
AR		= ar
NAME	= so_long
CFLAGS	= -g -Wextra -Wall -Werror -Wunreachable-code -Ofast
AFLAGS	= -rcs
LIBMLX	= ../MLX42/
SRC_DIR = ./src/
OBJ_DIR = ./obj/

HEADERS	= -I ./include/ft_printf.h ./include/game_enums.h ./include/game_structs.h ./include/game.h ./include/get_next_line.h -I $(LIBMLX)/include
LIBS	= lib_so_long.a $(LIBMLX)/mlx_build/libmlx42.a -ldl -lglfw -pthread -lm
OBJS	= $(patsubst %.c,$(OBJ_DIR)%.o,$(SRCS))
SRCS	= \
$(SRC_DIR)animation/animation.c\
$(SRC_DIR)animation/enemy_anim.c\
$(SRC_DIR)animation/player_anim.c\
$(SRC_DIR)draw/assets_draw.c\
$(SRC_DIR)draw/counter_draw.c\
$(SRC_DIR)draw/draw_png.c\
$(SRC_DIR)draw/enemy_draw.c\
$(SRC_DIR)draw/game_anim_draw.c\
$(SRC_DIR)draw/player_draw.c\
$(SRC_DIR)enemy/enemy_actions.c\
$(SRC_DIR)enemy/enemy_spawn_helpers.c\
$(SRC_DIR)enemy/enemy_spawn.c\
$(SRC_DIR)error/error_strings.c\
$(SRC_DIR)error/error.c\
$(SRC_DIR)free_memory/memory_handeling_helpers.c\
$(SRC_DIR)free_memory/memory_handeling.c\
$(SRC_DIR)ft_gnl/ft_get_next_line_utils.c\
$(SRC_DIR)ft_gnl/ft_get_next_line.c\
$(SRC_DIR)ft_printf/ft_wchar.c\
$(SRC_DIR)ft_printf/ft_wstr.c\
$(SRC_DIR)ft_printf/ft_wdec.c\
$(SRC_DIR)ft_printf/ft_strlen.c\
$(SRC_DIR)ft_printf/ft_itoa.c\
$(SRC_DIR)ft_printf/ft_whex.c\
$(SRC_DIR)ft_printf/ft_con_tohex_a.c\
$(SRC_DIR)helpers/map_coords_helpers.c\
$(SRC_DIR)helpers/multi_strjoin.c\
$(SRC_DIR)init_data/counter_init.c\
$(SRC_DIR)init_data/enemy_init.c\
$(SRC_DIR)init_data/graphics_init.c\
$(SRC_DIR)init_data/map_init_helpers.c\
$(SRC_DIR)init_data/map_init.c\
$(SRC_DIR)init_data/structs_init.c\
$(SRC_DIR)init_data/structs_malloc.c\
$(SRC_DIR)map_parsing/map_is_playable.c\
$(SRC_DIR)map_parsing/map_parser.c\
$(SRC_DIR)player/movement_counter_switch.c\
$(SRC_DIR)player/player_actions.c\
$(SRC_DIR)player/player_move_directions.c\
$(SRC_DIR)player/player_move.c\
$(SRC_DIR)player/walk_behind_exit.c\
$(SRC_DIR)main_game_hook.c\
$(SRC_DIR)so_long.c


all: $(NAME)

libmlx.a:
	@if [ ! -f $(LIBMLX)/mlx_build/libmlx.a ]; then cmake -DDEBUG=1 $(LIBMLX) -B $(LIBMLX)/mlx_build && make -C $(LIBMLX)/mlx_build -j4; fi

lib_so_long.a: $(OBJS)
	@$(AR) $(AFLAGS) $@ $^ $(HEADERS)

%.o: $(SRC_DIR)%.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(LIBS)

clean:
	@rm -rf $(OBJ_DIR)/*.o
	@rm -rf $(LIBMLX)/mlx_build

fclean: clean
	@rm -rf $(NAME)

re: clean all

.PHONY: all clean fclean re libmlx lib_so_long