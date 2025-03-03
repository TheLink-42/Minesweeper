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

void	display_difficulty_menu( void )
{
	std::cout << "------------------------------------" << std::endl;
	std::cout << "Please, select the difficulty level:" << std::endl;
	std::cout << "\tBeginner (10 bombs) [1]" << std::endl;
	std::cout << "\tIntermediate (40 bombs) [2]" << std::endl;
	std::cout << "\tAdvanced (99 bombs) [3]" << std::endl;
	std::cout << "------------------------------------" << std::endl;

}

void	display_game_over_menu(t_game *game)
{
	if (game->game_over == 1)
		std::cout << "YOU WON !!!" << std::endl;
	if (game->game_over == 2)
		std::cout << "YOU LOST !!!" << std::endl;
}

void	display_replay_menu( void )
{
	std::cout << std::endl;
	std::cout << "Do you want to play again?" << std::endl;
	std::cout << "\tYES [1]" << std::endl;
	std::cout << "\tNO [2]" << std::endl;
}