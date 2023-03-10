#Colors------------------------------------------------------------
#\033[38;2;255;0;0m 38;2 indicates 24-bit color mode.
#                   255;0;0 amount of red, green, and blue
CYAN = \033[0;96m
ORANGE = \033[38;2;255;146;3m
RED = \033[38;2;255;0;0m
GREEN = \033[38;2;0;255;0m
PINK = \033[38;2;255;55;255m
L_VIOLET = \033[38;2;171;0;205m
VIOLET = \033[38;2;154;0;255m
RESET = \033[0m
#------------------------------------------------------------------

#Emojis-------------------------
EMOJI_HAPPY := \xF0\x9F\x98\x83
EMOJI_SAD := \xF0\x9F\x98\xA2
EMOJI_CELEBRATE := \xF0\x9F\x8E\x89
EMOJI_CLOCK := \xE2\x8F\xB0
EMOJI_ROBOT := \xF0\x9F\xA4\x96
SPARKS := \xE2\x9C\xA8
#--------------------------------

# Directories
LIBFT = ./libft

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIB = -L $(LIBFT) -lft
REMOVE = rm -f

# Source files
SRC = src/execute.c src/pipex.c src/utils.c src/files.c src/parsing.c src/main.c

# Object files
OBJ = $(SRC:src/%.c=obj/%.o)

# Binary name
NAME = pipex

all: header $(NAME)

$(NAME): $(OBJ)
	@echo "$(EMOJI_ROBOT)$(ORANGE)Compiling LIBFT...$(RESET)"
	make -C $(LIBFT)
	@echo "$(EMOJI_CLOCK)$(ORANGE)Compiling $(NAME)...$(RESET)"
	$(CC) $(CFLAGS) $(INC) -o $@ $^ $(LIB)
	@echo "$(EMOJI_HAPPY)$(GREEN)YEAH DONE ✓✓$(RESET)"

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
		@echo " $(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)"
		@echo " $(SPARKS)                                                        $(SPARKS)"
		@echo "$(PINK) $(SPARKS)    ∞∞∞∞∞  ∞∞∞          ∞                 ∞             $(SPARKS) $(RESET)"
		@echo "$(PINK) $(SPARKS)   ∞∞   ∞   ∞           ∞       ∞∞∞       ∞     ∞∞∞∞    $(SPARKS) $(RESET)"
		@echo "$(PINK) $(SPARKS)   ∞    ∞   ∞          ∞∞∞∞∞   ∞   ∞    ∞∞∞∞∞   ∞   ∞   $(SPARKS) $(RESET)"
		@echo "$(L_VIOLET) $(SPARKS)   ∞        ∞           ∞          ∞      ∞    ∞∞       $(SPARKS) $(RESET)"
		@echo "$(L_VIOLET) $(SPARKS)   ∞  ∞∞∞   ∞           ∞          ∞      ∞    ∞∞       $(SPARKS) $(RESET)"
		@echo "$(L_VIOLET) $(SPARKS)   ∞    ∞   ∞           ∞     ∞∞∞∞∞∞∞     ∞     ∞∞∞∞    $(SPARKS) $(RESET)"
		@echo "$(VIOLET) $(SPARKS)   ∞∞   ∞   ∞           ∞     ∞     ∞     ∞         ∞∞  $(SPARKS) $(RESET)"
		@echo "$(VIOLET) $(SPARKS)    ∞   ∞   ∞     ∞∞    ∞  ∞  ∞∞    ∞     ∞  ∞      ∞∞  $(SPARKS) $(RESET)"
		@echo "$(VIOLET) $(SPARKS)     ∞∞∞∞ ∞∞∞∞∞∞  ∞∞    ∞∞∞∞   ∞∞∞∞∞∞∞    ∞∞∞∞  ∞∞∞∞∞   $(SPARKS) $(RESET)"
		@echo " $(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)"
		@echo " $(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(RESET)$(CYAN)PIPEX PROJECT!$(RESET)$(CYAN)$(SPARKS)$(SPARKS)$(RESET)"

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

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes --trace-children=yes -s -q ./pipex ...

normlib:
	@echo "$(CYAN)\nChecking norm for Libft...$(RESET)\n"
	@norminette $(LIBFT) includes/ && echo "$(EMOJI_HAPPY)$(GREEN)Norm check passed!$(RESET)$(EMOJI_CELEBRATE)" || echo "$(EMOJI_SAD)$(RED)Norm check failed!$(RESET)$(EMOJI_SAD)"

norm:
	@echo "$(CYAN)\nChecking norm for Pipex...$(RESET)\n"
	@norminette $(SRC) includes/ && echo "$(EMOJI_HAPPY)$(GREEN)Norm check passed!$(RESET)$(EMOJI_CELEBRATE)" || echo "$(EMOJI_SAD)$(RED)Norm check failed!$(RESET)$(EMOJI_SAD)"

normall: normlib norm

.PHONY: all cleanobj clean fclean re
