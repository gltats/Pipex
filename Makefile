#Colors--------------------
BLUE = \033[94m
ORANGE = \033[38;5;215m
RED = \033[31m
GREEN = \033[38;5;82m
RESET = \033[0m
#--------------------------

NAME = pipex

CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = pipex.c
REMOVE = rm -f

all: header $(NAME)

$(NAME):
	@echo "$(RESET)$(ORANGE)Compiling...$(RESET)"
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)
	@echo "$(RESET)$(GREEN)DONE ✓✓$(RESET)"
	
header:	
		@echo "$(BLUE)                           $(RESET)"
		@echo "$(BLUE)   ********  **       **********     **     **********  ********$(RESET)"
		@echo "$(BLUE)  **//////**/**      /////**///     ****   /////**///  **////// $(RESET)"
		@echo "$(BLUE) **      // /**          /**       **//**      /**    /**  $(RESET)"
		@echo "$(BLUE)/**         /**          /**      **  //**     /**    /*********$(RESET)"
		@echo "$(BLUE)/**    *****/**          /**     **********    /**    ////////**$(RESET)"
		@echo "$(BLUE)//**  ////**/**          /**    /**//////**    /**           /**$(RESET)"
		@echo "$(BLUE) //******** /********    /**    /**     /**    /**     ******** $(RESET)"
		@echo "$(BLUE)  ////////  ////////     //     //      //     //     ////////$(RESET)"
		@echo "$(RED)                                                                 IS COOL! $(RESET)"
		@echo "$(BLUE)                           $(RESET)"

clean:
	@echo "$(RESET)$(ORANGE)Cleaning object files...$(RESET)"
	${REMOVE}
	@echo "$(RESET)$(GREEN)CLEANED ✓✓$(RESET)"

fclean: clean
	@echo "$(RESET)$(ORANGE)Cleaning object files and program...$(RESET)"
	${REMOVE} $(NAME)
	@echo "$(RESET)$(GREEN)ALL CLEANED ✓✓$(RESET)"

re: fclean all

.PHONY: all bonus clean fclean re