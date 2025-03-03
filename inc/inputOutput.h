#pragma once

#include "Game.h"
#include "colors.h"
#include <iostream>
#include <iomanip>
#include <fstream>

const int	N_SPACE = 2;

void	display_intro();
void	display_game(Game game);
void	display_result(const Game& game);

void	ask_pos(int& row, int& col);
bool	load_game(Game& game);

std::istream&	operator>>(std::istream& in, Game& game);
std::ostream&	operator<<(std::ostream& out, Game& game);