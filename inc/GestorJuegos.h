#pragma once

class	ListaJuegos;
class	Juego;

class	GestorJuegos
{
	private:
		ListaJuegos	juegos;

	public:
		GestorJuegos();

		int				numero_juegos() const;
		const Juego&	dame_juego(int pos) const;

		bool			hay_juegos() const;

		bool			cargar_juegos();
		void			mostrar_lista_juegos() const;
}