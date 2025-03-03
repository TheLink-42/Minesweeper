#pragma once
#include "PosList.h"

const int MAX_UNDO = 100;

class UndoList
{
	private:
		int		count;
		PosList	list[MAX_UNDO];
	public:
		UndoList();							//Constructor por defecto
		~UndoList();						//Destructor por defecto

		PosList	get_last() const;			//Obtencion de la ultima lista de posiciones

		void	destroy();					//Reestablecimiento de valores base
		void	add_last(PosList list);		//Añadir nuevo movimiento al final de la lista
		void	delete_last();				//Quitar ultimo movimiento del final de la lista
};
