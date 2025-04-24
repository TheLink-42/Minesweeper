#include "ListaJuegos.h"
//#include "checkML.h"

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

void	ListaJuegos::resize(int tamano)
{
	Juego** nuevaLista = new Juego*[tamano];
	for (int i = 0; i < tamano; i++)
	{
		if (i < cont)
			nuevaLista[i] = lista[i];
		else
			nuevaLista[i] = nullptr;
	}
	delete[] lista;
	lista = nuevaLista;
	capacidad = tamano;
}

int		ListaJuegos::buscar(const Juego& juego) const
{
	int pos = 0;
	int	newGameDiff = dificultad(juego);
	int	left = 0;
	int	right = cont - 1;

	if (newGameDiff < dificultad(dame_juego(left)))
		pos = 0;
	else if (newGameDiff >= dificultad(dame_juego(right)))
		pos = cont;
	else
	{
		while (left < right)
		{
			int mid = left + (right - left) / 2;
			if (newGameDiff < dificultad(dame_juego(mid)))
				right = mid;
			else
				left = mid + 1;
		}
		pos = left;
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
	if (cont == 0)
		pos = 0;
	else
		pos = buscar(juego);
	for (int i = cont; i > pos; i--)
		lista[i] = lista[i - 1];
	lista[pos] =  new Juego(juego);
	cont++;
	
	return pos;
}

