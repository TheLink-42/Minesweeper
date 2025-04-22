#include "GestorJuegos.h"
#include "ListaUndo.h"
#include "inputOutput.h"
#include "checkML.h"
#include <ctime>


int		juega(Juego& game, int x, int y, ListaUndo& list);
void	undo(Juego& game, ListaUndo& undoList);
void	existente(GestorJuegos& GP, ListaUndo& lista_undo);
void	aleatorio(ListaUndo& lista_undo);

int main( void )
{
//	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	srand(time(NULL));
	mostrar_cabecera();
	GestorJuegos GP;
	ListaUndo	lista_undo;
	if (GP.cargar_juegos())
	{
		int	opcion;
		std::cout << "Juego aleatorio (opcion 1) o juego existente (opcion 2):";
		std::cin >> opcion;

		if (opcion != 2)
			aleatorio(lista_undo);
		else
			existente(GP, lista_undo);
	}
	else
		aleatorio(lista_undo);

	return 0;
}

void	undo(Juego& juego, ListaUndo& lista_undo)
{
	ListaPosiciones	lista_pos = lista_undo.ultimo_elemento();
	int				casillas = lista_pos.longitud();

	for (int i = 0; i < casillas; i++)
		juego.ocultar(lista_pos.dame_posX(i), lista_pos.dame_posY(i));		//Se cubren cada una de las casillas descubiertas
	lista_undo.eliminar_ultimo();
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

void	aleatorio(ListaUndo& lista_undo)
{
	int	fila, col, mina = 0;
	int	x,y,output = 0;

	std::cout << "Generando juego aleatorio..." << std::endl;
	std::cout << "Numero de filas (>=3) y columnas (>=3) del tablero:" << std::endl;
	std::cin >> fila >> col;

	std::cout << "Numero de minas (<" << fila*col/3 << "):";
	std::cin >> mina;

	Juego juego(fila, col, mina);

	std::cout << "Juego con " << mina << "minas" << std::endl;
	mostrar_juego(juego);
	while (!juego.esta_completo() && !juego.mina_explotada() && output != -127)
	{
		pedir_pos(x, y);
		output = juega(juego, x, y, lista_undo);
	}
	mostrar_resultado(juego);
}

void	existente(GestorJuegos& GP, ListaUndo& lista_undo)
{
	int	pos,x,y,output = 0;

	GP.mostrar_lista_juegos();
	std::cin >> pos;

	Juego juego(GP.dame_juego(pos));
	mostrar_juego(juego);
	while (!juego.esta_completo() && !juego.mina_explotada() && output != -127)
	{
		pedir_pos(x, y);
		output = juega(juego, x, y, lista_undo);
	}
	mostrar_resultado(juego);

}