#pragma once
#include "Cell.h"

const int   MAX_ROWS = 20;
const int   MAX_COLS = 20;

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