#Colors--------------------
BLUE = \033[94m
ORANGE = \033[38;5;215m
RED = \033[31m
GREEN = \033[38;5;82m
RESET = \033[0m
#--------------------------

# Directories
LIBFT = ./libft

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIB = -L $(LIBFT) -lft
REMOVE = rm -f

# Source files
SRC = src/execute.c src/pipex.c src/utils.c src/main.c

# Object files
OBJ = $(SRC:src/%.c=obj/%.o)

# Binary name
NAME = pipex

all: header $(NAME)

$(NAME): $(OBJ) $(GNL_OBJ)
	@echo "$(RESET)$(ORANGE)Compiling LIBFT...$(RESET)"
	make -C $(LIBFT)
	@echo "$(RESET)$(ORANGE)Compiling $(NAME)...$(RESET)"
	$(CC) $(CFLAGS) $(INC) -o $@ $^ $(LIB)
	@echo "$(RESET)$(GREEN)DONE ✓✓$(RESET)"

# This rule specifies that for each object file in $(OBJ), 
# make should look for a source file in the src directory with 
# the same name but with a .c extension, compile it into an object file and 
# put the result in the obj directory. 
# The | obj part tells make that the obj directory should be created first if it doesn't exist.
$(OBJ): obj/%.o : src/%.c | obj
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<


obj:
	@mkdir -p $@
	
header:	
		@echo "                                                    "
		@echo "$(BLUE)		 ___________________________________________________ $(BLUE)"
		@echo "$(BLUE)		|                                                   | $(BLUE)"
		@echo "$(BLUE)		|    *****  ***          *            *             | $(RESET)"
		@echo "$(BLUE)		|   *** **   **          *      **    *     ****    | $(RESET)"
		@echo "$(BLUE)		|   **  **   **         *****  **** *****   ****    | $(RESET)"
		@echo "$(BLUE)		|   **       **         *****  *  * *****  **  *    | $(RESET)"
		@echo "$(BLUE)		|   ** ***   **          *     ****   *    ****     | $(RESET)"
		@echo "$(BLUE)		|   ** ***   **          *    *****   *     ****    | $(RESET)"
		@echo "$(BLUE)		|   *** **   **    **    ** * **  *   **** **  **   | $(RESET)"
		@echo "$(BLUE)		|    ***** *****   **    **** ******  **** *****    | $(RESET)"
		@echo "$(BLUE)		|     **** *****   **    ****  *****  ***  *****    | $(RESET)"
		@echo "$(BLUE)		|___________________________________________________|$(RESET)"
		@echo "$(BLUE)		|__________________________________________$(RED)PROJECT!$(RESET)$(BLUE)_|$(RESET)"

cleanobj:
	$(RM) -r obj/

cleanlib:
	make clean -C $(LIBFT)

fcleanlib:
	make fclean -C $(LIBFT)

clean: cleanobj cleanlib
	@echo "$(RESET)$(ORANGE)Cleaning object files...$(RESET)"
	${REMOVE} $(OBJ)
	@echo "$(RESET)$(GREEN)CLEANED ✓✓$(RESET)"

fclean: clean fcleanlib
	@echo "$(RESET)$(ORANGE)Cleaning object files and program...$(RESET)"
	${REMOVE} $(NAME)
	@echo "$(RESET)$(GREEN)ALL CLEANED ✓✓$(RESET)"

re: fclean all

.PHONY: all cleanobj clean fclean re
