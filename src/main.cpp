#include "Juego.h"
#include "ListaUndo.h"
#include "inputOutput.h"


int		juega(Juego& game, int x, int y, ListaUndo& list);
void	undo(Juego& game, ListaUndo& undoList);

int main( void )
{
	Juego		juego;
	ListaUndo	lista_undo;
	int			x,y,output;
	
	mostrar_cabecera();
	if (carga_juego(juego))			//Solo ejecutará el juego en caso de que el archivo se haya cargado correctamente
	{
		output = 0;
		mostrar_juego(juego);
		while (!juego.esta_completo() && !juego.mina_explotada() && output != -127)
		{
			pedir_pos(x, y);
			output = juega(juego, x, y, lista_undo);
		}
		mostrar_resultado(juego);
		juego.destruye(); 				//Cuando implementemos memoria dinamica será util
	}

	return 0;
}

void	undo(Juego& juego, ListaUndo& lista_undo)
{
	ListaPosiciones	lista_pos = lista_undo.ultimo_elemento();
	std::cout << "LLega" << std::endl;
	int				casillas = lista_pos.longitud();

	for (int i = 0; i < casillas; i++)
		juego.ocultar(lista_pos.dame_posX(i), lista_pos.dame_posY(i));		//Se cubren cada una de las casillas descubiertas
}

int	juega(Juego& juego, int x, int y, ListaUndo& lista_undo)
{
	ListaPosiciones	lista_pos;
	int		output = 0;
	bool	movimiento;

	if (x == -3 && y == -3)
		undo(juego, lista_undo);
	else if (x == -1 && y == -1)
		output = -127;
	else if (x == -2 && y == -2)				
	{											
		juego.swap_mode();						
		mostrar_juego(juego);
		std::cout << "Que casilla desea marcar:" << std::endl;
		std::cin >> x >> y;
		juego.marcar_desmarcar(x, y);
		juego.swap_mode();
	}
	else if (x >= 0 && x < juego.dame_num_filas() && y >= 0 && y < juego.dame_num_columnas())
	{
		movimiento = juego.juega(x, y, lista_pos);
		if (movimiento)
			lista_undo.insertar_final(lista_pos);
	}
	else
		std::cout << RED << "Por favor, introduzca coordenadas validas" << RESET << std::endl;
	mostrar_juego(juego);			//Se muestra el tablero para que se pueda apreciar el resultado de la jugada realizada
	
	return output;
}