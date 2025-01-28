NAME = msw

INC_DIR = inc
SRC_DIR = src/
OBJ_DIR = obj/

SRC =	$(SRC_DIR)main.cpp			\
		$(SRC_DIR)initialize.cpp	\
		$(SRC_DIR)difficulty.cpp	\
		$(SRC_DIR)board.cpp			\
		$(SRC_DIR)move.cpp			\
		$(SRC_DIR)display.cpp

OBJ = $(SRC:$(SRC_DIR)%.cpp=$(OBJ_DIR)%.o)

CPP = clang++
CPPFLAGS = -Wall -Wextra -Werror -I $(INC_DIR)
RM = rm -rf

#------------------------------------------------------------------------------#

all: $(NAME)

$(NAME): $(OBJ)
	@$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)
	@echo compiled

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@mkdir -p $(@D)
	@$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ_DIR)
	@echo "obj files removed"

fclean: clean
	$(RM) $(NAME)
	@echo "$(NAME) removed"


re: fclean all

.PHONY: all clean fclean re