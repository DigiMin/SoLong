NAME = libftprintf.a
CC = cc
CFLAGS = #-Wall -Wextra -Werror
AR = ar
AFLAGS = rcs
CURR_FILE = ft_printf.c
ifeq (current, $(firstword $(MAKECMDGOALS)))
OBJ = $(patsubst %.c, %.o, $(filter-out $(CURR_FILE), $(SRC)))
else
OBJ = $(patsubst %.c, %.o, $(SRC))
endif
SRC =\
ft_printf.c\
ft_wchar.c\
ft_wstr.c\
ft_wdec.c\
ft_strlen.c\
ft_itoa.c\
ft_whex.c\
ft_con_tohex_a.c

.PHONY: all clean fclean re libft $(NAME) current
.DEFAULT_GOAL: re

all: libft $(NAME)

%.o : %.c
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -c $< -o $@ 
	@echo "Object file $@ created"

$(NAME): $(OBJ)
	@echo "Creating $@"
	@$(AR) $(AFLAGS) $@ $^ f../../include/t_printf.h
	@echo "Created $@"

re: fclean all

current: libft $(NAME)
	@echo "Compiling $(CURR_FILE)"
	@$(CC) $(CFLAGS) $(CURR_FILE) libftprintf.a
	@echo "File $(CURR_FILE) compiled, please run: ./a.out"

fclean:
	@echo "Cleaning up all compiled files"
	@rm -f *.o *.a
	@echo "Printf repo cleaned up"

clean:
	@echo "Removing all objects"
	@rm -f *.o
	@echo "Printf objects removed"