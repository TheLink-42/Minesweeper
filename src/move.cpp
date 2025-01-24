#include "minesweeper.hpp"

bool	check_coordinates(const std::string coordinates, t_game *game)
{
	if (coordinates.length() != 3)
		return false;
	if (!islower(coordinates.at(0)))
		return false;
	if (!isupper(coordinates.at(2)))
		return false;
	if (coordinates.at(0) > 'a' + game->height - 1)
		return false;
	if (coordinates.at(2) > 'A' + game->width -1)
		return false;
	return true;
}

void	get_coordinates(t_game *game)
{
	std::string	coordinates;

	std::cout << "Introduce tile coordinates: (Formats is row-col)" << std::endl;
	std::getline(std::cin, coordinates);
	while (!check_coordinates(coordinates, game))
	{
		std::cout << "Please, introduce tile coordinates with the proper format (rows-cols)" << std::endl;
		std::getline(std::cin, coordinates);
	}
	game->coord_row = coordinates.at(0) - 'a';
	game->coord_col = coordinates.at(2) - 'A';
}

void	first_move(t_game *game)
{
	get_coordinates(game);
	set_board(game);
	game->player_board[game->coord_row][game->coord_col] = game->board[game->coord_row][game->coord_col];
//	display_board(game, game->board);
}

void	game_move(t_game *game)
{
	get_coordinates(game);
	game->player_board[game->coord_row][game->coord_col] = game->board[game->coord_row][game->coord_col];
	if (game->board[game->coord_row][game->coord_col] == '*')
		game->game_over = true;
//	else if (game->board[game->coord_row][game->coord_col] == '0')
//	{
//		floodfill(game);
//	}
}