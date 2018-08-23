#ifndef COMPUTER_HPP
# define COMPUTER_HPP

# include "Player.hpp"
# include "Computer.hpp"

class Computer : public Player, private Game
{
public:
	Computer(char c);
	~Computer();
	
	void	step() override;
private:
	void	_do_step(int x, int y) override;
	char	_symbol;
};
#endif