#pragma once

class ListaPosiciones
{
	private:
		typedef struct
		{
			int	posx;
			int	posy;
		}	Posicion;

		int cont;
		Posicion* lista;


	public:
		ListaPosiciones();								//Constructor por defecto
		ListaPosiciones(const ListaPosiciones& other);	//Constructor por copia
		~ListaPosiciones();								//Destructor por defecto

		int		longitud() const;			//Obtencion tamaño de la lista
		int		dame_posX(int i) const;		//Coordenada x de la posicion pedida
		int		dame_posY(int i) const;		//Coordenada y de la posicion pedida

		void	insertar_final(int x, int y);		//Añadir una nueva posicion al final con sus respectivas coordenadas

};

