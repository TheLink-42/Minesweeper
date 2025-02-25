#include "Board.h"

Board::Board()
{
    rows = 0;
    cols = 0;
}

Board::Board(int rows, int cols)
{
    this->rows = rows;
    this->cols = cols;
}

Board::~Board()
{

}



void    Board::destroy()
{
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols, j++)
            cells[i][j].destroy();
}




int     Board::get_rows() const
{
    return rows;
}

int     Board::get_cols() const
{
    return cols;
}

Cell    Board::get_cell(int rows, int cols) const
{
    return cells[rows][cols];
}



bool    Board::is_valid(int rows, int cols)
{
    return (rows >= 0 && rows < this->rows && cols >= 0 && cols < this->cols);
}

void    Board::set_cell(int rows, int cols, Cell cell)
{
    if (this->is_valid(rows, cols))
        cells[rows][cols] = cell;
}
