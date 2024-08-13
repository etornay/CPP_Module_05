BLUE	=\033[1;34m\033[7m
CYAN	=\033[1;36m\033[7m
GREEN	=\033[1;32m\033[7m
ORANGE	=\033[1;38;5;208m
PURPLE	=\033[1;38;5;129m
RED		=\033[1;31m
MAGENTA	=\033[1;35m\033[4m
YELLOW	=\033[1;33m
RESET	=\033[0m

NAME = Bureaucrat

SRC = 	Bureaucrat.cpp \
		main.cpp 

OBJ_DIR = obj
OBJ = $(SRC:%.cpp=$(OBJ_DIR)/%.o)

CC = clang++
FLAGS = -Wall -Werror -Wextra
STD = -std=c++98

$(NAME): $(OBJ)
	@echo "$(YELLOW)* Compiling. Please, wait...$(RESET)"
	@$(CC) $(FLAGS) $(STD) $(OBJ) -o $(NAME)
	@echo "  $(CYAN)PROGRAM READY$(RESET)"

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	@$(CC) $(FLAGS) $(STD) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

all: $(NAME)

clean:
	@echo "$(ORANGE)* Cleaning objects. Please, wait...$(RESET)"
	@rm -rf $(OBJ_DIR)
	@echo "  $(GREEN)DONE$(RESET)"

fclean: clean
	@echo "$(RED)* Cleaning all files. Please, wait...$(RESET)"
	@rm -f $(NAME)
	@echo "  $(GREEN)DONE$(RESET)"

re: fclean all

.PHONY: all re clean fclean