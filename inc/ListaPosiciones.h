#pragma once

const int MAX_LIST = 100;

class ListaPosiciones
{
	private:
		typedef struct
		{
			int	posx;
			int	posy;
		}	Posicion;

		int cont;
		Posicion lista[MAX_LIST];


	public:
		ListaPosiciones();							//Constructor por defecto
/**/		~ListaPosiciones();							//Destructor por defecto

		int		longitud() const;			//Obtencion tamaño de la lista
		int		dame_posX(int i) const;		//Coordenada x de la posicion pedida
		int		dame_posY(int i) const;		//Coordenada y de la posicion pedida

		void	destruye();					//Reestablecimiento de valores base
		void	insertar_final(int x, int y);		//Añadir una nueva posicion al final con sus respectivas coordenadas

};

