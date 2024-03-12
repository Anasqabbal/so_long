NAME = so_long
BONUS = so_long_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
FILES =  so_long.c 0_valid_extension.c 1_valid_map.c\
		 1_valid_map1.c 2_open_start_window.c 2_0_render_the_map.c\
		 2_1_do_moves.c ft_clear.c

FILESB =  so_long_bonus.c 0_valid_extension_bonus.c 1_valid_map_bonus.c\
		 1_valid_map1_bonus.c 2_open_start_window_bonus.c 2_0_render_the_map_bonus.c\
		 2_1_do_moves_bonus.c text_bonus.c enemies_bonus.c coins_bonus.c ft_clear_bonus.c
O_FILES = $(FILES:.c=.o)
O_FILESB = $(FILESB:_bonus.c=_bonus.o)
INCLUDES = -I/opt/X11/include
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit
LIBFT_PATH = ./libft/libft.a


all : lib $(NAME)

bonus : lib $(BONUS)

$(NAME) : $(O_FILES) $(LIBFT_PATH)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(LIBFT_PATH) $(O_FILES) -o $@

$(BONUS) : $(O_FILESB) $(LIBFT_PATH)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(LIBFT_PATH) $(O_FILESB) -o $@

lib :
	@$(MAKE) -C ./libft

%_bonus.o : %_bonus.c so_long_bonus.h ./libft/libft.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

%.o : %.c so_long.h ./libft/libft.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
 
clean :
	rm -f $(O_FILES)
	rm -f $(O_FILESB)
	@$(MAKE) -C ./libft $@

fclean : clean
	rm -f $(NAME)
	rm -f $(BONUS)
	@$(MAKE) -C ./libft $@

re : fclean all