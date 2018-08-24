#ifndef GAME_HPP
# define GAME_HPP

# include "game_lib.h"
# include "Player.hpp"
# include "Map.hpp"

class Game
{
public:
	Game();
	~Game();

	void						play();

private:
	void						_dicplay() const;
	void						_enter_sym(int coord[2], char c);
	int							_human_first();
	void						_check_winer();

	Player						*_player_x;
	Player						*_player_o;
	Map							*_map;
};

#endif