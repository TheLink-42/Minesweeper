#include "Game.h"
#include "inputOutput.h"

/*
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
	*/

int main( void )
{
	Game	game;
	
	display_header();
	load_game(game);
	display_game(game);

	cout << endl << endl;
	display_result(game);
	return 0;
}