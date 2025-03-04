#pragma once
#include "Board.h"
#include "PosList.h"


class Game
{
    private:
		Board	board;
		int		movements;
		int		mines;
/**/		int		player_mines;
		int		exposed;
/**/		bool	mode;
		bool	mine_exposed;

		bool	set_forfeit();									//Asignacion del juego a modo "rendirse"
		bool	switch_mode();									//Alternar entre modo banderas
		void	floodfill(int row, int col, PosList& list);		//Funcion recursiva para casillas vacias

    public:
    	Game();													//Constructor por defecto
		Game(int rows, int cols);								//Constructor con dimensiones del tablero
/**/		~Game();												//Destructor por defecto

		void	destroy();										//Reestablecimiento de valores base

		int		get_cols() const;								//Obtencion del numero de columnas
		int		get_mines() const;								//Obtencion del numero de minas
/**/		int		get_player_mines() const;						//Obtencion del numero de minas que faltan por marcar
		int		get_movements() const;							//Obtencion del numero de movimientos
		int		get_number(int row, int col) const;				//Obtencion del numero asignado en una casilla especifica
		int		get_rows() const;								//Obtencion del numero de filas
/**/		bool	get_mode() const;								//Obtencion del estado del modo banderas

		bool	set_mine(int row, int col);						//Asignacion de una mina en una casilla especifica
		
		bool	is_complete() const;							//Comprobacion de juego finalizado
		bool	exposed_mine() const;							//Comprobacion de mina expuesta
		
		bool	is_mine(int row, int col) const;				//Comprobacion de mina en la casilla
		bool	is_exposed(int row, int col) const;				//Comprobacion de casilla descubierta
		bool	is_marked(int row, int col) const;				//Comprobacion de casilla marcada
		bool	is_empty(int row, int col) const;				//Comprobacion de casilla vacia
		bool	is_number(int row, int col) const;				//Comprobacion de casilla con numero
		
		bool	mark(int row, int col);							//Marcar una casilla
		bool	hide(int row, int col);							//Esconder una casilla

		int		play(int row, int col, PosList& list);			//Ejecucion de un movimiento
		
};

