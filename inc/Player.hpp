#ifndef PLAYER_HPP
# define PLAYER_HPP

class Player
{
public:
	
	~Player() {}

	virtual void	step() = 0;

private:
	virtual void	_do_step(int x, int y) = 0;
};

#endif