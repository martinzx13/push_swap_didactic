#Creating the executable file. 
NAME:=push_swap
CHEL:=checker_linux
#Flags and C compiler.
CC:=cc
CFLAGS:= -Wall -Wextra -Werror

#Sources Files, to run the project.
SRC:= push_swap.c ft_split.c ft_error_display.c ft_libft_fun.c \
	  ft_swap_instructions_a.c ft_swap_instructions_b.c ft_sort_algoritm.c \
	  ft_utilities.c ft_rotate_calculation_a.c ft_rotate_calculation_b.c \
	  ft_push.c ft_free.c ft_check_num.c

#some test cases for the Valgrind memory leack checker.
ARG0:= "49 55 44 7 87 92 2 26 24 51 16 53 99 67 91 15 72 83 97 1"
ARG1:= "64 85 39 66 38 3 52 98 96 74 61 75 84 22 70 48 50 93 18 81 49 55 44 7 87 92 2 26 24 51 16 53 99 67 91 15 72 83 97 1"
ARG2:= "0  46 17 8 37 71 10 60 33 65 86 64 85 39 66 38 3 52 98 96 74 61 75 84 22 70 48 50 93 18 81 49 55 44 7 87 92 2 26 24 51 16 53 99 67 91 15 72 83 97 1"
ARG3:= "49 7 55 44 7 87 92 2 26 24 51 16 53 99 67 91 15 72 83 97 1"
ARG4:= "49 55 44 7 87 92 2 26 24 51 16 53 99 67 91 15 72 83 97 1 fdsfsd"
# OUT1 := $(shell ./$(NAME) $(ARG0) | ./$(CHEL) $(ARG0))
# OUT2 := $(shell ./$(NAME) $(ARG1) | ./$(CHEL) $(ARG1))
# OUT3 := $(shell ./$(NAME) $(ARG2) | ./$(CHEL) $(ARG2))

#Files #Objects Conversion. 
OBJ:= $(SRC:.c=.o)

# Colors for terminal output
GREEN := \033[0;32m
RED := \033[0;31m
YELLOW := \033[0;33m
NC := \033[0m

#Comands to create the executable. 
$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $@ $(OBJ)
	@echo "$(GREEN) Succesfully Build $(NAME)$(NC) $(GREEN)[...ok]"

#Rule to compile .c files to .o files 
%.o: %.C
	@$(CC) $(CFLAGS) -c $< -o $@

# Rule to build all targets. 
all: $(NAME)

#Rule to clean object files. 
clean: 
	@rm -f $(OBJ)
	@echo "$(YELLOW) ---- Cleaned Object Files ----$(NC) $(GREEN)[...ok]"

fclean: clean
	@rm -f $(NAME)
	@echo "$(YELLOW) ---- Cleaned excecutable ---- $(NAME) $(NC) $(GREEN)[...ok]"

# Valgrind rule to check for memory leaks. 
valgrind: $(NAME)
	@echo "$(YELLOW) ...Checking the memory leaks with Valgrind $(GREEN)[...ok]"
	@valgrind --leak-check=full ./$(NAME) $(ARG1) | wc -l || true
	@valgrind --leak-check=full ./$(NAME) $(ARG3) || true
	@valgrind --leak-check=full ./$(NAME) $(ARG4) || true


#some test
test:$(NAME)
	@echo "$(YELLOW) --------- Running some internal tests for the evaluation ---------$(GREEN)[...ok]"
	@echo $(OUT2)
	@echo $(OUT3)

#Rule to compile eveything from scratch.
re: fclean all


# .PHONY rules (non-file targets)
.PHONY: all clean fclean re valgrind