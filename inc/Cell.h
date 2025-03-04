#pragma once

class Cell
{
    private:
    	typedef enum {NUMBER, EMPTY, MINE} State;
		State	state;

		bool	exposed;
 		int		number;
		bool	marked;

	public:
		Cell();							//Constructor por defecto
/**/		~Cell();						//Destructor por defecto

		void	destroy();				//Reestablecimiento de valores base

		bool	get_exposed() const;	//Obtencion de casilla descubierta
		bool	get_marked() const;		//Obtencion de casilla marcada
		int 	get_number() const;		//Obtención de numero asignado a la casilla

		bool	is_empty() const;		//Comprobacion casilla vacia
		bool	is_mine() const;		//Comprobacion casilla con mina
		bool	is_number() const;		//Comprobacion casilla con numero

		void	hide_cell();			//Tapar una celda
		void	expose_cell();			//Descubrir una celda
		void	mark_cell();			//Marcar una celda
		void	unmark_cell();			//Desmarcar una celda

		void	set_mine();				//Asignar una mina
		void	set_number(int n);		//Asignar un numero
};
