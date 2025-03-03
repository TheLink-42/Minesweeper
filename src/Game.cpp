#include "Game.h"


////////////////////////////////////////////////////////////////////////////////
////																		////
////							CONSTRUCTORS								////
////																		////
////////////////////////////////////////////////////////////////////////////////

Game::Game(): board()
{
	movements = 0;
	mines = 0;
	exposed = 0;
	mine_exposed = false;
	mode = false;
}

Game::Game(int rows, int cols): board(rows, cols)
{
	movements = 0;
	mines = 0;
	exposed = 0;
	mine_exposed = false;
	mode = false;
}

Game::~Game()
{

}


////////////////////////////////////////////////////////////////////////////////
////																		////
////							GETTERS & SETTERS							////
////																		////
////////////////////////////////////////////////////////////////////////////////

int	Game::get_cols() const
{
	return board.get_cols();
}

int	Game::get_mines() const 
{
	return mines;
}

int	Game::get_movements() const 
{
	return movements;
}

int	Game::get_number(int row, int col) const
{
	return board.get_cell(row, col).get_number();
}

int	Game::get_rows() const
{
	return board.get_rows();
}

Board	Game::get_board() const
{
	return board;
}

bool	Game::get_mode() const
{
	return mode;
}

bool	Game::set_mine(int row, int col)
{
	Cell	cell;
	cell.set_mine();
	mines++;

	return board.set_cell(row, col, cell);
}

bool	Game::set_number(int row, int col, int n)
{
	Cell	cell;
	cell.set_number(n);

	return board.set_cell(row, col, cell);
}

bool	Game::set_forfeit()
{
	mine_exposed = true;

	return true;
}

////////////////////////////////////////////////////////////////////////////////
////																		////
////							MEMBER FUNCTIONS							////
////																		////
////////////////////////////////////////////////////////////////////////////////

bool	Game::is_valid(int row, int col) const
{
	return board.is_valid(row, col);
}

bool	Game::is_complete() const
{
	return (mines + exposed == board.get_rows() * board.get_cols());
}

bool	Game::exposed_mine() const
{
	return mine_exposed;
}


bool	Game::is_empty(int row, int col) const
{
	return board.get_cell(row, col).is_empty();
}

bool	Game::is_exposed(int row, int col) const
{
	return board.get_cell(row, col).get_exposed();
}

bool	Game::is_marked(int row, int col) const
{
	return board.get_cell(row, col).get_marked();
}

bool	Game::is_mine(int row, int col) const
{
	return board.get_cell(row, col).is_mine();
}

bool	Game::is_number(int row, int col) const
{
	return board.get_cell(row, col).is_number();
}


//Marcaje y desmarcaje de una casilla en funcion de su estado (marcada/no marcada)

bool	Game::mark(int row, int col)
{
	Cell	cell;
	bool	valid = board.is_valid(row, col);

	if (valid)
	{
		cell = board.get_cell(row, col);
		if(is_marked(row, col))
		{
			cell.unmark_cell();
			mines++;
		}
		else
		{
			cell.mark_cell();
			mines--;
		}
		board.set_cell(row, col, cell);
	}
	return valid;
}

//Oculta una casilla que este descubierta

bool	Game::hide(int row, int col)
{
	Cell	cell;
	bool	valid = board.is_valid(row, col);

	if (valid && board.get_cell(row, col).get_exposed())
	{
		cell = board.get_cell(row, col);
		cell.hide_cell();
		board.set_cell(row, col, cell);
		exposed--;
	}
	return valid;
}

//Activa y desactiva el interruptor para el modo banderas

bool	Game::switch_mode()
{
	mode = !mode;

	return true;
}

//"Elimina" el tablero (el cual elimina cada casilla) antes de "eliminar" el juego
void	Game::destroy()
{
	board.destroy();
	movements = 0;
	mines = 0;
	exposed = 0;
	mine_exposed = false;
}

void	Game::floodfill(int row, int col, PosList& list)
{
	Cell	cell;

	//Al ser una funcion recursiva, realizamos las comprobaciones pertinentes a cada casilla (cada llamada) para evaluar
	//posible descubrimiento (casilla valida, no descubierta y no marcada)
	if (board.is_valid(row, col) && !is_exposed(row, col) && !is_marked(row, col))
	{
		cell = board.get_cell(row, col);					//Una vez comprobada, hacemos una copia de la casilla y
		cell.expose_cell();									//la descubrimos, la añadimos al tablero y añadimos su
		board.set_cell(row, col, cell);						//posicion a nuestra lista de posiciones descubiertas
		exposed++;											//en este movimiento
		list.add_last(row, col);
		if (!get_number(row, col))							//En caso de que sea una casilla de numero 0, hacemos una 
		{													//llamada de la funcion recursiva con cada casilla adyacente
			for (int r = row - 1; r <= row + 1; r++)
			{
				for (int c = col - 1; c <= col + 1; c++)
				{
					if (r == row && c == col)				//En este caso, la casilla central ya esta evaluada por lo que la 
						continue;							//saltamos
					floodfill(r, c, list);
				}
			}
		}
	}
}

int		Game::play(int row, int col, PosList& list)
{
	int		output = 0;
	Cell	cell;

	//Se gestionan posibles escenarios y errores con distintos valores de salida, permitiendo trabajar cada 
	//escenario de forma individual

	if (!board.is_valid(row, col))			//Casilla no valida, devuelve -1
		output = -1;

	else if (is_exposed(row, col))			//Casilla ya descubierta, devuelve 1
		output = 1;

	else if (mode)							//En caso de estar en modo banderas, marca o desmarca la casilla en funcion de
		mark(row, col);						//su estado anterior

	else if (is_marked(row, col))			//Si es una casilla ya marcada y se intenta descubrir, devuelve 2
		output = 2;
	else									//Modo banderas apagado y sin estar marcada/descubierta la casilla, procedemos
	{										//a realizar el movimiento
		movements++;
		cell = board.get_cell(row, col);	
		cell.expose_cell();					//Creamos una copia de la casilla existente y la descubrimos

		if (is_mine(row, col))				//En caso de mina, actualizamos los valores respectivos para indicar mina explotada,
		{									//reemplazamos la casilla cubierta por la casilla descubierta y añadimos sus
			mine_exposed = true;			//coordenadas a la lista de casillas descubiertas en este movimiento
			board.set_cell(row, col, cell);
			list.add_last(row, col);
			exposed++;
		}

		else if (!get_number(row, col))		//En caso de ser una casilla con un 0, llamamos a la funcion recursiva para
			floodfill(row, col, list);		//descubrir todas sus adyacentes

		else								//En caso de ser un numero distinto de 0, descubrimos la casilla y añadimos sus
		{									//coordenadas a la lista de casillas descubiertas en este movimiento
			board.set_cell(row, col, cell);
			list.add_last(row, col);
			exposed++;
		}
	}
	return output;
}

