#pragma once
#include "ListaPosiciones.h"

const int MAX_UNDO = 100;

class ListaUndo
{
	private:
		int		cont;
		ListaPosiciones	lista[MAX_UNDO];
	public:
		ListaUndo();							//Constructor por defecto
/**/		~ListaUndo();						//Destructor por defecto

		ListaPosiciones	ultimo_elemento();			//Obtencion de la ultima lista de posiciones

		void	destruye();					//Reestablecimiento de valores base
		void	insertar_final(ListaPosiciones lista_pos);		//Añadir nuevo movimiento al final de la lista
};
