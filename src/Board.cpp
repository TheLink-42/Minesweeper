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
    bool    valid = this->is_valid(rows, cols);     //En caso de ser una casilla valida, se asigna la celda
    if (valid)
        cells[rows][cols] = cell;
    return valid;
}


////////////////////////////////////////////////////////////////////////////////
////																		////
////							MEMBER FUNCTIONS							////
////																		////
////////////////////////////////////////////////////////////////////////////////

bool    Board::is_valid(int rows, int cols) const
{
    return (rows >= 0 && rows < this->rows && cols >= 0 && cols < this->cols);
}


void    Board::destroy()                //Se destruye cada celda antes de destruir el tablero
{
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            cells[i][j].destroy();
    rows = 0;
    cols = 0;
}