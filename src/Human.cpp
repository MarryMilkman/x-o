#include "Human.hpp"

Human::Human(char c, t_map & map) : _symbol(c), _map(&map)
{
}

Human::~Human()
{
}

void		Human::step()
{
	std::string		buf;
	int				x;
	int				y;

	std::cout << "Enter coords:\n";
	x = 0;
	y = 0;
	while (std::cin.fail() == 0)
	{
		std::getline(std::cin, buf);
		if (buf[0] >= '1' && buf[0] <= '3' && buf[1] == '-'
			&& buf[2] >= '1' && buf[2] <= '3')
		{
			x = buf[0] - '0';
			y = buf[2] - '0';
			break ;
		}
		if (std::cin.fail() == 0)
			std::cout << "Invalid coord. Exampl: 1-2\n";
	}
	this->_do_step(x, y);
}

void		Human::_do_step(int x, int y)
{
	this->_map->vect[x - 1][y - 1] = this->_symbol;
}