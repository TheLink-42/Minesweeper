#ifndef MINESWEEPER_HPP
# define MINESWEEPER_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

typedef struct s_game {
	int		difficulty;
	int		height;
	int		width;
	int**	board;
	int**	score_board;
	int**	player_board;
	bool	game_over;
	bool	replay;
}	t_game;

bool	start_game(t_game *game);
void	set_diff(t_game *game);



#endif
