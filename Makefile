NAME = so_long
MANDATORY = mandatory
BONUS = bonus

MANDATORY_PATH = ./mandatory/game_logic/

all :
	$(MAKE) -C $(MANDATORY_PATH)

clean :
	$(MAKE) -C $(MANDATORY_PATH) $@

fclean :
	$(MAKE) -C $(MANDATORY_PATH) $@

re : fclean all
