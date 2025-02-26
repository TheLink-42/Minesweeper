#pragma once
#include "Board.h"
#include "PosList.h"

class Game
{
    private:
		Board	board;
		int		movements;
		int		mines;
		int		exposed;
		bool	mine_exposed;

    public:
    	Game();
		Game(int rows, int cols);
    	~Game();

		void	destroy();

		int		get_cols() const;
		int		get_mines() const;
		int		get_movements() const;
		int		get_number(int row, int col) const;
		int		get_rows() const;

		bool	set_mine(int row, int col);

		bool	is_complete() const;
		bool	exposed_mine() const;

		bool	is_mine(int row, int col) const;
		bool	is_exposed(int row, int col) const;
		bool	is_marked(int row, int col) const;
		bool	is_empty(int row, int col) const;
		bool	is_number(int row, int col) const;


		bool	mark(int row, int col);
		bool	hide(int row, int col);

//		int		play(int row, int col, PosList list);
		
};

