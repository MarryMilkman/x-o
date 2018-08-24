#ifndef PLAYER_HPP
# define PLAYER_HPP

# include "game_lib.h"

class Player
{
public:
	
	~Player() {}

	virtual int						*step() = 0;

private:
	virtual	int						_check_coord(int const *coord) = 0;
};

#endif