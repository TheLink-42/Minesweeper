#pragma once

class Celda
{
    private:
    	typedef enum {NUMERO, VACIO, MINA} Estado;
		Estado	estado;

		bool	descubierta;
 		int		numero;
		bool	marcada;

	public:
		Celda();							//Constructor por defecto
/**/		~Celda();						//Destructor por defecto

		void	destruye();				//Reestablecimiento de valores base

		bool	esta_descubierta() const;	//Obtencion de casilla descubierta
		bool	esta_marcada() const;		//Obtencion de casilla marcada
		int 	dame_numero() const;		//Obtención de numero asignado a la casilla

		bool	esta_vacia() const;		//Comprobacion casilla vacia
		bool	contiene_mina() const;		//Comprobacion casilla con mina
		bool	contiene_numero() const;		//Comprobacion casilla con numero

		void	ocultar_celda();			//Tapar una celda
		void	descubrir_celda();			//Descubrir una celda
		void	marcar_celda();			//Marcar una celda
		void	desmarcar_celda();			//Desmarcar una celda

		void	poner_mina();				//Asignar una mina
		void	poner_numero(int n);		//Asignar un numero
};
