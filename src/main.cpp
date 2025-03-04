#include "Game.h"
#include "UndoList.h"
#include "inputOutput.h"


void	play(Game& game, int x, int y, UndoList& list);
void	undo(Game& game, UndoList& undoList);

int main( void )
{
	Game		game;
	UndoList	undo;
	int			x,y;
	
	display_intro();
	if (load_game(game))			//Solo ejecutará el juego en caso de que el archivo se haya cargado correctamente
	{
		display_game(game);

		while (!game.is_complete() && !game.exposed_mine())		//Bucle de ejecucion que finaliza con todas las casillas
		{														//descubiertas o una mina explotada
			ask_pos(x, y);										//Se piden las coordenadas
			play(game, x, y, undo);								//Se ejecuta la accion correspondiente a dichas coordenadas
		}
		display_result(game);
		game.destroy(); //Cuando implementemos memoria dinamica será util
		undo.destroy(); //Cuando implementemos memoria dinamica será util
	}

	return 0;
}

void	undo(Game& game, UndoList& undoList)
{
	PosList	list = undoList.get_last();						//Se obtiene un listado y el numero de todas las casillas 
	int		tiles = list.get_length(); 						//descubiertas en el ultimo movimiento
	for (int i = 0; i < tiles; i++)
		game.hide(list.get_posx(i), list.get_posy(i));		//Se cubren cada una de las casillas descubiertas
}

void	play(Game& game, int x, int y, UndoList& undoList)
{
	PosList	list;
	int		output;

	if (x == -3 && x == -3)
		undo(game, undoList);
	else
	{
		output = game.play(x, y, list);
		if (!output)
			undoList.add_last(list);
		else if (output == -1)
			std::cout << RED << "Por favor, introduzca coordenadas validas" << RESET << std::endl;
	}
	display_game(game);			//Se muestra el tablero para que se pueda apreciar el resultado de la jugada realizada
}