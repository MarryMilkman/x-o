#include "Game.hpp"
#include "Computer.hpp"
#include "Human.hpp"

Game::Game()
{
	this->_intro();
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
	std::cout << std::endl;
}

Game::~Game()
{
	delete this->_map;
	if (this->_player_x->is_human())
	{
		delete reinterpret_cast<Human *>(this->_player_o);
		delete reinterpret_cast<Computer *>(this->_player_x);
	}
	else
	{
		delete reinterpret_cast<Human *>(this->_player_x);
		delete reinterpret_cast<Computer *>(this->_player_o);
	}
}

void		Game::play()
{
	int		*coord;

	this->_dicplay();
	while (1)
	{
		std::cout << "Player X" << std::endl;
		coord = this->_player_x->step();
		this->_enter_sym(coord, 'x');
		this->_dicplay();
		this->_check_map();

		std::cout << "Player O" << std::endl;
		coord = this->_player_o->step();
		this->_enter_sym(coord, 'o');
		this->_dicplay();
		this->_check_map();
	}
}

void		Game::_intro()
{
	std::cout << "To select a sector, press the corresponding digit:\n";
	std::cout << "  -------\n";
	std::cout << "  |7|8|9|\n";
	std::cout << "  |4|5|6|\n";
	std::cout << "  |1|2|3|\n";
	std::cout << "  -------\n";
	std::cout << "By Odin, by Thor! Use your brain!!!\n";
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
		std::cout << "Choose your Hero ('x' or 'o')\n";
		std::getline(std::cin, buf);
		if (std::cin.eof())
		{
			std::cout << "Nooooooooo\n";
			exit (0);
		}
		if ((buf[0] == 'x' || buf[0] == 'X') && buf.size() == 1)
			return (1);
		else if ((buf[0] == 'o' || buf[0] == 'O') && buf.size() == 1)
			return (0);
		else
		{
			std::cout << "There are no such Heroes\n";
			continue;
		}
	}
}

void	Game::_dicplay() const
{
	static int	cycle = 0;
	int			i;

	std::cout << "< Cycle " << cycle << " >\n";
	i = 0;
	std::cout << "  -------\n";
	while (i < 3)
	{
		std::cout << "  |" << static_cast<char>(this->_map->arr_str[i][0]);
		std::cout << "|" << static_cast<char>(this->_map->arr_str[i][1]);
		std::cout << "|" << static_cast<char>(this->_map->arr_str[i][2]) << "|\n";
		i++;
	}
	std::cout << "  -------\n";
	cycle++;
}

void	Game::_check_map()
{
	int		c;

	if ((c = this->_check_winer()))
	{
		std::cout << "'" << static_cast<char>(c) << "' won!\n";
		if (c == 'x')
			this->_player_x->win_phrase();
		if (c == 'o')
			this->_player_o->win_phrase();
		exit (0);
	}
	if (this->_check_draw())
	{
		std::cout << "Drow!\n";
		exit(0);
	}
}

char	Game::_check_winer()
{
	int								i;
	int								count;
	char							c;
	std::list<t_sector>::iterator	it;
	std::list<t_sector>				line;

	i = 0;
	while (i < 8)
	{
		line = this->_map->line[i];
		it = line.begin();
		c = *(it->symbol);
		count = 0;
		while (it != line.end())
		{
			if (*(it->symbol) != c || *(it->symbol) == '.')
				break ;
			count++;
			it++;
		}
		if (count == 3)
			return (c);
		i++;
	}
	return (0);
}

int		Game::_check_draw()
{
	int		i;
	std::list<t_sector>::iterator	it;
	std::list<t_sector>			line;

	i = 0;
	while (i < 8)
	{
		line = this->_map->line[i];
		it = line.begin();
		while (it != line.end())
		{
			if (*(it->symbol) == '.')
				return (0) ;
			it++;
		}
		i++;
	}
	return (1);
}