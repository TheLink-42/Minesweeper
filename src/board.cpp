#include "minesweeper.hpp"

void	display_board(t_game *game, char** board)
{
	std::cout << "  ";
	for (int i = 0; i < game->width; i++)
		std::cout << char('A' + i);
	std::cout << std::endl << " ";
	for (int i = 0; i < game->width + 2; i++)
		std::cout << "#";
	std::cout << std::endl;
	for(int i = 0; i < game->height; i++)
	{
		std::cout << char('a' + i)<< "#";
		for (int j = 0; j < game->width; j++)
			std::cout << board[i][j];
		std::cout << "#" << std::endl;
	}
	std::cout << " ";
	for (int i = 0; i < game->width + 2; i++)
		std::cout << "#";
	std::cout << std::endl;
}

char	count_bombs(t_game *game, int i)
{
	int	row;
	int	col;
	int	bombs;

	row = i/game->width;
	col = i%game->width;
	bombs = 0;
	if (row - 1 >= 0)
	{
		if (col - 1 >= 0)
			if (game->board[row - 1][col - 1] == '*')
				bombs++;
		if (game->board[row - 1][col] == '*')
			bombs++;
		if (col + 1 < game->width)
			if (game->board[row - 1][col + 1] == '*')
			bombs++;
	}
	if (row + 1 < game->height)
	{
		if (col - 1 >= 0)
			if (game->board[row + 1][col - 1] == '*')
				bombs++;
		if (game->board[row + 1][col] == '*')
			bombs++;
		if (col + 1 < game->width)
			if (game->board[row + 1][col + 1] == '*')
			bombs++;
	}
	if (col - 1 >= 0)
		if (game->board[row][col - 1] == '*')
			bombs++;
	if (col + 1 < game->width)
		if (game->board[row][col + 1] == '*')
			bombs++;
	return (bombs + '0');
}

void	set_board(t_game *game)
{
	int	i;
	int	tile;

	i = 0;
	while(i < game->number_bombs)
	{
		tile = rand() % (game->height * game->width);
		if (tile/game->width != game->coord_row || tile%game->width != game->coord_col)
		{
			if(game->board[tile/game->width][tile%game->width] != '*')
				i++;
			game->board[tile/game->width][tile%game->width] = '*';
		}
	}
	i = 0;
	while (i < (game->height * game->width))
	{
		if(game->board[i/game->width][i%game->width] != '*')
			game->board[i/game->width][i%game->width] = count_bombs(game, i);
		i++;
	}
}

void	create_boards(t_game *game)
{
	game->board = new char* [game->height];
	for(int i = 0; i < game->height; i++)
	{
		game->board[i] = new char [game->width];
		for (int j = 0; j < game->width; j++)
			game->board[i][j] = '.';
	}
	game->score_board = new char* [game->height];
	for(int i = 0; i < game->height; i++)
	{
		game->score_board[i] = new char [game->width];
		for (int j = 0; j < game->width; j++)
			game->score_board[i][j] = '.';
	}
	game->player_board = new char* [game->height];
	for(int i = 0; i < game->height; i++)
	{
		game->player_board[i] = new char [game->width];
		for (int j = 0; j < game->width; j++)
			game->player_board[i][j] = '.';
	}
}