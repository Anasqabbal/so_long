NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
FILES =  just_print.c so_long_parsing.c 0_open_window.c
O_FILES = $(FILES:.c=.o)
MLX = -Lmlx -lmlx -framework OpenGL -framework AppKit
# INCLUDES = -I/opt/X11/include -Imlx
# MLX_FLAGS = -Lmlx -lmlx -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit
LIBFT = ./libft/libft.a

all : $(NAME)

$(NAME) : lib $(O_FILES) so_long.h 
	$(CC) $(CFLAGS) so_long.c $(MLX) $(LIBFT) $(O_FILES) -o $@

lib :
	$(MAKE) -C ./libft

%.o : %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@
 
clean :
	rm -f $(O_FILES)
	$(MAKE) -C ./libft $@

fclean : clean
	rm -f $(NAME)
	$(MAKE) -C ./libft $@

re : fclean all