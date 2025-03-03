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
		Board();											//Constructor por defecto
		Board(int rows, int cols);							//Constructor con dimensiones establecidas
		~Board();											//Destructor por defecto

		void	destroy();									//Reestablecimiento de valores base

		int		get_rows() const;							//Obtención del numero de filas del tablero
		int		get_cols() const;							//Obtención del numero de columnas del tablero
		Cell	get_cell(int rows, int cols) const;			//Obtención de una celda específica del tablero

		bool	is_valid(int rows, int cols) const;			//Comprobacion de coordenadas validas

		bool	set_cell(int rows, int cols, Cell cell);	//Asignacion de una nueva celda en una posicion especifica
};