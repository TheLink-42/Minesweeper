#include "Juego.h"


////////////////////////////////////////////////////////////////////////////////
////																		////
////							CONSTRUCTORS								////
////																		////
////////////////////////////////////////////////////////////////////////////////

Juego::Juego(): tablero()
{
	num_jugadas = 0;
	num_minas = 0;
	num_descubiertas = 0;
	mina_pisada = false;
	display_mines = 0;
	mode = false;
}

Juego::Juego(int rows, int cols): tablero(rows, cols)
{
	num_jugadas = 0;
	num_minas = 0;
	num_descubiertas = 0;
	mina_pisada = false;
	display_mines = 0;
	mode = false;
}

Juego::~Juego()
{

}


////////////////////////////////////////////////////////////////////////////////
////																		////
////							GETTERS & SETTERS							////
////																		////
////////////////////////////////////////////////////////////////////////////////

int	Juego::dame_num_columnas() const
{
	return tablero.num_columnas();
}

int	Juego::dame_num_minas() const 
{
	return num_minas;
}

int	Juego::get_display_mines() const 
{
	return display_mines;
}

int	Juego::dame_num_jugadas() const 
{
	return num_jugadas;
}

int	Juego::dame_numero(int fila, int col) const
{
	return tablero.dame_celda(fila, col).dame_numero();
}

int	Juego::dame_num_filas() const
{
	return tablero.num_filas();
}

bool	Juego::get_mode() const
{
	return mode;
}

bool	Juego::poner_mina(int fila, int col)
{
	Celda	celda;
	bool	output;


	celda.poner_mina();
	output = tablero.poner_celda(fila, col, celda);
	num_minas++;
	display_mines++;

	for (int r = fila - 1; r <= fila + 1; r++)
	{
		for (int c = col - 1; c <= col + 1; c++)
		{
			if (tablero.es_valida(r, c) && !contiene_mina(r, c))
			{
				celda = tablero.dame_celda(r, c);
				celda.poner_numero(celda.dame_numero() + 1);
				tablero.poner_celda(r, c, celda);
			}
		}
	}

	return output;
}

////////////////////////////////////////////////////////////////////////////////
////																		////
////							MEMBER FUNCTIONS							////
////																		////
////////////////////////////////////////////////////////////////////////////////


bool	Juego::esta_completo() const
{
	return (num_minas + num_descubiertas == tablero.num_filas() * tablero.num_columnas());
}

bool	Juego::mina_explotada() const
{
	return mina_pisada;
}


bool	Juego::esta_vacia(int fila, int col) const
{
	return tablero.dame_celda(fila, col).esta_vacia();
}

bool	Juego::esta_descubierta(int fila, int col) const
{
	return tablero.dame_celda(fila, col).esta_descubierta();
}

bool	Juego::esta_marcada(int fila, int col) const
{
	return tablero.dame_celda(fila, col).esta_marcada();
}

bool	Juego::contiene_mina(int fila, int col) const
{
	return tablero.dame_celda(fila, col).contiene_mina();
}

bool	Juego::contiene_numero(int fila, int col) const
{
	return tablero.dame_celda(fila, col).contiene_numero();
}


//Marcaje y desmarcaje de una casilla en funcion de su estado (marcada/no marcada)

bool	Juego::marcar_desmarcar(int fila, int col)
{
	Celda	celda;
	bool	valid = tablero.es_valida(fila, col);

	if (valid)
	{
		celda = tablero.dame_celda(fila, col);
		if(esta_marcada(fila, col))
		{
			celda.desmarcar_celda();
			display_mines++;
		}
		else
		{
			celda.marcar_celda();
			display_mines--;
		}
		tablero.poner_celda(fila, col, celda);
	}
	return valid;
}

//Oculta una casilla que este descubierta

bool	Juego::ocultar(int fila, int col)
{
	Celda	celda;
	bool	valid = tablero.es_valida(fila, col);

	if (valid && tablero.dame_celda(fila, col).esta_descubierta())
	{
		celda = tablero.dame_celda(fila, col);
		celda.ocultar_celda();
		tablero.poner_celda(fila, col, celda);
		num_descubiertas--;
	}
	return valid;
}

bool	Juego::swap_mode()
{
	mode = !mode;
	return mode;
}


//"Elimina" el tablero (el cual elimina cada casilla) antes de "eliminar" el juego
void	Juego::destruye()
{
	tablero.destruye();
	num_jugadas = 0;
	num_minas = 0;
	num_descubiertas = 0;
	mina_pisada = false;

	mode = false;
	display_mines = 0;
}

void	Juego::floodfill(int fila, int col, ListaPosiciones& lista_pos)
{
	Celda	celda;

	//Al ser una funcion recursiva, realizamos las comprobaciones pertinentes a cada casilla (cada llamada) para evaluar
	//posible descubrimiento (casilla valida, no descubierta y no marcada)
	if (tablero.es_valida(fila, col) && !esta_descubierta(fila, col) && !esta_marcada(fila, col))
	{
		celda = tablero.dame_celda(fila, col);					//Una vez comprobada, hacemos una copia de la casilla y
		celda.descubrir_celda();									//la descubrimos, la añadimos al tablero y añadimos su
		tablero.poner_celda(fila, col, celda);						//posicion a nuestra lista de posiciones descubiertas
		num_descubiertas++;											//en este movimiento
		lista_pos.insertar_final(fila, col);
		if (!dame_numero(fila, col))							//En caso de que sea una casilla de numero 0, hacemos una 
		{													//llamada de la funcion recursiva con cada casilla adyacente
			for (int r = fila - 1; r <= fila + 1; r++)
			{
				for (int c = col - 1; c <= col + 1; c++)
					floodfill(r, c, lista_pos);
			}
		}
	}
}

int		Juego::juega(int fila, int col, ListaPosiciones& lista_pos)
{
	int		output = 0;
	Celda	celda;

	//Se gestionan posibles escenarios y errores con distintos valores de salida, permitiendo trabajar cada 
	//escenario de forma individual
	/*
	if (fila == -2 && col == -2)
	{
		output = -2;
		mode = !mode;
	}
	Activar unicamente si se quiere implementar la posibilidad de rendirse o undo en mitad del movimiento de marcar una casilla
	*/
	if (!tablero.es_valida(fila, col))			//Casilla no valida, devuelve -1
		output = -1;

	else if (esta_descubierta(fila, col))			//Casilla ya descubierta, devuelve 1
		output = 1;
	/*
	else if (mode)
	{												//En caso de estar en modo banderas, marca o desmarca la casilla en funcion de
		marcar_desmarcar(fila, col);					//su estado anterior
		mode = !mode;
		output = 3;
	}
	Activar unicamente si se quiere implementar la posibilidad de rendirse o undo en mitad del movimiento de marcar una casilla
	*/
	else if (esta_marcada(fila, col))				//Si es una casilla ya marcada y se intenta descubrir, devuelve 2
		output = 2;
	else											//Modo banderas apagado y sin estar marcada/descubierta la casilla, procedemos
	{												//a realizar el movimiento
		num_jugadas++;
		if (contiene_numero(fila, col) && !dame_numero(fila, col))	//En caso de ser una casilla con un 0, llamamos a la funcion
			floodfill(fila, col, lista_pos);							//recursiva para descubrir todas sus adyacentes
		else
		{
			if (contiene_mina(fila, col))						//En caso de mina, actualizamos los valores respectivos para indicar mina explotada
				mina_pisada = true;
			celda = tablero.dame_celda(fila, col);	//Remplazamos la casilla cubierta por la casilla descubierta
			celda.descubrir_celda();
			tablero.poner_celda(fila, col, celda);
			lista_pos.insertar_final(fila, col);		//Añadimos sus coordenadas a la lista de casillas descubiertas en este movimiento
			num_descubiertas++;
		}
	}
	return output;
}

