#include "Game.h"


////////////////////////////////////////////////////////////////////////////////
////																		////
////							CONSTRUCTORS								////
////																		////
////////////////////////////////////////////////////////////////////////////////

Game::Game(): board()
{
	movements = 0;
	mines = 0;
	exposed = 0;
	mine_exposed = false;
	mode = false;
}

Game::Game(int rows, int cols): board(rows, cols)
{
	movements = 0;
	mines = 0;
	exposed = 0;
	mine_exposed = false;
	mode = false;
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

Board	Game::get_board() const
{
	return board;
}

bool	Game::get_mode() const
{
	return mode;
}

bool	Game::set_mine(int row, int col)
{
	Cell	cell;
	cell.set_mine();
	mines++;

	return board.set_cell(row, col, cell);
}

bool	Game::set_number(int row, int col, int n)
{
	Cell	cell;
	cell.set_number(n);

	return board.set_cell(row, col, cell);
}

bool	Game::set_forfeit()
{
	mine_exposed = true;

	return true;
}

////////////////////////////////////////////////////////////////////////////////
////																		////
////							MEMBER FUNCTIONS							////
////																		////
////////////////////////////////////////////////////////////////////////////////

bool	Game::is_valid(int row, int col) const
{
	return board.is_valid(row, col);
}

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
	Cell	cell;
	bool	valid = board.is_valid(row, col);

	if (valid)
	{
		cell = board.get_cell(row, col);
		if(is_marked(row, col))
		{
			cell.unmark_cell();
			mines++;
		}
		else
		{
			cell.mark_cell();
			mines--;
		}
		board.set_cell(row, col, cell);
	}
	return valid;
}

bool	Game::hide(int row, int col)
{
	Cell	cell;
	bool	valid = board.is_valid(row, col);

	if (valid && board.get_cell(row, col).get_exposed())
	{
		cell = board.get_cell(row, col);
		cell.hide_cell();
		board.set_cell(row, col, cell);
		exposed--;
	}
	return valid;
}

bool	Game::switch_mode()
{
	mode = !mode;

	return true;
}

void	Game::destroy()
{
	board.destroy();
	movements = 0;
	mines = 0;
	exposed = 0;
	mine_exposed = false;
}

void	Game::floodfill(int row, int col, PosList& list)
{
	Cell	cell;

	if (board.is_valid(row, col) && !is_exposed(row, col) && !is_marked(row, col))
	{
		cell = board.get_cell(row, col);
		cell.expose_cell();
		board.set_cell(row, col, cell);
		exposed++;
		list.add_last(row, col);
		if (!get_number(row, col))
		{
			for (int r = row - 1; r <= row + 1; r++)
			{
				for (int c = col - 1; c <= col + 1; c++)
				{
					if (r == row && c == col)
						continue;
					floodfill(r, c, list);
				}
			}
		}
	}
}

int		Game::play(int row, int col, PosList& list)
{
	int		output = 0;
	Cell	cell;

	if (!board.is_valid(row, col))
		output = -1;
	else if (is_exposed(row, col))
		output = 1;
	else if (mode)
		mark(row, col);
	else if (is_marked(row, col))
		output = 2;
	else
	{
		list.add_last(row, col);
		movements++;
		cell = board.get_cell(row, col);
		cell.expose_cell();
		if (is_mine(row, col))
		{
			mine_exposed = true;
			board.set_cell(row, col, cell);
			exposed++;
		}
		else if (!get_number(row, col))
			floodfill(row, col, list);
		else
		{
			board.set_cell(row, col, cell);
			exposed++;
		}
	}
	return output;
}

