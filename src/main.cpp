#include "Game.h"
#include "UndoList.h"
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

void	play(Game& game, int x, int y, UndoList& list);

int main( void )
{
	Game		game;
	UndoList	undo;
	int			x,y;
	
	display_intro();
	if (load_game(game))
	{
		display_game(game);

		while (!game.is_complete() && !game.exposed_mine())
		{
			ask_pos(x, y);
			play(game, x, y, undo);
		}
		display_result(game);
	}

	return 0;
}

void	undo(Game& game, UndoList& undoList)
{
	PosList	list = undoList.get_last();
	int		tiles = list.get_length();
	for (int i = 0; i < tiles; i++)
		game.hide(list.get_posx(i), list.get_posy(i));
	undoList.delete_last();
}

void	play(Game& game, int x, int y, UndoList& undoList)
{
	PosList	list;
	int		output;

	if (x == -1 && y == -1)
		game.set_forfeit();
	else
	{
		if (x == -2 && y == -2)
			game.switch_mode();
		else if (x == -3 && y == -3)
			undo(game, undoList);
		else
		{
			output = game.play(x, y, list);
			if (!output)
				undoList.add_last(list);
			else if (output == -1)
				cout << RED << "Please, restrain coordinates to valid ones" << RESET << endl;
		}
		display_game(game);
	}
}