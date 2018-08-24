#include "Game.hpp"
#include "Computer.hpp"
#include "Human.hpp"

Game::Game()
{
	this->_map = new Map();
	if (this->_human_first())
	{
		this->_player_x = new Human(this->_map);
		this->_player_o = new Computer('o', this->_map);
	}
	else
	{
		this->_player_x = new Computer('x', this->_map);
		this->_player_o = new Human(this->_map);
	}

	///test////////////////////////////////


//	this->_map->arr_str[0][0] = 'x';
	// this->_map->arr_str[1][1] = 'x';
	// this->_map->arr_str[2][2] = 'o';
	// this->_map->arr_str[1][0] = 'x';
	// this->_map->arr_str[2][0] = 'x';
	// this->_map->arr_str[0][2] = 'x';
	// this->_dicplay();
	// std::list<t_sector>::iterator it;
	// int	i;

	// i = 0;
	// while (i < 8)
	// {
	// 	std::cout << "line:" << i << " \n";
	// 	it = (this->_map->line)[i].begin();
	// 	while (it != (this->_map->line)[i].end())
	// 	{
	// 		std::cout << *(it->symbol) << ", coord[0] = ";
	// 		std::cout << it->coord[0] << ", coord[1] = ";
	// 		std::cout << it->coord[1] << "\n";
	// 		it++;
	// 	}
	// 	std::cout << std::endl;
	// 	i++;
	// }
	// exit(0);

// 	// end test///////////////////////////////
	
	std::cout << std::endl;
}

Game::~Game()
{
}

void		Game::play()
{
	int		*coord;

	while (1)
	{
		coord = this->_player_x->step();
		this->_enter_sym(coord, 'x');
		std::cout << "Player X" << std::endl;
		this->_dicplay();
		this->_check_winer();
		
		coord = this->_player_o->step();
		this->_enter_sym(coord, 'o');
		std::cout << "Player O" << std::endl;
		this->_dicplay();
		this->_check_winer();
	//	system("leaks game_x_o");
	}
}

void		Game::_enter_sym(int coord[2], char c)
{
	this->_map->arr_str[coord[0]][coord[1]] = c;
	delete[] coord;
}

int			Game::_human_first()
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

void	Game::_dicplay() const
{
	std::cout << "+\n";
	std::cout << " " << this->_map->arr_str[0] << std::endl;
	std::cout << " " << this->_map->arr_str[1] << std::endl;
	std::cout << " " << this->_map->arr_str[2] << std::endl;
}

void	Game::_check_winer()
{
	std::list<t_sector>::iterator	it;
	int								i;
	char							c;
	int								count;

	i = 0;
	count = 0;
	while (i < 8)
	{
		it = (this->_map->line)[i].begin();
		c = 0;
		while (it != (this->_map->line)[i].end())
		{
			if (*(it->symbol) == '.')
			{
				c = 0;
				count++;
				break ;
			}
			c == 0 ? c = *(it->symbol) : 0;
			if (c != *(it->symbol))
			{
				c = 0;
				break ;
			}
			it++;
		}
		if (c)
		{
			std::cout << "Congratulation! '" << c << "' won\n";
			exit (0);
		}
		i++;
	}
	if (!count)
	{
		std::cout << "Draw\n";
		exit(0);
	}
}



