#include "Celda.h"


////////////////////////////////////////////////////////////////////////////////
////																		////
////							CONSTRUCTORS								////
////																		////
////////////////////////////////////////////////////////////////////////////////

Celda::Celda()
{
    estado = VACIO;
    descubierta = false;
    numero = 0;
    marcada = false;
}

Celda::~Celda()
{

}


////////////////////////////////////////////////////////////////////////////////
////																		////
////							GETTERS & SETTERS							////
////																		////
////////////////////////////////////////////////////////////////////////////////

bool    Celda::esta_descubierta() const
{
    return descubierta;
}

bool    Celda::esta_marcada() const
{
    return marcada;
}

int     Celda::dame_numero() const
{
    return numero;
}


void	Celda::poner_mina()
{
	estado = MINA;
}

void	Celda::poner_numero(int numero)
{
	this->numero = numero;
	estado = NUMERO;
}


////////////////////////////////////////////////////////////////////////////////
////																		////
////							MEMBER FUNCTIONS							////
////																		////
////////////////////////////////////////////////////////////////////////////////

bool	Celda::esta_vacia() const
{
	return estado == VACIO;
}

bool	Celda::contiene_mina() const
{
	return estado == MINA;
}

bool	Celda::contiene_numero() const
{
	return estado == numero;
}


void	Celda::ocultar_celda()
{
	descubierta = false;
}

void	Celda::descubrir_celda()
{
	descubierta = true;
}

void	Celda::marcar_celda()
{
	marcada = true;
}

void	Celda::desmarcar_celda()
{
	marcada = false;
}


void    Celda::destruye()
{
    estado = VACIO;
    descubierta = false;
    numero = 0;
    marcada = false;
}