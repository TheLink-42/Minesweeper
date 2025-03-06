#pragma once
#include "Tablero.h"
#include "ListaPosiciones.h"


class Juego
{
    private:
		Tablero	tablero;
		int		num_jugadas;
		int		num_minas;
		int		num_descubiertas;
		bool	mina_pisada;

		/**/		bool	mode;									//Variables empleadas unicamente para la informacion mostrada 
		/**/		int		display_mines;							//en el terminal

		void	floodfill(int fila, int col, ListaPosiciones& list);		//Funcion recursiva para casillas vacias

    public:
    	Juego();													//Constructor por defecto
		Juego(int filas, int cols);									//Constructor con dimensiones del tablero
/**/		~Juego();												//Destructor por defecto

		void	destruye();											//Reestablecimiento de valores base

		int		dame_num_columnas() const;							//Obtencion del numero de columnas
		int		dame_num_minas() const;								//Obtencion del numero de minas
		int		dame_num_jugadas() const;							//Obtencion del numero de movimientos
		int		dame_numero(int fila, int col) const;				//Obtencion del numero asignado en una casilla especifica
		int		dame_num_filas() const;								//Obtencion del numero de filas

/**/		int		get_display_mines() const;						//
/**/		bool	swap_mode();									//Funciones unicamente para mostrar info extra en terminal
/**/		bool	get_mode() const;								//

		bool	poner_mina(int fila, int col);						//Asignacion de una mina en una casilla especifica
		
		bool	esta_completo() const;								//Comprobacion de juego finalizado
		bool	mina_explotada() const;								//Comprobacion de mina expuesta
		
		bool	contiene_mina(int fila, int col) const;				//Comprobacion de mina en la casilla
		bool	esta_descubierta(int fila, int col) const;			//Comprobacion de casilla descubierta
		bool	esta_marcada(int fila, int col) const;				//Comprobacion de casilla marcada
		bool	esta_vacia(int fila, int col) const;				//Comprobacion de casilla vacia
		bool	contiene_numero(int fila, int col) const;			//Comprobacion de casilla con numero
		
		bool	marcar_desmarcar(int fila, int col);				//Marcar/desmarcar una casilla
		bool	ocultar(int fila, int col);							//Esconder una casilla

		int		juega(int fila, int col, ListaPosiciones& lista_pos);		//Ejecucion de un movimiento
		
};

