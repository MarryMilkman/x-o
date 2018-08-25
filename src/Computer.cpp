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

	this->_logic(coord);
	return (coord);
}

int		Computer::_check_coord(int const *coord)
{					
	if (this->_map->arr_str[coord[0]][coord[1]] != '.')
		return (0);
	return (1);
}

// algo

void	Computer::_logic(int *coord)
{
	if (this->_check_win(coord))
		return ;
	if (this->_check_danger(coord))
		return ;
	if (this->_symbol == 'x' && this->_attack_mod(coord))
		return;
	else if (this->_defense_mod(coord))
		return ;
	this->_find_first_empty(coord);
}

int		Computer::_check_danger(int *coord)
{
	std::list<t_sector>::iterator	it;
	int								i;
	int								denger_count;
	char							c;
	int								change;

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
		if (denger_count >= 2 && change)
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

int		Computer::_attack_mod(int *coord)
{
	int								i;
	std::list<t_sector>				line;
	std::list<t_sector>::iterator	it;
	int								ret_result;

	ret_result = 0;
	i = -1;
	while (++i < 4)
	{
		if (i == 1 || i == 2)
			continue;
		line = this->_map->line[i];
		if (this->_check_line(line, this->_enemy_symbol))
			continue;
		it = line.begin();
		while (it != line.end())
		{
			if (!(it->coord[0] == 1 || it->coord[1] == 1)
			 && *(it->symbol) == '.' && !ret_result)
			{
				coord[0] = it->coord[0];
				coord[1] = it->coord[1];
				ret_result = 1;
			}
			it++;
		}
	}
	it = this->_map->line[6].begin();
	it++;
	if (!ret_result || *(it->symbol) == this->_enemy_symbol)
	{
		it++;
		if (*(it->symbol) == '.')
		{
			coord[0] = it->coord[0];
			coord[1] = it->coord[1];
			return (1);
		}
	}
	return (ret_result);
}

int		Computer::_defense_mod(int *coord)
{
	int								i;
	std::list<t_sector>				line;
	std::list<t_sector>::iterator	it;

	it = this->_map->line[6].begin();
	it++;
	if (*(it->symbol) == '.')
	{
		coord[0] = it->coord[0];
		coord[1] = it->coord[1];
		return (1);
	}
	// if (*(it->symbol) == 'o')
	// {

	// }
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
				coord[0] = i;
				coord[1] = j;
				return;
			}
	}
}

int		Computer::_check_line(std::list<t_sector> line, char c)
{
	std::list<t_sector>::iterator	it;

	it = line.begin();
	while (it != line.end())
	{
		if (*(it->symbol) == c)
			return (1);
		it++;
	}
	return (0);
}