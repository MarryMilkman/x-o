#include "Game.hpp"
#include "Computer.hpp"
#include "Human.hpp"

Game::Game()
{
	int			i = 0;
	this->_map.vect.reserve(3);
	while (i < 3)
		this->_map.vect[i++] = "...";
	if (this->_human_first())
	{
		this->player_x = new Human('x', this->_map);
		this->player_o = new Computer('o', this->_map);
	}
	else
	{
		this->player_x = new Computer('x', this->_map);
		this->player_o = new Human('o', this->_map);
	}
	std::cout << std::endl;
}

Game::~Game()
{
}

int	Game::_human_first()
{
	std::string	buf;

	while (1)
	{
		std::cout << "Enter symbol to play ('x' or 'o')\n";
		std::getline(std::cin, buf);
		if (buf[0] == 'x' || buf[0] == 'X')
			return (1);
		else if (buf[0] == 'o' || buf[0] == 'O')
			return (0);
		else
		{
			std::cout << "Error: Invalid symbol.\n";
			continue;
		}
	}
}

void	Game::dicplay(void) const
{
	std::cout << "0123\n";
	std::cout << "1" << this->_map.vect[0] << std::endl;
	std::cout << "2" << this->_map.vect[1] << std::endl;
	std::cout << "3" << this->_map.vect[2] << std::endl;
}

t_map	Game::_map;