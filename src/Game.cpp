#include "Game.h"


////////////////////////////////////////////////////////////////////////////////
////																		////
////							CONSTRUCTORS								////
////																		////
////////////////////////////////////////////////////////////////////////////////

Game::Game()
{
	movements = 0;
	mines = 0;
	exposed = 0;
	mine_exposed = false;
}

Game::Game(int rows, int cols): board(rows, cols)
{
	movements = 0;
	mines = 0;
	exposed = 0;
	mine_exposed = false;
}

Game::~Game()
{

}


////////////////////////////////////////////////////////////////////////////////
////																		////
////							GETTERS & SETTERS							////
////																		////
////////////////////////////////////////////////////////////////////////////////

int	Game::get_cols() const
{
	return board.get_cols();
}

int	Game::get_mines() const 
{
	return mines;
}

int	Game::get_movements() const 
{
	return movements;
}

int	Game::get_number(int row, int col) const
{
	return board.get_cell(row, col).get_number();
}

int	Game::get_rows() const
{
	return board.get_rows();
}


bool	Game::set_mine(int row, int col)
{
	Cell cell;
	cell.set_mine();

	return board.set_cell(row, col, cell);
}

////////////////////////////////////////////////////////////////////////////////
////																		////
////							MEMBER FUNCTIONS							////
////																		////
////////////////////////////////////////////////////////////////////////////////

bool	Game::is_complete() const
{
	return (mines + exposed == board.get_rows() * board.get_cols());
}

bool	Game::exposed_mine() const
{
	return mine_exposed;
}


bool	Game::is_empty(int row, int col) const
{
	return board.get_cell(row, col).is_empty();
}

bool	Game::is_exposed(int row, int col) const
{
	return board.get_cell(row, col).get_exposed();
}

bool	Game::is_marked(int row, int col) const
{
	return board.get_cell(row, col).get_marked();
}

bool	Game::is_mine(int row, int col) const
{
	return board.get_cell(row, col).is_mine();
}

bool	Game::is_number(int row, int col) const
{
	return board.get_cell(row, col).is_number();
}


bool	Game::mark(int row, int col)
{
	bool	valid = board.is_valid(row, col);
	if (valid)
	{
		if(is_marked(row, col))
			board.get_cell(row, col).unmark_cell();
		else
			board.get_cell(row, col).mark_cell();
	}
	return valid;
}

bool	Game::hide(int row, int col)
{
	bool	valid = board.is_valid(row, col);
	if (valid && !board.get_cell(row, col).get_exposed())
	{
		board.get_cell(row, col).expose_cell();
		exposed++;
	}
	return valid;
}