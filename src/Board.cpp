#include "Board.h"


////////////////////////////////////////////////////////////////////////////////
////																		////
////							CONSTRUCTORS								////
////																		////
////////////////////////////////////////////////////////////////////////////////

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


////////////////////////////////////////////////////////////////////////////////
////																		////
////							GETTERS & SETTERS							////
////																		////
////////////////////////////////////////////////////////////////////////////////

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


bool    Board::set_cell(int rows, int cols, Cell cell)
{
    bool    valid = this->is_valid(rows, cols);
    if (valid)
        cells[rows][cols] = cell;
    return valid;
}


////////////////////////////////////////////////////////////////////////////////
////																		////
////							MEMBER FUNCTIONS							////
////																		////
////////////////////////////////////////////////////////////////////////////////

void    Board::destroy()
{
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            cells[i][j].destroy();
}

bool    Board::is_valid(int rows, int cols) const
{
    return (rows >= 0 && rows < this->rows && cols >= 0 && cols < this->cols);
}

