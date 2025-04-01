#include "ListaPosiciones.h"


////////////////////////////////////////////////////////////////////////////////
////																		////
////							CONSTRUCTORS								////
////																		////
////////////////////////////////////////////////////////////////////////////////

ListaPosiciones::ListaPosiciones()
{
	cont = 0;
	lista = nullptr;
}

ListaPosiciones::ListaPosiciones(const ListaPosiciones& other)
{
	cont = other.cont;
	lista = new Posicion[cont];
	for (int i = 0; i < cont; i++)
		lista[i] = other.lista[i];
}

ListaPosiciones::~ListaPosiciones()
{
	if (lista != nullptr)
		delete[] lista;
}


////////////////////////////////////////////////////////////////////////////////
////																		////
////							GETTERS & SETTERS							////
////																		////
////////////////////////////////////////////////////////////////////////////////

int	ListaPosiciones::longitud() const
{
	return cont;
}

int	ListaPosiciones::dame_posX(int i) const
{
	int x = -1;
	if (i >= 0 && i < cont)
		x = lista[i].posx;
	return x;
}

int	ListaPosiciones::dame_posY(int i) const
{
	int y = -1;
	if (i >= 0 && i < cont)
		y = lista[i].posy;
	return y;
}


////////////////////////////////////////////////////////////////////////////////
////																		////
////							MEMBER FUNCTIONS							////
////																		////
////////////////////////////////////////////////////////////////////////////////

void	ListaPosiciones::insertar_final(int x, int y)
{
	Posicion*	newLista = new Posicion[cont + 1];
	if (lista != nullptr)
	{
		for (int i = 0; i < cont; i++)
			newLista[i] = lista[i];
		delete[] lista;
	}
	newLista[cont].posx = x;
	newLista[cont].posy = y;
	cont++;
	
	lista = newLista;
}
