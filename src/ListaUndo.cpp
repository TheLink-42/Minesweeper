#include "ListaUndo.h"


////////////////////////////////////////////////////////////////////////////////
////																		////
////							CONSTRUCTORS								////
////																		////
////////////////////////////////////////////////////////////////////////////////

ListaUndo::ListaUndo(): lista()
{
	cont = 0;
}

ListaUndo::~ListaUndo()
{

}


////////////////////////////////////////////////////////////////////////////////
////																		////
////							GETTERS & SETTERS							////
////																		////
////////////////////////////////////////////////////////////////////////////////

ListaPosiciones	ListaUndo::ultimo_elemento()
{
	ListaPosiciones	lista_pos;
	if (cont > 0)
	{
		cont --;
		lista_pos = lista[cont];
	}
	return lista_pos;
}


////////////////////////////////////////////////////////////////////////////////
////																		////
////							MEMBER FUNCTIONS							////
////																		////
////////////////////////////////////////////////////////////////////////////////

void	ListaUndo::insertar_final(ListaPosiciones lista_pos)
{
	if (cont < MAX_UNDO)					//Si hay hueco, se incluye al final
	{
		this->lista[cont] = lista_pos;
		cont++;
	}
	else									//Si no hay hueco, se desplazan todas a la izquierda, dejando libre el ultimo
	{
		for (int i = 0; i < cont - 1; i++)
			this->lista[i] = this->lista[i+1];
		this->lista[cont - 1] = lista_pos;
	}
}

void	ListaUndo::destruye()					//se destruyen todos los movimientos antes de destruir la lista 
{
	for (int i = 0; i < cont; i++)
		lista[i].destruye();
	cont = 0;
}
