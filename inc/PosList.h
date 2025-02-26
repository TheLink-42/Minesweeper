#pragma once

int const MAX_LIST = 100;

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
		PosList();
		~PosList();

		int	get_length() const;
		int	get_posx(int i) const;
		int	get_posy(int i) const;

		void	destroy();
		void	add_last(int x, int y);

};

