CC		:= cc
NAME	:= so_long
CFLAGS	:= -g #-fsanitize=address#-Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX	:= ../MLX42/

HEADERS	:= -I ./include -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/mlx_build/libmlx42.a -ldl -lglfw -pthread -lm
SRCS	:= $(shell find ./src -iname "*.c")
OBJS	:= ${SRCS:.c=.o}

all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/mlx_build && make -C $(LIBMLX)/mlx_build -j4

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)
	@make clean

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/mlx_build

fclean: clean
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx