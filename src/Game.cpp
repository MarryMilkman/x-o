#include "Game.hpp"
#include "Computer.hpp"
#include "Human.hpp"

Game::Game()
{
	int			i = 0;
	Human		*human;

	if (1)//this->_human_first())
	{
		this->player_x = new Human('x');
		this->player_o = new Computer('o');
	}
	else
	{
		this->player_x = new Computer('x');
		this->player_o = new Human('o');
	}
	this->_map.reserve(3);
	while (i < 3)
		this->_map[i++] = "...";
}

Game::~Game()
{
}

void	Game::dicplay(void) const
{
	std::cout << "01234\n";
	std::cout << "1" << this->_map[0] << std::endl;
	std::cout << "2" << this->_map[1] << std::endl;
	std::cout << "3" << this->_map[2] << std::endl;
}