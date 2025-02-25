#pragma once
#include "Board.h"

class Game
{
    private:
		Board	board;
		int		movements;
		int		number_mines;
		int		number_exposed;
		bool	mine_exposed;

    public:
    	Game();
		Game(int rows, int cols);
    	~Game();

		
};

