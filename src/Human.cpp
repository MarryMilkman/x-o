#include "Human.hpp"

Human::Human(Map *map)
{
	this->_map = map;
}

Human::~Human()
{
}


void			Human::win_phrase()
{
	std::cout << "I do not know how, but you won 0_0\n";
}

int				*Human::step()
{
	std::string			buf;
	int					*coord = new int[2];

	std::cout << "Enter coords:\n";
	while (std::cin.fail() == 0)
	{
		std::getline(std::cin, buf);
		if (std::cin.eof())
		{
			std::cout << "Nooooooooo\n";
			exit (0);
		}
		if (buf[0] > '9' || buf[0] < '1' || buf.size() > 1)
		{
			std::cout << "Put right number (1 - 9)\n";
			continue;
		}
		switch (buf[0])
		{
			case '7':
			{
				std::cout << "Im hear\n";
				coord[0] = 0;
				coord[1] = 0;
				break ;
			}
			case '8':
			{
				coord[0] = 0;
				coord[1] = 1;
				break ;
			}
			case '9':
			{
				coord[0] = 0;
				coord[1] = 2;
				break ;
			}
			case '4':
			{
				coord[0] = 1;
				coord[1] = 0;
				break ;
			}
			case '5':
			{
				coord[0] = 1;
				coord[1] = 1;
				break ;
			}
			case '6':
			{
				coord[0] = 1;
				coord[1] = 2;
				break ;
			}
			case '1':
			{
				coord[0] = 2;
				coord[1] = 0;
				break ;
			}
			case '2':
			{
				coord[0] = 2;
				coord[1] = 1;
				break ;
			}
			case '3':
			{
				coord[0] = 2;
				coord[1] = 2;
				break ;
			}
			default:
			{
				std::cout << "Put right number (1 - 9)\n";
				continue;
			}
		}
		if (!this->_check_coord(coord))
		{
			std::cout << "Cell is busy. Try again\n";
			continue;
		}
		else
			return (coord);
	}
	return (coord);
}

int				Human::is_human()
{
	return (1);
}

int				Human::_check_coord(int const *coord)
{				
	if (this->_map->arr_str[coord[0]][coord[1]] != '.')
		return (0);
	return (1);
}