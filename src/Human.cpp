#include "Human.hpp"

Human::Human(Map *map) : _map(map)
{
}

Human::~Human()
{
}

int				*Human::step()
{
	std::string			buf;
	int					*coord = new int[2];

	std::cout << "Enter coords:\n";
	while (std::cin.fail() == 0)
	{
		std::getline(std::cin, buf);
		if (buf[0] >= '1' && buf[0] <= '3' && buf[1] == '-'
			&& buf[2] >= '1' && buf[2] <= '3')
		{
			coord[0] = buf[0] - '0' - 1;
			coord[1] = buf[2] - '0' - 1;
			if (!this->_check_coord(coord))
			{
				std::cout << "Cell is busy. Try again\n";
				continue;
			}
			break ;
		}
		if (std::cin.fail() == 0)
			std::cout << "Invalid coord. Exampl: 1-2\n";
	}
	return (coord);
}

int				Human::_check_coord(int const *coord)
{				
	if (this->_map->arr_str[coord[0]][coord[1]] != '.')
		return (0);
	return (1);
}