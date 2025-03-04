#include "inputOutput.h"

using namespace std;

////////////////////////////////////////////////////////////////////////////////
////																		////
////							MENU DISPLAY								////
////																		////
////////////////////////////////////////////////////////////////////////////////

void	display_intro()
{
	cout << MAGENTA;
	cout << "+------------------------------+" << endl;
	cout << "|          Buscaminas          |" << endl;
	cout << "+------------------------------+" << RESET << endl;
}

namespace
{
	void	display_gameover()
	{
		cout << RED;
		cout << "+------------------------------+" << endl;
		cout << "|          GAME  OVER          |" << endl;
		cout << "+------------------------------+" << RESET << endl;
		/*
		string color = BG_RED;

		cout << color << setw(8) << ' ' << RESET << setw(2) << ' '; //1-G
		cout << color << setw(8) << ' ' << RESET << setw(2) << ' '; //1-A
		cout << color << setw(2) << ' ' << RESET << setw(4) << ' ' << color << setw(2) << ' ' << RESET << setw(2) << ' '; //1-M
		cout << color << setw(8) << ' ' << RESET << setw(7) << ' '; //1-E
		cout << color << setw(8) << ' ' << RESET << setw(2) << ' '; //1-O
		cout << color << setw(2) << ' ' << RESET << setw(4) << ' ' << color << setw(2) << ' ' << RESET << setw(2) << ' '; //1-V
		cout << color << setw(8) << ' ' << RESET << setw(2) << ' '; //1-E
		cout << color << setw(8) << ' ' << RESET << endl; //1-R

		cout << color << setw(2) << ' ' << RESET << setw(8) << ' '; //2-G
		cout << color << setw(2) << ' ' << RESET << setw(4) << ' ' << color << setw(2) << ' ' << RESET << setw(2) << ' '; //2-A 
		cout << color << setw(3) << ' ' << RESET << setw(2) << ' ' << color << setw(3) << ' ' << RESET << setw(2) << ' '; //2-M
		cout << color << setw(2) << ' ' << RESET << setw(13) << ' '; //2-E
		cout << color << setw(2) << ' ' << RESET << setw(4) << ' ' << color << setw(2) << ' ' << RESET << setw(2) << ' '; //2-O
		cout << color << setw(2) << ' ' << RESET << setw(4) << ' ' << color << setw(2) << ' ' << RESET << setw(2) << ' '; //2-V
		cout << color << setw(2) << ' ' << RESET << setw(8) << ' '; //2-E
		cout << color << setw(2) << ' ' << RESET << setw(4) << ' ' << color << setw(2) << ' ' << RESET << endl; //2-R

		cout << color << setw(2) << ' ' << RESET << setw(3) << ' ' << color << setw(3) << ' ' << RESET << setw(2) << ' '; //3-G
		cout << color << setw(8) << ' ' << RESET << setw(2) << ' '; //3-A
		cout << color << setw(2) << ' ' << RESET << setw(1) << ' ' << color << setw(2) << ' ' << RESET << setw(1) << ' '  << color << setw(2) << ' ' << RESET << setw(2) << ' '; //3-M
		cout << color << setw(8) << ' ' << RESET << setw(7) << ' '; //3-E
		cout << color << setw(2) << ' ' << RESET << setw(4) << ' ' << color << setw(2) << ' ' << RESET << setw(3) << ' '; //3-O
		cout << color << setw(2) << ' ' << RESET << setw(2) << ' ' << color << setw(2) << ' ' << RESET << setw(3) << ' '; //3-V
		cout << color << setw(8) << ' ' << RESET << setw(2) << ' '; //3-E
		cout << color << setw(8) << ' ' << RESET << endl; //3-R

		cout << color << setw(2) << ' ' << RESET << setw(4) << ' ' << color << setw(2) << ' ' << RESET << setw(2) << ' '; //4-G 
		cout << color << setw(2) << ' ' << RESET << setw(4) << ' ' << color << setw(2) << ' ' << RESET << setw(2) << ' '; //4-A
		cout << color << setw(2) << ' ' << RESET << setw(4) << ' ' << color << setw(2) << ' ' << RESET << setw(2) << ' '; //4-M
		cout << color << setw(2) << ' ' << RESET << setw(13) << ' '; //4-E
		cout << color << setw(2) << ' ' << RESET << setw(4) << ' ' << color << setw(2) << ' ' << RESET << setw(3) << ' '; //4-O
		cout << color << setw(2) << ' ' << RESET << setw(2) << ' ' << color << setw(2) << ' ' << RESET << setw(3) << ' '; //4-V
		cout << color << setw(2) << ' ' << RESET << setw(8) << ' '; //4-E
		cout << color << setw(2) << ' ' << RESET << setw(2) << ' ' << color << setw(2) << ' ' << RESET << endl; // 4-R

		cout << color << setw(8) << ' ' << RESET << setw(2) << ' '; //5-G
		cout << color << setw(2) << ' ' << RESET << setw(4) << ' ' << color << setw(2) << ' ' << RESET << setw(2) << ' '; //5-A
		cout << color << setw(2) << ' ' << RESET << setw(4) << ' ' << color << setw(2) << ' ' << RESET << setw(2) << ' '; //5-M
		cout << color << setw(8) << ' ' << RESET << setw(7) << ' '; //5-E
		cout << color << setw(8) << ' ' << RESET << setw(5) << ' '; //5-O
		cout << color << setw(2) << ' ' << RESET << setw(5) << ' '; //5-V
		cout << color << setw(8) << ' ' << RESET << setw(2) << ' '; //5-E
		cout << color << setw(2) << ' ' << RESET << setw(4) << ' ' << color << setw(2) << ' ' << RESET << endl; // 5-R	*/
	}
	void	display_victory()
	{
		cout << LGREEN;
		cout << "+------------------------------+" << endl;
		cout << "|           VICTORIA           |" << endl;
		cout << "+------------------------------+" << RESET << endl;

		/*
		string color = BG_LGREEN;

		cout << color << setw(2) << ' ' << RESET << setw(4) << ' ' << color << setw(2) << ' ' << RESET << setw(2) << ' '; //1-V
		cout << color << setw(8) << ' ' << RESET << setw(2) << ' '; //1-I
		cout << color << setw(8) << ' ' << RESET << setw(2) << ' '; //1-C
		cout << color << setw(8) << ' ' << RESET << setw(2) << ' '; //1-T
		cout << color << setw(8) << ' ' << RESET << setw(2) << ' '; //1-O
		cout << color << setw(8) << ' ' << RESET << setw(2) << ' '; //1-R
		cout << color << setw(2) << ' ' << RESET << setw(4) << ' ' << color << setw(2) << ' ' << RESET << endl; //1-Y

		cout << color << setw(2) << ' ' << RESET << setw(4) << ' ' << color << setw(2) << ' ' << RESET << setw(5) << ' '; //2-V
		cout << color << setw(2) << ' ' << RESET << setw(5) << ' '; //2-I
		cout << color << setw(2) << ' ' << RESET << setw(11) << ' '; //2-C
		cout << color << setw(2) << ' ' << RESET << setw(5) << ' '; //2-T
		cout << color << setw(2) << ' ' << RESET << setw(4) << ' ' << color << setw(2) << ' ' << RESET << setw(2) << ' '; //2-O
		cout << color << setw(2) << ' ' << RESET << setw(4) << ' ' << color << setw(2) << ' ' << RESET << setw(3) << ' '; //2-R
		cout << color << setw(2) << ' ' << RESET << setw(2) << ' ' << color << setw(2) << ' ' << RESET << endl; //2-Y

		cout << ' ' << color << setw(2) << ' ' << RESET << setw(2) << ' ' << color << setw(2) << ' ' << RESET << setw(6) << ' '; //3-V
		cout << color << setw(2) << ' ' << RESET << setw(5) << ' '; //3-I
		cout << color << setw(2) << ' ' << RESET << setw(11) << ' '; //3-C
		cout << color << setw(2) << ' ' << RESET << setw(5) << ' '; //3-T
		cout << color << setw(2) << ' ' << RESET << setw(4) << ' ' << color << setw(2) << ' ' << RESET << setw(2) << ' '; //3-O
		cout << color << setw(8) << ' ' << RESET << setw(4) << ' '; //3-R
		cout << color << setw(4) << ' ' << RESET << endl; //3-Y

		cout << ' ' << color << setw(2) << ' ' << RESET << setw(2) << ' ' << color << setw(2) << ' ' << RESET << setw(6) << ' '; //4-V
		cout << color << setw(2) << ' ' << RESET << setw(5) << ' '; //4-I
		cout << color << setw(2) << ' ' << RESET << setw(11) << ' '; //4-C
		cout << color << setw(2) << ' ' << RESET << setw(5) << ' '; //4-T
		cout << color << setw(2) << ' ' << RESET << setw(4) << ' ' << color << setw(2) << ' ' << RESET << setw(2) << ' '; //4-O
		cout << color << setw(2) << ' ' << RESET << setw(2) << ' ' << color << setw(2) << ' ' << RESET << setw(7) << ' '; //4-R
		cout << color << setw(2) << ' ' << RESET << endl; //4-Y

		cout << "   " << color << setw(2) << ' ' << RESET << setw(5) << ' '; //5-V
		cout << color << setw(8) << ' ' << RESET << setw(2) << ' '; //5-I
		cout << color << setw(8) << ' ' << RESET << setw(5) << ' '; //5-C
		cout << color << setw(2) << ' ' << RESET << setw(5) << ' '; //5-T
		cout << color << setw(8) << ' ' << RESET << setw(2) << ' '; //1-O
		cout << color << setw(2) << ' ' << RESET << setw(4) << ' ' << color << setw(2) << ' ' << RESET << setw(5) << ' '; //5-R
		cout << color << setw(2) << ' ' << RESET << endl; //5-Y */
	}
/*	void	display_score(const Game& game)
	{

	}*/
}

void	display_result(const Game& game)
{
	if (game.exposed_mine())
		display_gameover();
	else
		display_victory();
//	display_score(game);
}


////////////////////////////////////////////////////////////////////////////////
////																		////
////							GAME LOADING								////
////																		////
////////////////////////////////////////////////////////////////////////////////

bool	load_game(Game& game)
{
	ifstream	file;
	string		file_name;
	bool		valid = false;

	cout << "Por favor, introduzca el nombre del fichero escogido: ";
	cin >> file_name;
	file_name = "./tools/" + file_name;
	file.open(file_name.c_str());
	if (!file.is_open())
		cerr << "Error: No se pudo abrir el archivo " << file_name << endl;
	else
	{
		file >> game;
		valid = true;
		file.close();
	}

	return valid;
}


////////////////////////////////////////////////////////////////////////////////
////																		////
////							GAME DISPLAY								////
////																		////
////////////////////////////////////////////////////////////////////////////////

void	display_game(Game game)
{
	cout << game;
}


////////////////////////////////////////////////////////////////////////////////
////																		////
////							USER INPUT									////
////																		////
////////////////////////////////////////////////////////////////////////////////

void	ask_pos(int& row, int& col)
{
	cout << "Por favor, introduzca las coordenadas deseadas" << endl;
	cout << "Opciones:" << endl;
	cout << "\t+ -3 -3 (Deshacer ultimo movimiento)" << endl;
	cout << "\t+ -2 -2 (Activar modo bandera)" << endl;
	cout << "\t+ -1 -1 (Rendirse. Contara como derrota)" << endl;
	cout << "\t+ 0+ 0+ (Coordenadas sobre las que se desea jugar)" << endl;
	cin >> row >> col;
}


////////////////////////////////////////////////////////////////////////////////
////																		////
////								OPERATORS								////
////																		////
////////////////////////////////////////////////////////////////////////////////

std::istream&	operator>>(std::istream& in, Game& game)
{
	int		row;
	int		col;
	int		mines;

	in >> row >> col >> mines;
	Game	new_game(row, col);

	for(int i = 0; i < mines; i++)
	{
		in >> row >> col;
		new_game.set_mine(row, col);
	}
//	fill_numbers(new_game);
	game = new_game;
	return in;
}


namespace
{
	void color_number(int number)
	{
		switch (number) {
		case 1: cout << BLUE; break;
		case 2: cout << GREEN; break;
		case 3: cout << RED; break;
		case 4: cout << DBLUE; break;
		case 5: cout << DGREEN; break;
		case 6: cout << DRED; break;
		default:
			break;
		}
	}
	void	print_movements(const Game& game)
	{
		cout << MAGENTA;
		cout << "+------------------------------+" << endl;
		cout << "|Jugadas: " << LBLUE << left << setw(21) << game.get_movements() << right << MAGENTA << '|' << endl;
		cout << "|Minas:   " << LBLUE << left << setw(21) << game.get_player_mines() << right << MAGENTA << '|' << endl;
		cout << "|Bandera: ";
		if (game.get_mode())
			cout << LGREEN << "ON" << MAGENTA << setw(20) << '|' << endl;
		else
			cout << RED << "OFF" << MAGENTA << setw(19) << '|' << endl;
		cout << "+------------------------------+" << RESET << endl;
	}
	void	print_header(const Game& game)
	{
		cout << "\t  |";
		for (int i = 0; i < game.get_cols(); i++)
			cout << LBLUE << setw(N_SPACE) << i << RESET << "|";
		cout << endl;
	}
	void	print_delimiter(const Game& game)
	{
		cout << "\t -+";
		for (int i = 0; i < game.get_cols(); i++)
			cout << setw(N_SPACE + 1) << setfill('-') << '+' << setfill(' ');
		cout << endl;
	}
	void	print_cell(const Game& game, int i, int j)
	{
		int	number;

		cout << BG_GRAY << BLACK;
		if (!game.is_exposed(i, j))
		{
			if (game.is_marked(i, j))
				cout << BG_ORANGE << ORANGE;
			cout << setw(N_SPACE) << setfill(' ') << ' ' << RESET;
		}
		else
		{
			cout << BG_BLACK;
			if (game.is_mine(i, j))
				cout << RED << setw(N_SPACE) << setfill(' ') << '*' << RESET;
			else
			{
				number = game.get_number(i, j);
				color_number(number);
				if (!number)
					cout << setw(N_SPACE) << setfill(' ') << ' ' << RESET;
				else
					cout << setw(N_SPACE) << setfill(' ') << number << RESET;
			}
		}
		cout << "|";
	}
}

std::ostream&	operator<<(std::ostream& out, Game& game)
{
	print_movements(game);
	print_header(game);
	print_delimiter(game);
	for (int i = 0; i < game.get_rows(); i++)
	{
		cout << LBLUE << "\t" << setw(N_SPACE) << i << RESET << "|";
		for (int j = 0; j < game.get_cols(); j++)
			print_cell(game, i, j);
		cout << endl;
		print_delimiter(game);
	}
	return out;
}