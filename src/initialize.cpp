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
	game->game_over = 0;
	game->replay = false;
}

void	free_boards(t_game *game)
{
	for (int i = 0; i < game->height; i++)
	{
		delete[] game->board[i];
		delete[] game->score_board[i];
		delete[] game->player_board[i];
	}
	delete[] game->board;
	delete[] game->score_board;
	delete[] game->player_board;
}

void	replay(t_game *game)
{
	std::string	input;
	int			replay;

	display_replay_menu();
	std::getline(std::cin, input);
		replay = stoi(input);
	if (replay == 1)
		game->replay = true;
	else if (replay != 2)
		std::cout << "Invalid answwer. If you want to replay, execute again." << std::endl;
}

bool	start_game(t_game *game)
{
	set_default_values(game);
	set_diff(game);
	create_boards(game);
	display_board(game, game->player_board);
	first_move(game);
	while(!game->game_over)
		game_move(game);
	display_game_over_menu(game);
	free_boards(game);
	replay(game);
	return (game->replay);
}

