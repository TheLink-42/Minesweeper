#include "GestorJuegos.h"
#include "ListaUndo.h"
#include "inputOutput.h"
//#include "checkML.h"



bool		juega(Juego& game, int x, int y, ListaUndo& list);
void	undo(Juego& game, ListaUndo& undoList);
void	existente(GestorJuegos& GP, ListaUndo& lista_undo);
void	aleatorio(GestorJuegos& GP, ListaUndo& lista_undo);

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
			aleatorio(GP, lista_undo);
		else
			existente(GP, lista_undo);
	}
	else
		aleatorio(GP, lista_undo);
	GP.guardar_lista_juegos();
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

bool	juega(Juego& juego, int x, int y, ListaUndo& lista_undo)
{
	ListaPosiciones	lista_pos;
	bool	output = true;
	bool	movimiento;

	if (x == -3 && y == -3)
		undo(juego, lista_undo);
	else if (x == -1 && y == -1)
		output = false;
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
	if (juego.esta_completo() || juego.mina_explotada())
		output = false;
	return output;
}

void	aleatorio(GestorJuegos& GP, ListaUndo& lista_undo)
{
	int	fila, col, mina = 0;
	int	x,y = 0;
	int pos;

	std::cout << "Generando juego aleatorio..." << std::endl;
	std::cout << "Numero de filas (>=3) y columnas (>=3) del tablero:" << std::endl;
	std::cin >> fila >> col;
	if (fila > 20)
		fila = 20;
	if (fila < 3)
		fila = 3;
	if (col > 20)
		col = 20;
	if (col < 3)
		col = 3;

	std::cout << "Numero de minas (<" << fila*col/3 << "):";
	std::cin >> mina;

	Juego juego(fila, col, mina);

	pos = GP.insertar(juego);
	std::cout << "Juego con " << mina << "minas" << std::endl;
	mostrar_juego(juego);
	do{
		pedir_pos(x, y);
	} while (juega(juego, x, y, lista_undo));
	mostrar_resultado(GP, pos, juego);
}

void	existente(GestorJuegos& GP, ListaUndo& lista_undo)
{
	int	pos,x,y = 0;

	GP.mostrar_lista_juegos();
	std::cin >> pos;

	Juego juego(GP.dame_juego(pos));
	mostrar_juego(juego);
	do {
		pedir_pos(x, y);
	} while (juega(juego, x, y, lista_undo));
	mostrar_resultado(GP, pos, juego);
}