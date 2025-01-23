#include "minesweeper.hpp"

void	set_default_values(t_game *game)
{
	game->difficulty = 0;
	game->height = 0;
	game->width = 0;
	game->board = NULL;
	game->score_board = NULL;
	game->player_board = NULL;
	game->game_over = false;
	game->replay = false;
}

bool	start_game(t_game *game)
{
	set_default_values(game);
	set_diff(game);
	create_board(game);
	display_board(game);
//	while(!game->game_over)
//		play_game();
//		print_board(game->player_board);

	return (false);
}