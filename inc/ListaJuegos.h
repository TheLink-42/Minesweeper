#pragma once

#include "Juego.h"

class ListaJuegos
{
	private:
		const int	CAPACIDAD = 10;
		int		cont;
		Juego** lista;
		int		capacidad;

		int		buscar(const Juego& juego) const;
		void	resize(int tamano);
	
	public:
		ListaJuegos();
		~ListaJuegos();

		int				insertar(const Juego& juego);
		int				dame_longitud() const;
		bool			es_vacia() const;
		const Juego&	dame_juego(int pos) const;
		void			eliminar(int pos);
};