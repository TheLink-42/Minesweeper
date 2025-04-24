#include "Tablero.h"


////////////////////////////////////////////////////////////////////////////////
////																		////
////							CONSTRUCTORS								////
////																		////
////////////////////////////////////////////////////////////////////////////////

Tablero::Tablero()
{
    filas = 0;
    columnas = 0;
}

Tablero::Tablero(int fila, int columna)
{
    this->filas = fila;
    this->columnas = columna;
}

Tablero::~Tablero()
{

}


////////////////////////////////////////////////////////////////////////////////
////																		////
////							GETTERS & SETTERS							////
////																		////
////////////////////////////////////////////////////////////////////////////////

int     Tablero::num_filas() const
{
    return filas;
}

int     Tablero::num_columnas() const
{
    return columnas;
}

Celda    Tablero::dame_celda(int fila, int columna) const
{
    return celdas[fila][columna];
}


bool    Tablero::poner_celda(int fila, int columna, Celda celda)
{
    bool    valid = this->es_valida(fila, columna);     //En caso de ser una casilla valida, se asigna la celda
    if (valid)
        celdas[fila][columna] = celda;
    return valid;
}


////////////////////////////////////////////////////////////////////////////////
////																		////
////							MEMBER FUNCTIONS							////
////																		////
////////////////////////////////////////////////////////////////////////////////

bool    Tablero::es_valida(int fila, int columna) const
{
    return (fila >= 0 && fila < this->filas && columna >= 0 && columna < this->columnas);
}


void    Tablero::destruye()                //Se destruye cada celda antes de destruir el tablero
{
    for(int i = 0; i < filas; i++)
        for(int j = 0; j < columnas; j++)
            celdas[i][j].destruye();
    filas = 0;
    columnas = 0;
}