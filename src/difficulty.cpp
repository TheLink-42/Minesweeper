#include "minesweeper.hpp"

void	print_difficulty_menu( void )
{
	std::cout << "------------------------------------" << std::endl;
	std::cout << "Please, select the difficulty level:" << std::endl;
	std::cout << "\tBeginner (10 bombs) [1]" << std::endl;
	std::cout << "\tIntermediate (40 bombs) [2]" << std::endl;
	std::cout << "\tAdvanced (99 bombs) [3]" << std::endl;
	std::cout << "------------------------------------" << std::endl;

}

void	set_diff(t_game *game)
{
	std::string	difficulty;

	while(game->difficulty < 1 || game->difficulty > 3)
	{
		if(game->difficulty != 0)
			std::cout << "Please, select a difficulty level inside the parameters (1 - 3)" << std::endl;
		print_difficulty_menu();
		std::getline(std::cin, difficulty);
		game->difficulty = stoi(difficulty);
		if(game->difficulty == 0)
			game->difficulty = -1;
	}
}