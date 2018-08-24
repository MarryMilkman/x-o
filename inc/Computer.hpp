#ifndef COMPUTER_HPP
# define COMPUTER_HPP

# include "game_lib.h"
# include "Player.hpp"
# include "Game.hpp"

class Computer : public Player
{
public:
	Computer(char c, t_map & map);
	~Computer();
	
	void	step() override;
private:
	void	_do_step(int x, int y) override;
	char	_symbol;
	t_map	*_map;
};
#endif