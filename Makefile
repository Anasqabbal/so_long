NAME = so_long
# $(BONUS) = so_long_b

CC = cc
FLAGS = -Wall -Wextra -Werror
FILES = just_print.c
MAN = ./mandatory
O_FILES = $(FILES:$(MAN)/.c=$(MAN)/.o)
# FILES_B = ./bonus/
# O_FILES_B =
 all : $(NAME)

 $(NAME) : $(MAN)/$(O_FILES) $(MAN)/so_long.h
	$(CC) $(FLAGS) $(MAN)/so_long.c $(MAN)/$(O_FILES) -o $@
$(MAN)/%.o : $(MAN)/%.c
	$(CC) $(FLAGS) -c $(MAN)/$(FILES) -c $< 

clean :
	rm -f $(MAN)/$(O_FILES)

fclean : clean
	rm -f $(NAME)