#ifndef HUMAN_HPP
# define HUMAN_HPP

# include "game_lib.h"
# include "Game.hpp"

class Human : public Player
{
public:
	Human(Map *map);
	~Human();
	
	int						*step() override;
private:
	int						_check_coord(int const *coord) override;
	Map						*_map;
};

#endif