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

protected:
	static std::vector<std::string>	_map;
};

#endif