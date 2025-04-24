#pragma once
#include "Celda.h"

const int   MAX_FILAS = 20;
const int   MAX_COLS = 20;

class Tablero
{
    private:
        int     filas;
        int     columnas;
        Celda	celdas[MAX_FILAS][MAX_COLS];

	public:
		Tablero();											//Constructor por defecto
		Tablero(int filas, int columnas);							//Constructor con dimensiones establecidas
/**/		~Tablero();											//Destructor por defecto

		void	destruye();									//Reestablecimiento de valores base

		int		num_filas() const;							//Obtención del numero de filas del tablero
		int		num_columnas() const;							//Obtención del numero de columnas del tablero
		Celda	dame_celda(int fil, int col) const;			//Obtención de una celda específica del tablero

		bool	es_valida(int fil, int col) const;			//Comprobacion de coordenadas validas

		bool	poner_celda(int fil, int col, Celda celda);	//Asignacion de una nueva celda en una posicion especifica
};