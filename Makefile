NAME = mandatory
FILES = just_print.c
O_FILES = $(FILES:.c=.o)

all : $(NAME)

$(NAME) : ./mandatory/$(O_FILES) ./mandatory/so_long.c
	make -C ./mandatory

clean :
	$(MAKE) -C ./mandatory $@

fclean :
	$(MAKE) -C ./mandatory $@

re :
	$(MAKE) -C ./mandatory $@
