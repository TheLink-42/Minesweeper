NAME = msw

INC_DIR = inc
SRC_DIR = src/
OBJ_DIR = obj/

SRC =	$(SRC_DIR)Board.cpp				\
		$(SRC_DIR)Cell.cpp				\
		$(SRC_DIR)Game.cpp				\
		$(SRC_DIR)PosList.cpp			\
		$(SRC_DIR)UndoList.cpp			\
		$(SRC_DIR)inputOutput.cpp		\
		$(SRC_DIR)main.cpp

OBJ = $(SRC:$(SRC_DIR)%.cpp=$(OBJ_DIR)%.o)

CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -I $(INC_DIR)
RM = rm -rf

#------------------------------------------------------------------------------#

all: $(NAME)

$(NAME): $(SRC)
	@$(CPP) $(CPPFLAGS) $(SRC) -o $(NAME)
	@echo compiled

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@mkdir -p $(@D)
	@$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ_DIR)
	@echo "obj files removed"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(NAME) removed"


re: fclean all

.PHONY: all clean fclean re