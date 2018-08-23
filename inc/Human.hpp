#ifndef HUMAN_HPP
# define HUMAN_HPP

# include "Player.hpp"
# include "Computer.hpp"

class Human : public Player, private Game
{
public:
	Human(char c);
	~Human();
	
	void	step() override;
private:
	void	_do_step(int x, int y) override;
	char	_symbol;
};

#endif