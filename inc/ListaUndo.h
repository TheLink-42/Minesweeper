#pragma once
#include "ListaPosiciones.h"

const int MAX_UNDO = 10;

class ListaUndo
{
	private:
		int		cont;
		ListaPosiciones*	lista[MAX_UNDO];
	public:
		ListaUndo();							//Constructor por defecto
		~ListaUndo();						//Destructor por defecto

		ListaPosiciones	ultimo_elemento();			//Obtencion de la ultima lista de posiciones

		void	eliminar_ultimo();								//Elimina el ultimo elemento de la lista
		void	insertar_final(const ListaPosiciones& lista_pos);		//Añadir nuevo movimiento al final de la lista
};
