#ifndef PLAYER_HPP
# define PLAYER_HPP

# include "game_lib.h"
# include "Map.hpp"

class Player
{
public:
	
	virtual ~Player() {}

	virtual int						*step() = 0;
	virtual void					win_phrase() = 0;
	virtual int						is_human() = 0;

protected:
	virtual	int						_check_coord(int const *coord) = 0;
	Map								*_map;
};

#endif