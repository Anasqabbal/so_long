NAME = so_long #../../so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
FILES =  so_long.c 0_valid_extension.c 1_valid_map.c\
		 1_valid_map1.c 2_open_start_window.c 2_0_render_the_map.c\
		 2_1_do_moves.c
O_FILES = $(FILES:.c=.o)
INCLUDES = -I/opt/X11/include -Imlx
MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit
LIBFT_PATH = ./libft/libft.a

all : lib $(NAME)

$(NAME) : $(O_FILES) $(LIBFT_PATH)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(LIBFT_PATH) $(O_FILES) -o $@

lib :
	$(MAKE) -C ./libft

%.o : %.c so_long.h ./libft/libft.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
 
clean :
	rm -f $(O_FILES)
	$(MAKE) -C ./libft $@

fclean : clean
	rm -f $(NAME)
	$(MAKE) -C ./libft $@

re : fclean all