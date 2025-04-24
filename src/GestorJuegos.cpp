#include "GestorJuegos.h"
#include "inputOutput.h"

////////////////////////////////////////////////////////////////////////////////
////																		////
////							CONSTRUCTORS								////
////																		////
////////////////////////////////////////////////////////////////////////////////

GestorJuegos::GestorJuegos(): juegos()
{

}


////////////////////////////////////////////////////////////////////////////////
////																		////
////							GETTERS & SETTERS							////
////																		////
////////////////////////////////////////////////////////////////////////////////

int	GestorJuegos::numero_juegos() const
{
	return juegos.dame_longitud();
}

const Juego&	GestorJuegos::dame_juego(int pos) const
{
	return juegos.dame_juego(pos);
}


////////////////////////////////////////////////////////////////////////////////
////																		////
////							MEMBER FUNCTIONS							////
////																		////
////////////////////////////////////////////////////////////////////////////////

bool	GestorJuegos::hay_juegos() const
{
	return !juegos.es_vacia();
}

int		GestorJuegos::insertar(const Juego& juego)
{
	return juegos.insertar(juego);
}

void	GestorJuegos::eliminar(int pos)
{
	juegos.eliminar(pos);
}

bool	GestorJuegos::cargar_juegos()
{
	std::ifstream	file;
	std::string		file_name;
	bool			valid = false;
	int				num_juegos = 0;

	std::cout << "Por favor, introduzca el nombre del fichero de juegos escogido: ";
	std::cin >> file_name;
	file.open(file_name.c_str());
	if (!file.is_open())
		std::cerr << "Error: No se pudo abrir el archivo " << file_name << std::endl;
	else
	{
		file >> num_juegos;
		if (num_juegos)
		{
			for (int i = 0; i < num_juegos; i++)
				insertar(carga_juego(file));
			valid = true;
		}
		else
			std::cerr << "Error: El fichero seleccionado no contiene juegos" << std::endl;
		file.close();
	}

	return valid;
}

void	GestorJuegos::mostrar_lista_juegos() const
{
	std::cout << "Mostrando lista de juegos por orden de dificultad..." << std::endl;
	
	int	numJuegos = numero_juegos();
	for (int i = 0; i < numJuegos; i++)
	{
		std::cout << "Juego " << i << ":" << std::endl;
		std::cout << "\tDimension: " << juegos.dame_juego(i).dame_num_filas();
		std::cout << " x " << juegos.dame_juego(i).dame_num_columnas() << std::endl;
		std::cout << "\tMinas: " << juegos.dame_juego(i).dame_num_minas() << std::endl;
	}
	std::cout << "Selecciona la partida:";
}

bool	GestorJuegos::guardar_lista_juegos() const
{
	std::ofstream	file;
	std::string		file_name;
	bool			valid = false;

	std::cout << "Por favor, introduzca el nombre del fichero donde quiere guardar los juegos: ";
	std::cin >> file_name;
	file.open(file_name.c_str());
	if (!file.is_open())
		std::cerr << "Error: No se pudo crear el archivo juegosGuardados.txt" << std::endl;
	else
	{
		int	numJuegos = numero_juegos();
		file << numJuegos << std::endl;
		for (int i = 0; i < numJuegos; i++)
		{
			int	filas = juegos.dame_juego(i).dame_num_filas();
			int	columnas = juegos.dame_juego(i).dame_num_columnas();
			int	minas = juegos.dame_juego(i).dame_num_minas();

			file << filas << " " << columnas << std::endl;
			file << minas << std::endl;
			for (int j = 0; j < filas*columnas; j++)
			{
				if (juegos.dame_juego(i).contiene_mina(j/columnas, j%columnas))
					file << j/columnas << " " << j%columnas << std::endl;
			}
		}
		valid = true;
		file.close();
	}

	return valid;
}
