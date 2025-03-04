#include "UndoList.h"


////////////////////////////////////////////////////////////////////////////////
////																		////
////							CONSTRUCTORS								////
////																		////
////////////////////////////////////////////////////////////////////////////////

UndoList::UndoList(): list()
{
	count = 0;
}

UndoList::~UndoList()
{

}


////////////////////////////////////////////////////////////////////////////////
////																		////
////							GETTERS & SETTERS							////
////																		////
////////////////////////////////////////////////////////////////////////////////

PosList	UndoList::get_last()
{
	count --;
	return list[count];
}


////////////////////////////////////////////////////////////////////////////////
////																		////
////							MEMBER FUNCTIONS							////
////																		////
////////////////////////////////////////////////////////////////////////////////

void	UndoList::add_last(PosList list)
{
	if (count < MAX_UNDO)					//Si hay hueco, se incluye al final
	{
		this->list[count] = list;
		count++;
	}
	else									//Si no hay hueco, se desplazan todas a la izquierda, dejando libre el ultimo
	{
		for (int i = 0; i < count - 1; i++)
			this->list[i] = this->list[i+1];
		this->list[count - 1] = list;
	}
}

void	UndoList::destroy()					//se destruyen todos los movimientos antes de destruir la lista 
{
	for (int i = 0; i < count; i++)
		list[i].destroy();
	count = 0;
}
