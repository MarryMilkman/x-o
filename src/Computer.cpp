#include "Computer.hpp"

Computer::Computer(char c, Map *map) : _symbol(c), _map(map)
{
	this->_enemy_symbol = (this->_symbol == 'x') ? 'o' : 'x';
}

Computer::~Computer()
{
}

int		*Computer::step()
{
	int	*coord = new int[2];

	if (this->_symbol == 'x')
		this->_attack_mod(coord);
	else
	{
		coord[0] = 1;
		coord[1] = 0;
	}
	return (coord);
}

int		Computer::_check_coord(int const *coord)
{
	std::cout << "gi2\n";					
	if (this->_map->arr_str[coord[0]][coord[1]] != '.')
		return (0);
	return (1);
}

// algo

void	Computer::_attack_mod(int *coord)
{
	if (this->_check_win(coord))
		return ;
	if (this->_check_danger(coord))
		return ;
	if (this->_map->arr_str[1][1] == '.')
	{
		coord[0] = 1;
		coord[1] = 1;
		return ;
	}
	this->_find_first_empty(coord);
}

int		Computer::_check_danger(int *coord)
{
	std::list<t_sector>::iterator	it;
	int								i;
	int								denger_count;
	char							c;
	int								change;

	coord[0] = -1;
	i = 0;
	c = 0;
	while (i < 8)
	{
		change = 0;
		denger_count = 0;
		it = this->_map->line[i].begin();
		while (it != this->_map->line[i].end())
		{
			c = *(it->symbol);
			if (c == this->_enemy_symbol)
				denger_count++;
			if (c == '.')
			{
				change = 1;
				coord[0] = it->coord[0];
				coord[1] = it->coord[1];
			}
			it++;
		}
		if (denger_count >= 2)
			break ;
		i++;
	}
	if (denger_count >= 2 && change)
		return (1);
	return (0);
}

int		Computer::_check_win(int *coord)
{
	std::list<t_sector>::iterator	it;
	int								i;
	int								win_count;
	char							c;
	int								change;

	i = 0;
	c = 0;
	while (i < 8)
	{
		change = 0;
		win_count = 0;
		it = this->_map->line[i].begin();
		while (it != this->_map->line[i].end())
		{
			c = *(it->symbol);
			if (c == this->_symbol)
				win_count++;
			if (c == '.')
			{
				std::cout << "ZALUPA: " << coord[0]
					<< " : " << coord[1] << "\n";
				change = 1;
				coord[0] = it->coord[0];
				coord[1] = it->coord[1];
			}
			it++;
		}
		if (win_count >= 2)
			break ;
		i++;
	}
	if (win_count >= 2 && change)
		return (1);
	return (0);
}

void	Computer::_find_first_empty(int *coord)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (++j < 3)
			if (this->_map->arr_str[i][j] == '.')
			{
				std::cout << i << j << " tut? \n";
				coord[0] = i;
				coord[1] = j;
				return;
			}
	}
}