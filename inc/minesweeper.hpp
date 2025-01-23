#ifndef MINESWEEPER_HPP
# define MINESWEEPER_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

typedef struct s_game {
	int		difficulty;
	int		number_bombs;
	int		height;
	int		width;
	char**	board;
	char**	score_board;
	char**	player_board;
	bool	game_over;
	bool	replay;
}	t_game;

bool	start_game(t_game *game);
void	set_diff(t_game *game);
void	create_board(t_game *game);
void	display_board(t_game *game);

#endif
