#include "ListaJuegos.h"
#include "checkML.h"

////////////////////////////////////////////////////////////////////////////////
////																		////
////							CONSTRUCTORS								////
////																		////
////////////////////////////////////////////////////////////////////////////////

ListaJuegos::ListaJuegos(): cont(0),  capacidad(CAPACIDAD)
{
	lista = new Juego*[CAPACIDAD];
	for (int i = 0; i < CAPACIDAD; i++)
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

namespace
{
	int	dificultad(const Juego& juego)
	{
		return juego.dame_num_columnas() * juego.dame_num_filas() / juego.dame_num_minas();
	}
}

void	ListaJuegos::resize(int tamaño)
{
	Juego** nuevaLista = new Juego*[tamaño];
	for (int i = 0; i < tamaño; i++)
	{
		if (i < cont)
			nuevaLista[i] = lista[i];
		else
			nuevaLista[i] = nullptr;
	}
	delete[] lista;
	lista = nuevaLista;
	capacidad = tamaño;
}

int		ListaJuegos::buscar(const Juego& juego) const
{
	int	newGameDiff = dificultad(juego);
	int	pos = cont;
	int i = 0;

	while (i < cont && pos == cont)
	{
		int	currGameDiff = dificultad(*lista[i]);
		if (newGameDiff < currGameDiff)
			pos = i;
		i++;
	}
	return pos;
}

bool	ListaJuegos::es_vacia() const
{
	return cont == 0;
}

void	ListaJuegos::eliminar(int pos)
{
	if (pos >= 0 && pos < cont)
	{
		delete lista[pos];
		for (; pos < cont - 1; pos++)
			lista[pos] = lista[pos + 1];
		lista[pos] = nullptr;
		cont--;
	}
}

int	ListaJuegos::insertar(const Juego& juego)
{
	int	pos;

	if (cont == capacidad)
		resize(capacidad + CAPACIDAD);
	pos = buscar(juego);
	for (int i = cont; i > pos; i--)
		lista[i] = lista[i - 1];
	lista[pos] =  new Juego(juego);
	cont++;
	
	return pos;
}

