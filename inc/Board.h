#pragma once
#include "Cell.h"

int const   MAX_ROWS = 10;
int const   MAX_COLS = 10;

class Board
{
    private:
        int     rows;
        int     cols;
        Cell    cells[MAX_ROWS][MAX_COLS];

	public:
		Board();
		Board(int rows, int cols);
		~Board();

		void	destroy();

		int		get_rows() const;
		int		get_cols() const;
		Cell	get_cell(int rows, int cols) const;

		bool	is_valid(int rows, int cols) const;

		bool	set_cell(int rows, int cols, Cell cell);
};