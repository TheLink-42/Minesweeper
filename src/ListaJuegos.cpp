#include "ListaJuegos.h"
#include "Juego.h"

////////////////////////////////////////////////////////////////////////////////
////																		////
////							CONSTRUCTORS								////
////																		////
////////////////////////////////////////////////////////////////////////////////

ListaJuegos::ListaJuegos(): cont(0)
{

}

ListaJuegos::~ListaJuegos()
{
	if (lista != nullptr)
	{
		for (int i = 0; i < capacidad; i++)
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
}

int	ListaJuegos::insertar(const Juego& juego)
{
	(void)juego;
	return 0;
}

