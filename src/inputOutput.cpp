#include "inputOutput.h"
#include "GestorJuegos.h"

using namespace std;
std::istream&	operator>>(std::istream& in, Juego& juego);
std::ostream&	operator<<(std::ostream& out, Juego& juego);

////////////////////////////////////////////////////////////////////////////////
////																		////
////							MENU DISPLAY								////
////																		////
////////////////////////////////////////////////////////////////////////////////

void	mostrar_cabecera()
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
	}
	void	display_victoria()
	{
		cout << LGREEN;
		cout << "+------------------------------+" << endl;
		cout << "|           VICTORIA           |" << endl;
		cout << "+------------------------------+" << RESET << endl;
	}
	void	display_forfeit()
	{
		cout << RED;
		cout << "+------------------------------+" << endl;
		cout << "|           RENDIDO            |" << endl;
		cout << "+------------------------------+" << RESET << endl;
	}
}

void	mostrar_resultado(GestorJuegos& GP, int pos, const Juego& juego)
{
	if (juego.mina_explotada())
		display_gameover();
	else if (juego.esta_completo())
	{
		display_victoria();
		GP.eliminar(pos);
	}
	else
		display_forfeit();
}


////////////////////////////////////////////////////////////////////////////////
////																		////
////							GAME LOADING								////
////																		////
////////////////////////////////////////////////////////////////////////////////

Juego	carga_juego(ifstream& file)
{
	Juego	juego;
	file >> juego;

	return juego;
}


////////////////////////////////////////////////////////////////////////////////
////																		////
////							GAME DISPLAY								////
////																		////
////////////////////////////////////////////////////////////////////////////////

void	mostrar_juego(Juego juego)
{
	cout << juego;
}


////////////////////////////////////////////////////////////////////////////////
////																		////
////							USER INPUT									////
////																		////
////////////////////////////////////////////////////////////////////////////////

void	pedir_pos(int& row, int& col)
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

std::istream&	operator>>(std::istream& in, Juego& juego)
{
	int		row;
	int		col;
	int		mines;

	in >> row >> col >> mines;
	Juego	nuevo_juego(row, col);

	for(int i = 0; i < mines; i++)
	{
		in >> row >> col;
		nuevo_juego.poner_mina(row, col);
	}
	juego = nuevo_juego;
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
	void	print_movements(const Juego& juego)
	{
		cout << MAGENTA;
		cout << "+------------------------------+" << endl;
		cout << "|Jugadas: " << LBLUE << left << setw(21) << juego.dame_num_jugadas() << right << MAGENTA << '|' << endl;
		cout << "|Minas:   " << LBLUE << left << setw(21) << juego.get_display_mines() << right << MAGENTA << '|' << endl;
		cout << "|Bandera: ";
		if (juego.get_mode())
			cout << LGREEN << "ON" << MAGENTA << setw(20) << '|' << endl;
		else
			cout << RED << "OFF" << MAGENTA << setw(19) << '|' << endl;
		cout << "+------------------------------+" << RESET << endl;
	}
	void	print_header(const Juego& juego)
	{
		cout << "\t  |";
		for (int i = 0; i < juego.dame_num_columnas(); i++)
			cout << LBLUE << setw(N_SPACE) << i << RESET << "|";
		cout << endl;
	}
	void	print_delimiter(const Juego& juego)
	{
		cout << "\t -+";
		for (int i = 0; i < juego.dame_num_columnas(); i++)
			cout << setw(N_SPACE + 1) << setfill('-') << '+' << setfill(' ');
		cout << endl;
	}
	void	print_cell(const Juego& juego, int i, int j)
	{
		int	number;

		cout << BG_GRAY << BLACK;
		if (!juego.esta_descubierta(i, j))
		{
			if (juego.esta_marcada(i, j))
				cout << BG_ORANGE << ORANGE;
			cout << setw(N_SPACE) << setfill(' ') << ' ' << RESET;
		}
		else
		{
			cout << BG_BLACK;
			if (juego.contiene_mina(i, j))
				cout << RED << setw(N_SPACE) << setfill(' ') << '*' << RESET;
			else
			{
				number = juego.dame_numero(i, j);
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

std::ostream&	operator<<(std::ostream& out, Juego& juego)
{
	print_movements(juego);
	print_header(juego);
	print_delimiter(juego);
	for (int i = 0; i < juego.dame_num_filas(); i++)
	{
		cout << LBLUE << "\t" << setw(N_SPACE) << i << RESET << "|";
		for (int j = 0; j < juego.dame_num_columnas(); j++)
			print_cell(juego, i, j);
		cout << endl;
		print_delimiter(juego);
	}
	return out;
}