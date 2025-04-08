#include "ListaUndo.h"


////////////////////////////////////////////////////////////////////////////////
////																		////
////							CONSTRUCTORS								////
////																		////
////////////////////////////////////////////////////////////////////////////////

ListaUndo::ListaUndo():
cont(0)
{
	for (int i = 0; i < MAX_UNDO; i++)
		lista[i] = nullptr;
}

ListaUndo::~ListaUndo()
{
	for (int i = 0; i < cont; i++)
		delete lista[i];
}


////////////////////////////////////////////////////////////////////////////////
////																		////
////							GETTERS & SETTERS							////
////																		////
////////////////////////////////////////////////////////////////////////////////

ListaPosiciones	ListaUndo::ultimo_elemento()
{
	if (cont > 0)
		return *lista[cont - 1];
	return ListaPosiciones();
}


////////////////////////////////////////////////////////////////////////////////
////																		////
////							MEMBER FUNCTIONS							////
////																		////
////////////////////////////////////////////////////////////////////////////////

void	ListaUndo::insertar_final(const ListaPosiciones& lista_pos)
{
	ListaPosiciones*	newListaPos = new ListaPosiciones(lista_pos);
	if (cont < MAX_UNDO)					//Si hay hueco, se incluye al final
	{
		lista[cont] = newListaPos;
		cont++;
	}
	else									//Si no hay hueco, se desplazan todas a la izquierda, dejando libre el ultimo
	{
		delete lista[0];
		for (int i = 0; i < cont - 1; i++)
			lista[i] = lista[i+1];
		lista[cont - 1] = newListaPos;
	}
}

void	ListaUndo::eliminar_ultimo()
{
	if (cont > 0)
	{
		delete lista[cont - 1];
		lista[cont - 1] = nullptr;
		cont --;
	}
}
