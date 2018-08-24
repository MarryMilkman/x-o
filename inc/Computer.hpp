#ifndef COMPUTER_HPP
# define COMPUTER_HPP

# include "game_lib.h"
# include "Player.hpp"
# include "Game.hpp"

class Computer : public Player
{
public:
	Computer(char c, Map *map);
	~Computer();
	
	int						*step() override;
private:
	int						_check_danger(int *coord);
	int						_check_win(int *coord);
	int						_check_coord(int const *coord) override;
	void					_attack_mod(int *coord);
	void					_find_first_empty(int *coord);

	char					_symbol;
	char					_enemy_symbol;
	Map						*_map;
};
#endif