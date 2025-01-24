#include "minesweeper.hpp"

int main( void )
{
	srand(time(NULL));
	t_game *game;
	game = new t_game;
	while(start_game(game));
	delete game;
	return(0);
}