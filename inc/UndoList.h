#pragma once
#include "PosList.h"

const int MAX_UNDO = 100;

class UndoList
{
	private:
		int		count;
		PosList	list[MAX_UNDO];
	public:
		UndoList();
		~UndoList();

		PosList	get_last() const;

		void	destroy();
		void	add_last(PosList list);
};
