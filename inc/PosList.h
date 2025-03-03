#pragma once

const int MAX_LIST = 100;

class PosList
{
	private:
		typedef struct
		{
			int	posx;
			int	posy;
		}	Position;

		int count;
		Position list[MAX_LIST];


	public:
		PosList();							//Constructor por defecto
		~PosList();							//Destructor por defecto

		int		get_length() const;			//Obtencion tamaño de la lista
		int		get_posx(int i) const;		//Coordenada x de la posicion pedida
		int		get_posy(int i) const;		//Coordenada y de la posicion pedida

		void	destroy();					//Reestablecimiento de valores base
		void	add_last(int x, int y);		//Añadir una nueva posicion al final con sus respectivas coordenadas

};

