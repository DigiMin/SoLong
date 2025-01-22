CC			= cc
AR			= ar
NAME		= so_long
CFLAGS		= -g -Wextra -Wall -Werror
AFLAGS		= -rcs
LIBMLX		= ../MLX42
OBJ_DIR		= obj
SRC_DIR		= src/
SRC_DIRS	= animation draw enemy error free_memory ft_gnl ft_printf helpers init_data map_parsing player
OBJ_SUBDIRS	= $(addprefix $(OBJ_DIR)/, $(SRC_DIRS))

HEADERS	= -I./include -I$(LIBMLX)/include
LIBS	= lib_so_long.a $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
OBJS	= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)/%.o,$(SRCS))
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
$(SRC_DIR)ft_printf/ft_printf.c\
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


all: lib_so_long.a libmlx.a $(OBJ_SUBDIRS) $(NAME)

$(OBJ_SUBDIRS):
	@mkdir -p $@

libmlx.a:
	@if [ ! -f $(LIBMLX)/mlx_build/libmlx42.a ]; then \
		cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4; \
	fi

lib_so_long.a: $(OBJS)
	@$(AR) $(AFLAGS) $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)

clean:
	@rm -rf $(OBJ_DIR)
	@rm -rf $(LIBMLX)/build
	@rm -f lib_so_long.a

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re libmlx lib_so_long $(OBJ_SUBDIRS)