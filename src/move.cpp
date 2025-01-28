#include "minesweeper.hpp"

void	floodfill(t_game *game, int row, int col)
{
	if (row < 0 || row >= game->height || col < 0 || col >= game->width)
		return ; 
	if (game->score_board[row][col] != '.')
		return ;
	game->score_board[row][col] = '?';
	game->player_board[row][col] = game->board[row][col];
	if (game->board[row][col] == '0')
	{
		game->player_board[row][col] = ' ';
		floodfill(game, row - 1, col - 1);
		floodfill(game, row - 1, col);
		floodfill(game, row - 1, col + 1);
		floodfill(game, row, col - 1);
		floodfill(game, row, col + 1);
		floodfill(game, row + 1, col - 1);
		floodfill(game, row + 1, col);
		floodfill(game, row + 1, col + 1);
	}
}

bool	check_coordinates(const std::string coordinates, t_game *game)
{
	if (coordinates.length() != 3)
		return false;
	if (coordinates.at(0) > 'a' + game->height - 1 || coordinates.at(0) < 'a')
		return false;
	if (coordinates.at(2) > 'A' + game->width -1 || coordinates.at(2) < 'A')
		return false;
	return true;
}

void	get_coordinates(t_game *game)
{
	std::string	coordinates;

	std::cout << "Introduce tile coordinates: (Format is row-col)" << std::endl;
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
	floodfill(game, game->coord_row, game->coord_col);
	display_board(game, game->player_board);
}

void	game_completed(t_game *game)
{
	int	i;
	int	bombs;

	i = 0;
	bombs = 0;
	while (i < game->height * game->width)
	{
		if(game->score_board[i/game->width][i%game->width] == '.')
			bombs++;
		i++;
	}
	if (bombs == game->number_bombs)
		game->game_over = 1;
}

void	game_move(t_game *game)
{
	get_coordinates(game);
	if (game->board[game->coord_row][game->coord_col] == '*')
		game->game_over = 2;
	floodfill(game, game->coord_row, game->coord_col);
	game_completed(game);
	display_board(game, game->player_board);
}
