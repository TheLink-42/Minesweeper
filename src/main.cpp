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
	undoList.delete_last();									//Se elimina el ultimo movimiento de nuestro listado de 
}															//movimientos

void	play(Game& game, int x, int y, UndoList& undoList)
{
	PosList	list;
	int		output;

	if (x == -1 && y == -1)				//En caso de recibir por entrada -1 -1 se ejecuta la rendicion
		game.set_forfeit();
	else
	{
		if (x == -2 && y == -2)			//En caso de recibir por entrada -2 -2 se intercambia entre el modo normal y
			game.switch_mode();			//el modo bandera
		else if (x == -3 && y == -3)	//En caso de recibir por entrada -3 -3 se deshace el ultimo movimiento realizado
			undo(game, undoList);
		else
		{
			output = game.play(x, y, list);		//En el resto de casos se ejecuta la jugada
			if (!output)						//Si su valor de retorno es 0, la jugada se ha realizado con exito
				undoList.add_last(list);
			else if (output == -1)				//Si su valor es -1, las coordenadas recibidas no son validas
				std::cout << RED << "Por favor, introduzca coordenadas validas" << RESET << std::endl;
			//Se podria implementar acciones especiales para los valores de retorno 1 y 2, los cuales indican el 
			//intento de una jugada sobre una casilla ya descubierta (1) y una casilla marcada (2)
		}
		display_game(game);			//Se muestra el tablero para que se pueda apreciar el resultado de la jugada realizada
	}
}