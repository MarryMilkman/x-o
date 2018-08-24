#ifndef GAME_HPP
# define GAME_HPP

# include "game_lib.h"
# include "Player.hpp"

class Game
{
public:
	Game();
	~Game();

	void						dicplay() const;
	Player						*player_x;
	Player						*player_o;

private:
	int							_human_first();
	static t_map				_map;
};

#endif