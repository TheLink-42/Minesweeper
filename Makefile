NAME = msw

INC_DIR = inc
SRC_DIR = src/
OBJ_DIR = obj/

SRC =	$(SRC_DIR)Tablero.cpp			\
		$(SRC_DIR)Celda.cpp				\
		$(SRC_DIR)Juego.cpp				\
		$(SRC_DIR)ListaPosiciones.cpp	\
		$(SRC_DIR)ListaUndo.cpp			\
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