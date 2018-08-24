#ifndef HUMAN_HPP
# define HUMAN_HPP

# include "game_lib.h"
# include "Player.hpp"
# include "Game.hpp"

class Human : public Player
{
public:
	Human(char c, t_map & map);
	~Human();
	
	void	step() override;
private:
	void	_do_step(int x, int y) override;
	char	_symbol;
	t_map	*_map;
};

#endif