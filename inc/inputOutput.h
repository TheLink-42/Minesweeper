#pragma once

#include "Juego.h"
#include "colors.h"
#include <iostream>
#include <iomanip>
#include <fstream>

const int	N_SPACE = 2;

void	mostrar_cabecera();
void	mostrar_juego(Juego juego);
void	mostrar_resultado(const Juego& juego);

void	pedir_pos(int& row, int& col);
bool	carga_juego(Juego& juego);
