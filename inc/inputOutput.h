#pragma once

#include "Juego.h"
#include "colors.h"
#include <iostream>
#include <iomanip>
#include <fstream>

const int	N_SPACE = 2;
class GestorJuegos;

void	mostrar_cabecera();
void	mostrar_juego(Juego juego);
void	mostrar_resultado(GestorJuegos& GP, int pos, const Juego& juego);

void	pedir_pos(int& row, int& col);
Juego	carga_juego(std::ifstream& juego);
