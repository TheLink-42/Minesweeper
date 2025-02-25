#pragma once

class Cell
{
    private:
    	typedef enum {NUMBER, EMPTY, MINE} State;
		State	state;

		bool	exposed;
 		int		number;
		bool	marked;

	public:
		Cell();
		~Cell();

		void	destroy();

		bool	get_exposed() const;
		bool	get_marked() const;
		int 	get_number() const;

		bool	is_empty() const;
		bool	is_mine() const;
		bool	is_number() const;

		void	hide_cell();
		void	expose_cell();
		void	mark_cell();
		void	unmark_cell();

		void	set_mine();
		void	set_number(int n);
};
