#include "minesweeper.hpp"

char	count_bombs(t_game *game, int i)
{
	int	row;
	int	col;
	int	nrow;
	int	ncol;
	int	bombs;

	row = i/game->width;
	col = i%game->width;
	bombs = 0;
	
	for (int r = -1; r < 2; r++)
	{
		for (int c = -1; c < 2; c++)
		{
			if (!r && !c)
				continue;
			nrow = row + r;
			ncol = col + c;
			if (nrow >= 0 && nrow < game->height && ncol >= 0 && ncol < game->width)
				if (game->board[nrow][ncol] == '*')
					bombs++;
		}
	}
	return (bombs + '0');
}

bool	adjacent(t_game *game, int row, int col)
{
	if (row >= game->coord_row - 1 && row <= game->coord_row + 1 &&
		col >= game->coord_col - 1  && col <= game->coord_col + 1)
		return true;
	return false;
}

void	set_board(t_game *game)
{
	int	i;
	int	row;
	int col;

	i = 0;
	while(i < game->number_bombs)
	{
		row = rand() % game->height;
		col = rand() % game->width;
		if (!adjacent(game, row, col))
		{
			if(game->board[row][col] != '*')
				i++;
			game->board[row][col] = '*';
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
	game->score_board = new char* [game->height];
	game->player_board = new char* [game->height];
	for(int i = 0; i < game->height; i++)
	{
		game->board[i] = new char [game->width];
		game->score_board[i] = new char [game->width];
		game->player_board[i] = new char [game->width];
		for (int j = 0; j < game->width; j++)
		{
			game->board[i][j] = '.';
			game->score_board[i][j] = '.';
			game->player_board[i][j] = '.';
		}
	}
}
