#include "ListaJuegos.h"
#include "Juego.h"

////////////////////////////////////////////////////////////////////////////////
////																		////
////							CONSTRUCTORS								////
////																		////
////////////////////////////////////////////////////////////////////////////////

ListaJuegos::ListaJuegos(): cont(0),  capacidad(MAX_JUEGOS)
{
	lista = new Juego*[MAX_JUEGOS];
	for (int i = 0; i < MAX_JUEGOS; i++)
		lista[i] = nullptr;
}

ListaJuegos::~ListaJuegos()
{
	if (lista != nullptr)
	{
		for (int i = 0; i < cont; i++)
			if (lista[i] != nullptr)
				delete lista[i];
		delete[] lista;
	}
}


////////////////////////////////////////////////////////////////////////////////
////																		////
////							GETTERS & SETTERS							////
////																		////
////////////////////////////////////////////////////////////////////////////////

int	ListaJuegos::dame_longitud() const
{
	return cont;
}

const Juego&	ListaJuegos::dame_juego(int pos) const
{
	return (*lista[pos]);
}


////////////////////////////////////////////////////////////////////////////////
////																		////
////							MEMBER FUNCTIONS							////
////																		////
////////////////////////////////////////////////////////////////////////////////

bool	ListaJuegos::es_vacia() const
{
	return cont == 0;
}

void	ListaJuegos::eliminar(int pos)
{
	delete lista[pos];
	for (; pos < cont - 1; pos++)
		lista[pos] = lista[pos + 1];
	lista[pos] = nullptr;
	cont--;
}

int	ListaJuegos::insertar(const Juego& juego)
{
	(void)juego;
	return 0;
}

