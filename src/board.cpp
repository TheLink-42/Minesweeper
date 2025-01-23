#include "minesweeper.hpp"

void	display_board(t_game *game)
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
			std::cout << game->board[i][j];
		std::cout << "#" << std::endl;
	}
	std::cout << " ";
	for (int i = 0; i < game->width + 2; i++)
		std::cout << "#";
	std::cout << std::endl;
}

void	create_board(t_game *game)
{
	game->board = new char* [game->height];
	for(int i = 0; i < game->height; i++)
	{
		game->board[i] = new char [game->width];
		for (int j = 0; j < game->width; j++)
			game->board[i][j] = '?';
	}
}