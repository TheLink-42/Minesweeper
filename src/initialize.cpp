#include "minesweeper.hpp"

void	set_default_values(t_game *game)
{
	game->difficulty = 0;
	game->height = 0;
	game->width = 0;
	game->board = NULL;
	game->score_board = NULL;
	game->player_board = NULL;
	game->coord_col = -1;
	game->coord_row = -1;
	game->game_over = false;
	game->replay = false;
}

bool	start_game(t_game *game)
{
	set_default_values(game);
	set_diff(game);
	create_boards(game);
	display_board(game, game->player_board);
	first_move(game);
	display_board(game, game->board);
	while(!game->game_over)
	{
		game_move(game);
		display_board(game, game->player_board);
	}
	std::cout << "GAME OVER" << std::endl;
	return (game->replay);
}

