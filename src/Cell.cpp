#include "Cell.h"

Cell::Cell()
{
    state = EMPTY;
    exposed = false;
    number = 0;
    marked = false;
}

Cell::~Cell()
{

}

void    Cell::destroy()
{
    state = EMPTY;
    exposed = false;
    number = 0;
    marked = false;
}






bool    Cell::get_exposed() const
{
    return exposed;
}

bool    Cell::get_marked() const
{
    return marked;
}

int     Cell::get_number() const
{
    return number;
}







bool	Cell::is_empty() const
{
	return state == EMPTY;
}

bool	Cell::is_mine() const
{
	return state == MINE;
}

bool	Cell::is_number() const
{
	return state == NUMBER;
}





void	Cell::hide_cell()
{
	exposed = false;
}

void	Cell::expose_cell()
{
	exposed = true;
}

void	Cell::mark_cell()
{
	marked = true;
}

void	Cell::unmark_cell()
{
	marked = false;
}





void	Cell::set_mine()
{
	state = MINE;
}

void	Cell::set_number(int number)
{
	this->number = number;
	state = NUMBER;
}

